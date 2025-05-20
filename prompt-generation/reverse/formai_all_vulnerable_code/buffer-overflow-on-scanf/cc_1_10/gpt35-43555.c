//FormAI DATASET v1.0 Category: Smart home automation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void bedroomLights(bool);
void kitchenLights(bool);
void bathroomLights(bool);
void livingRoomLights(bool);
void airConditioner(bool);

int main() {
    // Set initial state for each appliance
    bool bedroomLightsOn = false;
    bool kitchenLightsOn = false;
    bool bathroomLightsOn = false;
    bool livingRoomLightsOn = false; 
    bool airConditionerOn = false;
    
    printf("Welcome to Smart Home Automation System!\n\n");
    
    while (true) {
        // Display menu options
        printf("Select an option:\n");
        printf("1. Turn on/off bedroom lights\n");
        printf("2. Turn on/off kitchen lights\n");
        printf("3. Turn on/off bathroom lights\n");
        printf("4. Turn on/off living room lights\n");
        printf("5. Turn on/off air conditioner\n");
        printf("6. Exit\n\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (bedroomLightsOn) {
                    bedroomLights(false);
                    printf("Bedroom lights turned off.\n");
                    bedroomLightsOn = false;
                } else {
                    bedroomLights(true);
                    printf("Bedroom lights turned on.\n");
                    bedroomLightsOn = true;
                }
                break;
            case 2:
                if (kitchenLightsOn) {
                    kitchenLights(false);
                    printf("Kitchen lights turned off.\n");
                    kitchenLightsOn = false;
                } else {
                    kitchenLights(true);
                    printf("Kitchen lights turned on.\n");
                    kitchenLightsOn = true;
                }
                break;
            case 3:
                if (bathroomLightsOn) {
                    bathroomLights(false);
                    printf("Bathroom lights turned off.\n");
                    bathroomLightsOn = false;
                } else {
                    bathroomLights(true);
                    printf("Bathroom lights turned on.\n");
                    bathroomLightsOn = true;
                }
                break;
            case 4:
                if (livingRoomLightsOn) {
                    livingRoomLights(false);
                    printf("Living room lights turned off.\n");
                    livingRoomLightsOn = false;
                } else {
                    livingRoomLights(true);
                    printf("Living room lights turned on.\n");
                    livingRoomLightsOn = true;
                }
                break;
            case 5:
                if (airConditionerOn) {
                    airConditioner(false);
                    printf("Air conditioner turned off.\n");
                    airConditionerOn = false;
                } else {
                    airConditioner(true);
                    printf("Air conditioner turned on.\n");
                    airConditionerOn = true;
                }
                break;
            case 6:
                printf("Exiting Smart Home Automation System...\n");
                exit(0);
            default:
                printf("Invalid option, please select a valid option.\n");
                break;
        }
    } 
    return 0;
}

// Functions to control each appliance
void bedroomLights(bool state) {
    if (state) {
        printf("Turning bedroom lights on...\n");
    } else {
        printf("Turning bedroom lights off...\n");
    }
}

void kitchenLights(bool state) {
    if (state) {
        printf("Turning kitchen lights on...\n");
    } else {
        printf("Turning kitchen lights off...\n");
    }
}

void bathroomLights(bool state) {
    if (state) {
        printf("Turning bathroom lights on...\n");
    } else {
        printf("Turning bathroom lights off...\n");
    }
}

void livingRoomLights(bool state) {
    if (state) {
        printf("Turning living room lights on...\n");
    } else {
        printf("Turning living room lights off...\n");
    }
}

void airConditioner(bool state) {
    if (state) {
        printf("Turning air conditioner on...\n");
    } else {
        printf("Turning air conditioner off...\n");
    }
}