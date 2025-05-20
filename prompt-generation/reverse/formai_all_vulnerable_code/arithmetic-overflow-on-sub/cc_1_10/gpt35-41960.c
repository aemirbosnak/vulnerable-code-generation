//FormAI DATASET v1.0 Category: Smart home light control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// Define macros for light control
#define LIGHT_ON 1
#define LIGHT_OFF 0

// Function declarations
void turnOnLights(int lights[]);
void turnOffLights(int lights[]);

int main() {
    int livingRoomLights[] = {LIGHT_OFF, LIGHT_OFF, LIGHT_OFF, LIGHT_OFF};
    int kitchenLights[] = {LIGHT_OFF, LIGHT_OFF, LIGHT_OFF};
    int bedroomLights[] = {LIGHT_OFF, LIGHT_OFF};
    
    int roomChoice;
    int lightChoice;
    int actionChoice;
    bool isRunning = true;
    
    printf("Welcome to Smart Home Light Control!\n");
    
    while (isRunning) {
        // Room selection
        printf("\nWhich room would you like to control?\n");
        printf("1. Living Room\n");
        printf("2. Kitchen\n");
        printf("3. Bedroom\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &roomChoice);
        
        switch (roomChoice) {
            case 1:
                printf("\nLIVING ROOM LIGHT CONTROL\n");
                printf("Which light would you like to control?\n");
                printf("1. Light 1\n");
                printf("2. Light 2\n");
                printf("3. Light 3\n");
                printf("4. Light 4\n");
                printf("Enter your choice (1-4): ");
                scanf("%d", &lightChoice);
                
                // Light action selection
                printf("\nWhat would you like to do with the light?\n");
                printf("1. Turn ON\n");
                printf("2. Turn OFF\n");
                printf("Enter your choice (1-2): ");
                scanf("%d", &actionChoice);
                
                if (actionChoice == 1) {
                    livingRoomLights[lightChoice - 1] = LIGHT_ON;
                } else if (actionChoice == 2) {
                    livingRoomLights[lightChoice - 1] = LIGHT_OFF;
                } else {
                    printf("\nInvalid choice!\n");
                }
                
                turnOnLights(livingRoomLights);
                turnOffLights(livingRoomLights);
                
                break;
                
            case 2:
                printf("\nKITCHEN LIGHT CONTROL\n");
                printf("Which light would you like to control?\n");
                printf("1. Light 1\n");
                printf("2. Light 2\n");
                printf("3. Light 3\n");
                printf("Enter your choice (1-3): ");
                scanf("%d", &lightChoice);
                
                // Light action selection
                printf("\nWhat would you like to do with the light?\n");
                printf("1. Turn ON\n");
                printf("2. Turn OFF\n");
                printf("Enter your choice (1-2): ");
                scanf("%d", &actionChoice);
                
                if (actionChoice == 1) {
                    kitchenLights[lightChoice - 1] = LIGHT_ON;
                } else if (actionChoice == 2) {
                    kitchenLights[lightChoice - 1] = LIGHT_OFF;
                } else {
                    printf("\nInvalid choice!\n");
                }
                
                turnOnLights(kitchenLights);
                turnOffLights(kitchenLights);
                
                break;
                
            case 3:
                printf("\nBEDROOM LIGHT CONTROL\n");
                printf("Which light would you like to control?\n");
                printf("1. Light 1\n");
                printf("2. Light 2\n");
                printf("Enter your choice (1-2): ");
                scanf("%d", &lightChoice);
                
                // Light action selection
                printf("\nWhat would you like to do with the light?\n");
                printf("1. Turn ON\n");
                printf("2. Turn OFF\n");
                printf("Enter your choice (1-2): ");
                scanf("%d", &actionChoice);
                
                if (actionChoice == 1) {
                    bedroomLights[lightChoice - 1] = LIGHT_ON;
                } else if (actionChoice == 2) {
                    bedroomLights[lightChoice - 1] = LIGHT_OFF;
                } else {
                    printf("\nInvalid choice!\n");
                }
                
                turnOnLights(bedroomLights);
                turnOffLights(bedroomLights);
                
                break;
                
            case 4:
                printf("\nThank you for using Smart Home Light Control!\n");
                isRunning = false;
                break;
                
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    
    return 0;
}

// Functions for turning lights on and off
void turnOnLights(int lights[]) {
    bool allLightsOn = true;
    
    for (int i = 0; i < sizeof(lights)/sizeof(lights[0]); i++) {
        if (lights[i] == LIGHT_OFF) {
            allLightsOn = false;
            break;
        }
    }
    
    if (allLightsOn) {
        printf("\nAll lights are already turned ON!\n");
    } else {
        printf("\nTurning lights ON...");
        usleep(2000000);
        for (int i = 0; i < sizeof(lights)/sizeof(lights[0]); i++) {
            lights[i] = LIGHT_ON;
            printf("\nLight %d is ON.", i+1);
        }
    }
}

void turnOffLights(int lights[]) {
    bool allLightsOff = true;
    
    for (int i = 0; i < sizeof(lights)/sizeof(lights[0]); i++) {
        if (lights[i] == LIGHT_ON) {
            allLightsOff = false;
            break;
        }
    }
    
    if (allLightsOff) {
        printf("\nAll lights are already turned OFF!\n");
    } else {
        printf("\nTurning lights OFF...");
        usleep(2000000);
        for (int i = 0; i < sizeof(lights)/sizeof(lights[0]); i++) {
            lights[i] = LIGHT_OFF;
            printf("\nLight %d is OFF.", i+1);
        }
    }
}