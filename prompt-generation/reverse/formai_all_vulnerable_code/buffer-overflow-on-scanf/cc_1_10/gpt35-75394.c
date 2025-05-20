//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

/* Global variables */
int lightStatus = 0;
int temperature = 25;
int fanSpeed = 0;
int windowStatus = 0;

/* Function prototypes */
void turnOnLight();
void turnOffLight();
void increaseTemp();
void decreaseTemp();
void increaseFanSpeed();
void decreaseFanSpeed();
void openWindow();
void closeWindow();

int main() {
    /* Main menu */
    int choice;
    printf("Welcome to Smart Home Automation!\n\n");
    do {
        printf("Select an option:\n");
        printf("1. Turn on/off the light\n");
        printf("2. Increase/decrease temperature\n");
        printf("3. Increase/decrease fan speed\n");
        printf("4. Open/close window\n");
        printf("5. Show current status\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if (lightStatus == 0) {
                    turnOnLight();
                } else {
                    turnOffLight();
                }
                break;
            case 2:
                printf("Select an option:\n");
                printf("1. Increase temperature\n");
                printf("2. Decrease temperature\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    increaseTemp();
                } else {
                    decreaseTemp();
                }
                break;
            case 3:
                printf("Select an option:\n");
                printf("1. Increase fan speed\n");
                printf("2. Decrease fan speed\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    increaseFanSpeed();
                } else {
                    decreaseFanSpeed();
                }
                break;
            case 4:
                if (windowStatus == 0) {
                    openWindow();
                } else {
                    closeWindow();
                }
                break;
            case 5:
                printf("Current status:\n");
                printf("Light: %d\n", lightStatus);
                printf("Temperature: %d Celsius\n", temperature);
                printf("Fan speed: %d\n", fanSpeed);
                printf("Window: %d\n", windowStatus);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void turnOnLight() {
    lightStatus = 1;
    printf("The light is on.\n");
}

void turnOffLight() {
    lightStatus = 0;
    printf("The light is off.\n");
}

void increaseTemp() {
    temperature++;
    printf("The temperature is now %d Celsius.\n", temperature);
}

void decreaseTemp() {
    temperature--;
    printf("The temperature is now %d Celsius.\n", temperature);
}

void increaseFanSpeed() {
    fanSpeed++;
    printf("The fan speed is now %d.\n", fanSpeed);
}

void decreaseFanSpeed() {
    fanSpeed--;
    printf("The fan speed is now %d.\n", fanSpeed);
}

void openWindow() {
    windowStatus = 1;
    printf("The window is open.\n");
}

void closeWindow() {
    windowStatus = 0;
    printf("The window is closed.\n");
}