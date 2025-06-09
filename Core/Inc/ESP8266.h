/*
 * ESP8266.h
 *
 *  Created on: Nov 17, 2021
 *      Author: vikto
 */

#ifndef INC_ESP8266_H_
#define INC_ESP8266_H_

#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WiFi_Credentials	"AT+CWJAP=\"WiFiSSID\",\"WiFiPASSWORD\"\r\n"
#define ESP_Post			"AT+CIPSTART=0,\"TCP\",\"192.168.1.51\",1883\r\n"

typedef enum {
	ESP_Disconnected,
	ESP_Connected
} ESP_State;

extern UART_HandleTypeDef huart2;
extern I2C_HandleTypeDef hi2c1;

extern uint32_t seconds;
extern uint8_t buffer[2000];
extern uint16_t buffer_index, timeout, messageHandlerFlag, no_activity_counter;
extern ESP_State esp_state;

void ESP_RESET();
void ESP_Server_Init();
void ESP_Clear_Buffer();
uint8_t string_compare(char array1[], char array2[], uint16_t length);
int string_contains(char bufferArray[], char searchedString[], uint16_t length);
void messageHandler();
void sendData();
void postMessageAsString(char message[]);
void send_MQTT_packet(uint8_t message[], uint16_t len);
void ESP_Open_Connection();
void ESP_Close_Connection();

#endif /* INC_ESP8266_H_ */
