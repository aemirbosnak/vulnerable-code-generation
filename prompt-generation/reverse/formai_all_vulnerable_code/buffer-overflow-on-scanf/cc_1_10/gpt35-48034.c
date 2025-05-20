//FormAI DATASET v1.0 Category: Smart home automation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIGHT_PIN 7
#define THERMOSTAT_PIN 13
#define DOOR_PIN 2

bool isLightOn = false;
int temperature = 72;
bool isDoorLocked = true;

void turnOnLight();
void turnOffLight();
void adjustTemperature(int newTemperature);
void lockDoor();
void unlockDoor();

int main() {
    printf("Welcome to the Smart Home Automation System!\n");

    while(true) {
        printf("\nWhat would you like to do?\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Adjust the temperature\n");
        printf("4. Lock the door\n");
        printf("5. Unlock the door\n");
        printf("6. Exit\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                turnOnLight();
                break;
            case 2:
                turnOffLight();
                break;
            case 3:
                printf("Enter the desired temperature: ");
                scanf("%d", &temperature);
                adjustTemperature(temperature);
                break;
            case 4:
                lockDoor();
                break;
            case 5:
                unlockDoor();
                break;
            case 6:
                printf("Exiting the Smart Home Automation System...\n");
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}

void turnOnLight() {
    if(!isLightOn) {
        // send signal to turn on the light via LIGHT_PIN
        printf("Turning on the light\n");
        isLightOn = true;
    }
    else {
        printf("The light is already on\n");
    }
}

void turnOffLight() {
    if(isLightOn) {
        // send signal to turn off the light via LIGHT_PIN
        printf("Turning off the light\n");
        isLightOn = false;
    }
    else {
        printf("The light is already off\n");
    }
}

void adjustTemperature(int newTemperature) {
    if(newTemperature != temperature) {
        // send signal to adjust the temperature via THERMOSTAT_PIN
        printf("Adjusting the temperature to %d degrees\n", newTemperature);
        temperature = newTemperature;
    }
    else {
        printf("The temperature is already set to %d degrees\n", temperature);
    }
}

void lockDoor() {
    if(!isDoorLocked) {
        // send signal to lock the door via DOOR_PIN
        printf("Locking the door\n");
        isDoorLocked = true;
    }
    else {
        printf("The door is already locked\n");
    }
}

void unlockDoor() {
    if(isDoorLocked) {
        // send signal to unlock the door via DOOR_PIN
        printf("Unlocking the door\n");
        isDoorLocked = false;
    }
    else {
        printf("The door is already unlocked\n");
    }
}