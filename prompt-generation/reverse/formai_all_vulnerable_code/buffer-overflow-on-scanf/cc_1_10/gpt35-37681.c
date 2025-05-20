//FormAI DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define global variables */
bool livingRoomLightOn = false;
bool kitchenLightOn = false;
bool bedroomLightOn = false;

/* Function to turn on/off living room light */
void setLivingRoomLight(bool on) {
    livingRoomLightOn = on;
    printf("Living room light turned %s\n", on ? "on" : "off");
}

/* Function to turn on/off kitchen light */
void setKitchenLight(bool on) {
    kitchenLightOn = on;
    printf("Kitchen light turned %s\n", on ? "on" : "off");
}

/* Function to turn on/off bedroom light */
void setBedroomLight(bool on) {
    bedroomLightOn = on;
    printf("Bedroom light turned %s\n", on ? "on" : "off");
}

/* Main function */
int main() {
    char input;

    printf("Welcome to Smart Home Light Control\n");

    while (true) {
        printf("\nEnter 'L' for living room light, 'K' for kitchen light, 'B' for bedroom light: ");
        scanf(" %c", &input);

        switch (input) {
            case 'L':
                setLivingRoomLight(!livingRoomLightOn);
                break;
            case 'K':
                setKitchenLight(!kitchenLightOn);
                break;
            case 'B':
                setBedroomLight(!bedroomLightOn);
                break;
            default:
                printf("Invalid input. Try again.\n");
                break;
        }
    }

    return 0;
}