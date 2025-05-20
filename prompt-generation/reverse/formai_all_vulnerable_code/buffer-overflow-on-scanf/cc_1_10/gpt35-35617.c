//FormAI DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LIGHTS 10 //maximum number of lights in the house
#define MAX_NAME_LENGTH 20 //maximum length of the name of the lights
#define MAX_SWITCHES 3 //maximum number of switches in the house

/* Struct to represent a light */
typedef struct {
    char name[MAX_NAME_LENGTH];
    bool isOn;
} Light;

/* Initialize an array of lights */
void initLights(Light lights[MAX_LIGHTS], int numLights) {
    for (int i = 0; i < numLights; i++) {
        printf("Enter name of light %d: ", i+1);
        scanf("%s", lights[i].name);
        lights[i].isOn = false;
    }
}

/* Turn on a specific light */
void turnOn(Light lights[MAX_LIGHTS], int numLights, char lightName[MAX_NAME_LENGTH]) {
    bool found = false;
    for (int i = 0; i < numLights; i++) {
        if (strcmp(lights[i].name, lightName) == 0) {
            found = true;
            if (lights[i].isOn) {
                printf("The light is already on!\n");
            } else {
                lights[i].isOn = true;
                printf("Turning on %s!\n", lightName);
            }
            break;
        }
    }
    if (!found) {
        printf("Light not found!\n");
    }
}

/* Turn off a specific light */
void turnOff(Light lights[MAX_LIGHTS], int numLights, char lightName[MAX_NAME_LENGTH]) {
    bool found = false;
    for (int i = 0; i < numLights; i++) {
        if (strcmp(lights[i].name, lightName) == 0) {
            found = true;
            if (!lights[i].isOn) {
                printf("The light is already off!\n");
            } else {
                lights[i].isOn = false;
                printf("Turning off %s!\n", lightName);
            }
            break;
        }
    }
    if (!found) {
        printf("Light not found!\n");
    }
}

/* Main function */
int main() {
    Light lights[MAX_LIGHTS];
    int numLights, numSwitches, choice;
    char switchName[MAX_NAME_LENGTH], lightName[MAX_NAME_LENGTH];
    
    printf("Welcome to Smart Home Light Control System!\n");
    printf("How many lights are there in your house? ");
    scanf("%d", &numLights);
    
    initLights(lights, numLights);
    
    printf("How many switches do you want to install? ");
    scanf("%d", &numSwitches);

    /* Initialize an array of switch names */
    char switchNames[MAX_SWITCHES][MAX_NAME_LENGTH] = {"Living Room", "Bed Room", "Kitchen"};
    
    while (true) {
        printf("Choose from the following options:\n");
        printf("1. Turn on a light\n");
        printf("2. Turn off a light\n");
        printf("3. Quit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Which light do you want to turn on? ");
                scanf("%s", lightName);
                turnOn(lights, numLights, lightName);
                break;
            case 2:
                printf("Which light do you want to turn off? ");
                scanf("%s", lightName);
                turnOff(lights, numLights, lightName);
                break;
            case 3:
                printf("Thank you for using Smart Home Light Control System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}