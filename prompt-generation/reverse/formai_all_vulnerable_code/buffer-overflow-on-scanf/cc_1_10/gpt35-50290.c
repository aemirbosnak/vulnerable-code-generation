//FormAI DATASET v1.0 Category: Smart home automation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIVING_ROOM_LIGHT 1
#define KITCHEN_LIGHT 2
#define BEDROOM_LIGHT 3
#define BATHROOM_LIGHT 4

bool livingRoomLightState = false;
bool kitchenLightState = false;
bool bedroomLightState = false;
bool bathroomLightState = false;

void toggleLight(int lightNumber) {
    switch (lightNumber) {
        case LIVING_ROOM_LIGHT:
            livingRoomLightState != livingRoomLightState;
            printf("Living room light is now %s\n", livingRoomLightState ? "ON" : "OFF");
            break;
        case KITCHEN_LIGHT:
            kitchenLightState != kitchenLightState;
            printf("Kitchen light is now %s\n", kitchenLightState ? "ON" : "OFF");
            break;
        case BEDROOM_LIGHT:
            bedroomLightState != bedroomLightState;
            printf("Bedroom light is now %s\n", bedroomLightState ? "ON" : "OFF");
            break;
        case BATHROOM_LIGHT:
            bathroomLightState != bathroomLightState;
            printf("Bathroom light is now %s\n", bathroomLightState ? "ON" : "OFF");
            break;
        default:
            printf("Invalid light number\n");
            break;
    }
}

int main() {
    printf("Welcome to Smart Home Automation\n\n");
    
    int selectedOption = -1;
    while (selectedOption != 0) {
        printf("What would you like to do?\n");
        printf("1. Toggle living room light\n");
        printf("2. Toggle kitchen light\n");
        printf("3. Toggle bedroom light\n");
        printf("4. Toggle bathroom light\n");
        printf("0. Exit\n");
        printf("Enter option number: ");
        scanf("%d", &selectedOption);
        printf("\n");
        
        switch (selectedOption) {
            case 1:
                toggleLight(LIVING_ROOM_LIGHT);
                break;
            case 2:
                toggleLight(KITCHEN_LIGHT);
                break;
            case 3:
                toggleLight(BEDROOM_LIGHT);
                break;
            case 4:
                toggleLight(BATHROOM_LIGHT);
                break;
            case 0:
                printf("Thank you for using Smart Home Automation!\n");
                break;
            default:
                printf("Invalid option. Please enter a valid option number.\n\n");
                break;
        }
    }
    
    return 0;
}