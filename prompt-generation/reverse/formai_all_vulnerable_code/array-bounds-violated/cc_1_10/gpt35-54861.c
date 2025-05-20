//FormAI DATASET v1.0 Category: Smart home light control ; Style: expert-level
#include <stdio.h>

// define constants for the rooms and lights
#define LIVING_ROOM 1
#define KITCHEN 2
#define BEDROOM 3
#define BATHROOM 4
#define LIGHT_1 1
#define LIGHT_2 2
#define LIGHT_3 3

// define the initial state of the lights
int livingRoomLights[3] = {0, 0, 0};
int kitchenLights[2] = {0, 0};
int bedroomLights[2] = {0, 0};
int bathroomLights[1] = {0};

// function to turn on a specific light in a room
void turnOnLight(int room, int light) {
    switch (room) {
        case LIVING_ROOM:
            livingRoomLights[light-1] = 1; // -1 as arrays are 0 indexed
            printf("Living room light %d turned on.\n", light);
            break;
        case KITCHEN:
            kitchenLights[light-1] = 1;
            printf("Kitchen light %d turned on.\n", light);
            break;
        case BEDROOM:
            bedroomLights[light-1] = 1;
            printf("Bedroom light %d turned on.\n", light);
            break;
        case BATHROOM:
            bathroomLights[light-1] = 1;
            printf("Bathroom light turned on.\n");
            break;
        default:
            printf("Invalid room entered.\n");
            break;
    }
}

// function to turn off a specific light in a room
void turnOffLight(int room, int light) {
    switch (room) {
        case LIVING_ROOM:
            livingRoomLights[light-1] = 0;
            printf("Living room light %d turned off.\n", light);
            break;
        case KITCHEN:
            kitchenLights[light-1] = 0;
            printf("Kitchen light %d turned off.\n", light);
            break;
        case BEDROOM:
            bedroomLights[light-1] = 0;
            printf("Bedroom light %d turned off.\n", light);
            break;
        case BATHROOM:
            bathroomLights[light-1] = 0;
            printf("Bathroom light turned off.\n");
            break;
        default:
            printf("Invalid room entered.\n");
            break;
    }
}

int main() {
    int roomChoice, lightChoice, actionChoice;
    
    printf("Welcome to the Smart Home Light Control System\n");
    
    // prompt user to select a room
    printf("Select a room:\n");
    printf("1. Living room\n");
    printf("2. Kitchen\n");
    printf("3. Bedroom\n");
    printf("4. Bathroom\n");
    scanf("%d", &roomChoice);
    
    // prompt user to select a light and an action
    switch (roomChoice) {
        case LIVING_ROOM:
            printf("Select a light in the living room:\n");
            printf("1. Light 1\n");
            printf("2. Light 2\n");
            printf("3. Light 3\n");
            scanf("%d", &lightChoice);
            printf("Select an action:\n");
            printf("1. Turn on\n");
            printf("2. Turn off\n");
            scanf("%d", &actionChoice);
            if (actionChoice == 1) {
                turnOnLight(LIVING_ROOM, lightChoice);
            } else if (actionChoice == 2) {
                turnOffLight(LIVING_ROOM, lightChoice);
            } else {
                printf("Invalid action entered.\n");
            }
            break;
        case KITCHEN:
            printf("Select a light in the kitchen:\n");
            printf("1. Light 1\n");
            printf("2. Light 2\n");
            scanf("%d", &lightChoice);
            printf("Select an action:\n");
            printf("1. Turn on\n");
            printf("2. Turn off\n");
            scanf("%d", &actionChoice);
            if (actionChoice == 1) {
                turnOnLight(KITCHEN, lightChoice);
            } else if (actionChoice == 2) {
                turnOffLight(KITCHEN, lightChoice);
            } else {
                printf("Invalid action entered.\n");
            }
            break;
        case BEDROOM:
            printf("Select a light in the bedroom:\n");
            printf("1. Light 1\n");
            printf("2. Light 2\n");
            scanf("%d", &lightChoice);
            printf("Select an action:\n");
            printf("1. Turn on\n");
            printf("2. Turn off\n");
            scanf("%d", &actionChoice);
            if (actionChoice == 1) {
                turnOnLight(BEDROOM, lightChoice);
            } else if (actionChoice == 2) {
                turnOffLight(BEDROOM, lightChoice);
            } else {
                printf("Invalid action entered.\n");
            }
            break;
        case BATHROOM:
            printf("Select an action:\n");
            printf("1. Turn on\n");
            printf("2. Turn off\n");
            scanf("%d", &actionChoice);
            if (actionChoice == 1) {
                turnOnLight(BATHROOM, LIGHT_1);
            } else if (actionChoice == 2) {
                turnOffLight(BATHROOM, LIGHT_1);
            } else {
                printf("Invalid action entered.\n");
            }
            break;
        default:
            printf("Invalid room entered.\n");
            break;
    }
    
    return 0;
}