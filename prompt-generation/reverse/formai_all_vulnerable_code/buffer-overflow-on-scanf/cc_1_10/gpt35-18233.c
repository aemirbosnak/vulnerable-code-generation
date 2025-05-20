//FormAI DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// define the maximum number of lights in the home
#define MAX_LIGHTS 20

// define a light structure
typedef struct {
    int lightID;
    bool isOn;
} Light;

// function prototypes
void initializeLights(Light* lights, int numLights);
void printLights(Light* lights, int numLights);
int getLightByID(Light* lights, int numLights, int lightID);
void turnOnLight(Light* lights, int lightIndex);
void turnOffLight(Light* lights, int lightIndex);

int main() {

    // declare an array of Light structures and initialize it
    Light lights[MAX_LIGHTS];
    initializeLights(lights, 3); // change 3 to the number of lights in your home

    // loop until the user chooses to exit
    int choice = -1;
    while (choice != 0) {
        printf("\n---- Light Control Menu ----\n");
        printf("1. List all lights and their status.\n");
        printf("2. Turn on a light.\n");
        printf("3. Turn off a light.\n");
        printf("0. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printLights(lights, 3); // change 3 to the number of lights in your home
                break;
            case 2:
                printf("\nEnter the ID of the light you want to turn on: ");
                int turnOnID;
                scanf("%d", &turnOnID);
                int turnOnIndex = getLightByID(lights, 3, turnOnID); // change 3 to the number of lights in your home
                if (turnOnIndex != -1) {
                    turnOnLight(lights, turnOnIndex);
                    printf("Light %d turned on.\n", turnOnID);
                } else {
                    printf("Light %d not found in the home.\n", turnOnID);
                }
                break;
            case 3:
                printf("\nEnter the ID of the light you want to turn off: ");
                int turnOffID;
                scanf("%d", &turnOffID);
                int turnOffIndex = getLightByID(lights, 3, turnOffID); // change 3 to the number of lights in your home
                if (turnOffIndex != -1) {
                    turnOffLight(lights, turnOffIndex);
                    printf("Light %d turned off.\n", turnOffID);
                } else {
                    printf("Light %d not found in the home.\n", turnOffID);
                }
                break;
            case 0:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid input. Please try again.\n");
        }
    }

    return 0;
}

// function to initialize the lights array
void initializeLights(Light* lights, int numLights) {
    for (int i = 0; i < numLights; i++) {
        lights[i].lightID = i + 1;
        lights[i].isOn = false;
    }
}

// function to print the current status of all lights
void printLights(Light* lights, int numLights) {
    printf("\n---- Current Light Status ----\n");
    for (int i = 0; i < numLights; i++) {
        printf("Light %d is %s.\n", lights[i].lightID, lights[i].isOn ? "on" : "off");
    }
}

// function to get the index of a light based on its ID
int getLightByID(Light* lights, int numLights, int lightID) {
    for (int i = 0; i < numLights; i++) {
        if (lights[i].lightID == lightID) {
            return i;
        }
    }
    return -1;
}

// function to turn on a light
void turnOnLight(Light* lights, int lightIndex) {
    lights[lightIndex].isOn = true;
}

// function to turn off a light
void turnOffLight(Light* lights, int lightIndex) {
    lights[lightIndex].isOn = false;
}