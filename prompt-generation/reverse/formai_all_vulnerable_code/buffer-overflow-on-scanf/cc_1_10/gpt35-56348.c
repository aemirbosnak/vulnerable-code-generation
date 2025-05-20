//FormAI DATASET v1.0 Category: Smart home automation ; Style: excited
#include <stdio.h>
#include <string.h>

#define LIGHT_PIN 2
#define FAN_PIN 3
#define AIRCONDITIONER_PIN 4

void turnOnLight() {
    printf("\n Turning on the light.");
    // Code to turn ON the light bulb
}

void turnOffLight() {
    printf("\n Turning off the light.");
    // Code to turn OFF the light bulb
}

void turnOnFan() {
    printf("\n Turning on the fan.");
    // Code to turn ON the fan
}

void turnOffFan() {
    printf("\n Turning off the fan.");
    // Code to turn OFF the fan
}

void turnOnAirConditioner() {
    printf("\n Turning on the air conditioner.");
    // Code to turn ON the air conditioner
}

void turnOffAirConditioner() {
    printf("\n Turning off the air conditioner.");
    // Code to turn OFF the air conditioner
}

int main() {
    int command;
    char input[50];

    printf("\n Welcome to Smart Home Automation System.");
    printf("\n Light is connected to Pin %d", LIGHT_PIN);
    printf("\n Fan is connected to Pin %d", FAN_PIN);
    printf("\n Airconditioner is connected to Pin %d", AIRCONDITIONER_PIN);

    while (1) {
        printf("\n Enter the command: ");
        scanf("%s", input);
        if (strcmp(input, "turn_on_light") == 0) {
            turnOnLight();
        } else if (strcmp(input, "turn_off_light") == 0) {
            turnOffLight();
        } else if (strcmp(input, "turn_on_fan") == 0) {
            turnOnFan();
        } else if (strcmp(input, "turn_off_fan") == 0) {
            turnOffFan();
        } else if (strcmp(input, "turn_on_air_conditioner") == 0) {
            turnOnAirConditioner();
        } else if (strcmp(input, "turn_off_air_conditioner") == 0) {
            turnOffAirConditioner();
        }
    }

    return 0;
}