//FormAI DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdbool.h>

/* Function prototype */
void turnLightOnOff(bool isLightOn);

int main() {
    bool isLightOn = false; // Initialize light status to off
    char inputChar;
    printf("Welcome to Smart Home Light Control System\n\n");
    printf("Press 'on' to turn on the light\n");
    printf("Press 'off' to turn off the light\n");
    printf("Press 'exit' to close the program\n\n");

    while (true) {
        scanf(" %s", &inputChar);
        if (inputChar == 'on') {
            if (!isLightOn) { // Check if light is already on
                turnLightOnOff(true);
                isLightOn = true;
                printf("Light is on\n");
            } else {
                printf("Light is already on\n");
            }
        } else if (inputChar == 'off') {
            if (isLightOn) { // Check if light is already off
                turnLightOnOff(false);
                isLightOn = false;
                printf("Light is off\n");
            } else {
                printf("Light is already off\n");
            }
        } else if (inputChar == 'exit') {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid input, please try again.\n");
        }
    }

    return 0;
}

/* Function definition */
void turnLightOnOff(bool isLightOn) {
    if (isLightOn) {
        // Code to turn on the light
        printf("Turning on light...\n");
    } else {
        // Code to turn off the light
        printf("Turning off light...\n");
    }
}