//FormAI DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    bool isOn;
} Light;

void printMenu() {
    printf("\n");
    printf("1. Turn on lights\n");
    printf("2. Turn off lights\n");
    printf("3. Toggle a specific light\n");
    printf("4. Display all lights\n");
    printf("5. Exit\n");
    printf("\n");
}

int getOption() {
    int option;
    printf("Enter option: ");
    scanf("%d", &option);
    return option;
}

void turnOnAllLights(Light lights[], int numLights) {
    for (int i = 0; i < numLights; i++) {
        lights[i].isOn = true;
    }
    printf("All lights turned on.\n");
}

void turnOffAllLights(Light lights[], int numLights) {
    for (int i = 0; i < numLights; i++) {
        lights[i].isOn = false;
    }
    printf("All lights turned off.\n");
}

void toggleLight(Light *light) {
    light->isOn = !light->isOn;
    printf("Light %s toggled. It is now %s.\n", light->name, light->isOn ? "on" : "off");
}

void displayAllLights(Light lights[], int numLights) {
    printf("\n");
    for (int i = 0; i < numLights; i++) {
        printf("Light %s is %s.\n", lights[i].name, lights[i].isOn ? "on" : "off");
    }
}

int main() {

    Light lights[MAX_LIGHTS];
    int numLights = 0;

    while (true) {

        printMenu();

        int option = getOption();

        if (option == 1) {
            turnOnAllLights(lights, numLights);
        } else if (option == 2) {
            turnOffAllLights(lights, numLights);
        } else if (option == 3) {
            printf("Enter name of light to toggle: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);

            bool foundLight = false;

            for (int i = 0; i < numLights; i++) {
                if (strcmp(lights[i].name, name) == 0) {
                    toggleLight(&lights[i]);
                    foundLight = true;
                    break;
                }
            }

            if (!foundLight) {
                printf("Light %s not found.\n", name);
            }

        } else if (option == 4) {
            displayAllLights(lights, numLights);
        } else if (option == 5) {
            break;
        }

    }

    return 0;
}