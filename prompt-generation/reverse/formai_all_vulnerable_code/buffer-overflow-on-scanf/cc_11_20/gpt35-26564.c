//FormAI DATASET v1.0 Category: Smart home light control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define LIGHTS_ON 1
#define LIGHTS_OFF 0

int main() {
    int livingRoomLights = LIGHTS_OFF;
    int kitchenLights = LIGHTS_OFF;
    int bedroomLights = LIGHTS_OFF;

    int selectedRoom, selectedAction;

    while (1) {
        printf("\nWelcome to Smart Home Light Control System!\n");
        printf("Please select a room to control the lights:\n");
        printf("1. Living room\n");
        printf("2. Kitchen\n");
        printf("3. Bedroom\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &selectedRoom);

        if (selectedRoom == 4) {
            printf("\nGoodbye!\n");
            break;
        }

        printf("Please select an action:\n");
        printf("1. Turn lights on\n");
        printf("2. Turn lights off\n");
        printf("Enter your choice: ");
        scanf("%d", &selectedAction);

        switch (selectedRoom) {
            case 1: 
                livingRoomLights = selectedAction == 1 ? LIGHTS_ON : LIGHTS_OFF;
                printf("Living room lights are now %s.\n", livingRoomLights == LIGHTS_ON ? "on" : "off");
                break;
            case 2:
                kitchenLights = selectedAction == 1 ? LIGHTS_ON : LIGHTS_OFF;
                printf("Kitchen lights are now %s.\n", kitchenLights == LIGHTS_ON ? "on" : "off");
                break;
            case 3:
                bedroomLights = selectedAction == 1 ? LIGHTS_ON : LIGHTS_OFF;
                printf("Bedroom lights are now %s.\n", bedroomLights == LIGHTS_ON ? "on" : "off");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}