//FormAI DATASET v1.0 Category: Smart home light control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIGHT_BEDROOM 1
#define LIGHT_LIVING_ROOM 2
#define LIGHT_KITCHEN 3

bool isBedroomLightOn = false;
bool isLivingRoomLightOn = false;
bool isKitchenLightOn = false;

void toggleLight(int lightCode) {
    switch (lightCode) {
        case LIGHT_BEDROOM:
            isBedroomLightOn = !isBedroomLightOn;
            break;
        case LIGHT_LIVING_ROOM:
            isLivingRoomLightOn = !isLivingRoomLightOn;
            break;
        case LIGHT_KITCHEN:
            isKitchenLightOn = !isKitchenLightOn;
            break;
        default:
            printf("Invalid Light Code\n");
    }
}

void printState() {
    printf("Bedroom Light: %s\n", isBedroomLightOn ? "ON" : "OFF");
    printf("Living Room Light: %s\n", isLivingRoomLightOn ? "ON" : "OFF");
    printf("Kitchen Light: %s\n", isKitchenLightOn ? "ON" : "OFF");
}

int main() {
    int choice;
    printf("Welcome to Smart Home Light Control System\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. Toggle Bedroom Light\n");
        printf("2. Toggle Living Room Light\n");
        printf("3. Toggle Kitchen Light\n");
        printf("4. Show Current State\n");
        printf("5. Exit\n");
        
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                toggleLight(LIGHT_BEDROOM);
                break;
            case 2:
                toggleLight(LIGHT_LIVING_ROOM);
                break;
            case 3:
                toggleLight(LIGHT_KITCHEN);
                break;
            case 4:
                printState();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 5);

    return 0;
}