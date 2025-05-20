//FormAI DATASET v1.0 Category: Smart home automation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isLightOn = false;
bool isAirconOn = false;

void turnOnLight() {
    printf("Turning on the light...\n");
    isLightOn = true;
}

void turnOffLight() {
    printf("Turning off the light...\n");
    isLightOn = false;
}

void turnOnAircon() {
    printf("Turning on the air conditioner...\n");
    isAirconOn = true;
}

void turnOffAircon() {
    printf("Turning off the air conditioner...\n");
    isAirconOn = false;
}

int main() {
    int choice;
    printf("Welcome to Smart Home Automation\n");

    while (true) {
        printf("\nPlease choose an option:\n");
        printf("1. Turn light on\n");
        printf("2. Turn light off\n");
        printf("3. Turn air conditioner on\n");
        printf("4. Turn air conditioner off\n");
        printf("5. Quit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isLightOn) {
                    turnOnLight();
                }
                else {
                    printf("Light is already on.\n");
                }
                break;
            case 2:
                if (isLightOn) {
                    turnOffLight();
                }
                else {
                    printf("Light is already off.\n");
                }
                break;
            case 3:
                if (!isAirconOn) {
                    turnOnAircon();
                }
                else {
                    printf("Air conditioner is already on.\n");
                }
                break;
            case 4:
                if (isAirconOn) {
                    turnOffAircon();
                }
                else {
                    printf("Air conditioner is already off.\n");
                }
                break;
            case 5:
                printf("Exiting Smart Home Automation.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}