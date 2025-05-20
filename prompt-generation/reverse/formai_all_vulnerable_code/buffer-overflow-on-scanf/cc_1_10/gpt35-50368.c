//FormAI DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIGHTS 10  // maximum number of lights in the house

/* Function to determine whether a given light is on or off */
int isLightOn(int lightIndex, int activeLights[], int numActiveLights) {
    for (int i = 0; i < numActiveLights; i++) {
        if (activeLights[i] == lightIndex)
            return 1; // light is on
    }
    return 0; // light is off
}

int main() {
    int numLights;      // number of lights in the house
    int activeLights[MAX_LIGHTS];   // array to store which lights are currently on
    int numActiveLights = 0;    // number of lights that are currently on

    printf("Enter the number of lights in your house: ");
    scanf("%d", &numLights);

    int lightStatus[numLights]; // array to store the on/off status of each light
    for (int i = 0; i < numLights; i++) {
        lightStatus[i] = 0; // all lights are initially off
    }

    printf("\nWelcome to Smart Light Control!\n\n");

    while (1) { // infinite loop until user chooses to exit
        printf("Current Light Status:\n");
        for (int i = 0; i < numLights; i++) {
            printf("Light %d: %s\n", i+1, (isLightOn(i, activeLights, numActiveLights)) ? "On" : "Off");
        }

        printf("\nEnter the number of the light you wish to control (1-%d) or 0 to exit: ", numLights);
        int lightIndex;
        scanf("%d", &lightIndex);

        if (lightIndex == 0) { // user has chosen to exit the program
            printf("\nGoodbye!\n");
            break;
        }
        else if (lightIndex < 1 || lightIndex > numLights) { // invalid input
            printf("\nInvalid light number. Please try again.\n");
            continue;
        }

        int lightStatusIndex = lightIndex - 1; // index of the light in the lightStatus array

        if (isLightOn(lightStatusIndex, activeLights, numActiveLights)) { // light is currently on
            printf("\nLight %d is currently on. Do you wish to turn it off? (Y/N): ", lightIndex);
            char choice;
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y') {
                lightStatus[lightStatusIndex] = 0; // turn the light off
                for (int i = 0; i < numActiveLights; i++) {
                    if (activeLights[i] == lightStatusIndex) { // remove the light from the activeLights array
                        for (int j = i; j < numActiveLights - 1; j++) {
                            activeLights[j] = activeLights[j + 1];
                        }
                        numActiveLights--;
                    }
                }
            }
            else { // user has chosen not to turn the light off
                printf("\nLight %d remains on.\n", lightIndex);
            }
        }
        else { // light is currently off
            printf("\nLight %d is currently off. Do you wish to turn it on? (Y/N): ", lightIndex);
            char choice;
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y') {
                lightStatus[lightStatusIndex] = 1; // turn the light on
                activeLights[numActiveLights] = lightStatusIndex; // add the light to the activeLights array
                numActiveLights++;
            }
            else { // user has chosen not to turn the light on
                printf("\nLight %d remains off.\n", lightIndex);
            }
        }
    }

    return 0;
}