//FormAI DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10
#define MAX_NAME_LENGTH 20

typedef struct Light {
    char name[MAX_NAME_LENGTH];
    bool isOn;
} Light;

void printMenu() {
    printf("\nMENU:\n");
    printf("1. Turn on a light\n");
    printf("2. Turn off a light\n");
    printf("3. Print status of all lights\n");
    printf("4. Quit\n");
}

void turnOnLight(Light *light) {
    light->isOn = true;
    printf("%s is now on.\n", light->name);
}

void turnOffLight(Light *light) {
    light->isOn = false;
    printf("%s is now off.\n", light->name);
}

void printLightStatus(Light *lights, int numLights) {
    printf("\nLIGHT STATUS:\n");
    for (int i = 0; i < numLights; i++) {
        printf("%s: %s\n", lights[i].name, (lights[i].isOn ? "on" : "off"));
    }
}

int main() {
    Light lights[MAX_LIGHTS];
    int numLights = 0;

    while (true) {
        printMenu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Turn on a light
                if (numLights == MAX_LIGHTS) {
                    printf("\nMax number of lights reached.\n");
                } else {
                    Light newLight;
                    printf("\nEnter name of light: ");
                    scanf("%s", newLight.name);
                    newLight.isOn = false;
                    turnOnLight(&newLight);
                    lights[numLights] = newLight;
                    numLights++;
                }
                break;

            case 2: // Turn off a light
                if (numLights == 0) {
                    printf("\nThere are no lights to turn off.\n");
                } else {
                    printf("\nEnter name of light to turn off: ");
                    char name[MAX_NAME_LENGTH];
                    scanf("%s", name);

                    bool isLightFound = false;
                    for (int i = 0; i < numLights; i++) {
                        if (strcmp(lights[i].name, name) == 0) {
                            turnOffLight(&lights[i]);
                            isLightFound = true;
                            break;
                        }
                    }

                    if (!isLightFound) {
                        printf("\n%s not found.\n", name);
                    }
                }
                break;

            case 3: // Print status of all lights
                if (numLights == 0) {
                    printf("\nThere are no lights to show status of.\n");
                } else {
                    printLightStatus(lights, numLights);
                }
                break;

            case 4: // Quit
                printf("\nGoodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}