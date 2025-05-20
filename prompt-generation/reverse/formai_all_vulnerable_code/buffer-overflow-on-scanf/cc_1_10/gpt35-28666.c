//FormAI DATASET v1.0 Category: Smart home light control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*Defines the maximum length for input strings*/
#define MAX_LEN 50

/*Defines the maximum number of lights in the system and their corresponding names*/
#define MAX_LIGHTS 10
char lightNames[MAX_LIGHTS][MAX_LEN] = {"Kitchen", "Living Room", "Bedroom", "Bathroom", "Garage", "Hallway", "Dining Room", "Office", "Patio", "Guestroom"};

/*Defines the maximum number of light modes*/
#define MAX_MODES 3
char lightModes[MAX_MODES][MAX_LEN] = {"on", "off", "dim"};

/*Function to print the available lights and their corresponding index*/
void printLights() {
    printf("The available lights in the system are: \n");
    for(int i=0; i<MAX_LIGHTS; i++) {
        printf("%d - %s\n", i, lightNames[i]);
    }
}

/*Function to print the available light modes and their corresponding index*/
void printModes() {
    printf("The available light modes are: \n");
    for(int i=0; i<MAX_MODES; i++) {
        printf("%d - %s\n", i, lightModes[i]);
    }
}

/*Function to set the mode of a specific light*/
void setLightMode(bool lights[MAX_LIGHTS], int index, int mode) {
    switch(mode) {
        case 0: //on
            lights[index] = true;
            break;
        case 1: //off
            lights[index] = false;
            break;
        case 2: //dim
            lights[index] = true;
            printf("Enter the brightness level (0-100): ");
            int brightness;
            scanf("%d", &brightness);
            printf("Light %s set to %d%% brightness\n", lightNames[index], brightness);
            break;
        default:
            printf("Invalid mode selection\n");
            break;
    }
}

int main() {
    /*Initializes all lights as off*/
    bool lights[MAX_LIGHTS] = {false};

    printf("Welcome to the Smart Home Light Control System\n");

    /*Infinite loop to prompt user for input until quit command is given*/
    while(true) {
        printf("Please enter a command (or type 'quit' to exit): ");
        char input[MAX_LEN];
        scanf("%s", input);

        if(strcmp(input, "list") == 0) { //list command
            printLights();
        }
        else if(strcmp(input, "modes") == 0) { //modes command
            printModes();
        }
        else if(strcmp(input, "set") == 0) { //set command
            printf("Please enter the light index: ");
            int lightIndex;
            scanf("%d", &lightIndex);
            if(lightIndex < 0 || lightIndex >= MAX_LIGHTS) {
                printf("Invalid light index\n");
                continue;
            }
            printf("Please enter the mode index: ");
            int modeIndex;
            scanf("%d", &modeIndex);
            if(modeIndex < 0 || modeIndex >= MAX_MODES) {
                printf("Invalid mode index\n");
                continue;
            }
            setLightMode(lights, lightIndex, modeIndex);
            printf("Light %s set to '%s' mode\n", lightNames[lightIndex], lightModes[modeIndex]);
        }
        else if(strcmp(input, "status") == 0) { //status command
            printf("Current light status:\n");
            for(int i=0; i<MAX_LIGHTS; i++) {
                printf("%s - %s\n", lightNames[i], lights[i] ? "on" : "off");
            }
        }
        else if(strcmp(input, "quit") == 0) { //quit command
            break;
        }
        else { //invalid command
            printf("Invalid command\n");
        }
    }

    printf("Smart Home Light Control System exiting...\n");

    return 0;
}