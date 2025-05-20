//FormAI DATASET v1.0 Category: Smart home light control ; Style: visionary
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define light control variables
bool bedroomLightOn = false;
bool kitchenLightOn = false;
bool livingRoomLightOn = false;
bool bathroomLightOn = false;

// Function to turn lights on and off
void turnLightOnOff(bool *lightStatus) {
    if (*lightStatus) {
        *lightStatus = false;
        printf("Light turned off.\n");
    } else {
        *lightStatus = true;
        printf("Light turned on.\n");
    }
}

int main() {
    char userChoice;
    printf("Welcome to the Smart Home Light Control System!\n");

    while (true) {
        printf("\nPlease select which room you would like to manage:\n");
        printf("1. Bedroom\n2. Kitchen\n3. Living Room\n4. Bathroom\n5. Exit\n");
        scanf(" %c", &userChoice);

        switch (userChoice) {
            case '1':
                printf("You are in the bedroom.\n");
                turnLightOnOff(&bedroomLightOn);
                break;
            case '2':
                printf("You are in the kitchen.\n");
                turnLightOnOff(&kitchenLightOn);
                break;
            case '3':
                printf("You are in the living room.\n");
                turnLightOnOff(&livingRoomLightOn);
                break;
            case '4':
                printf("You are in the bathroom.\n");
                turnLightOnOff(&bathroomLightOn);
                break;
            case '5':
                printf("Thank you for using the Smart Home Light Control System!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}