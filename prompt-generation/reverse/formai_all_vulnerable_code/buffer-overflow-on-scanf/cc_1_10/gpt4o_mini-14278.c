//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

typedef enum { OFF, ON } State;

typedef struct {
    char name[NAME_LENGTH];
    State state;
} SmartLight;

void initializeLights(SmartLight lights[], int count);
void printMenu();
void changeLightState(SmartLight lights[], int count);
void displayLightStatus(SmartLight lights[], int count);
void toggleLightState(SmartLight *light);
void setLightName(SmartLight *light);

int main() {
    SmartLight lights[MAX_DEVICES];
    int count = 0;
    int choice;

    // Initialize lights
    printf("Welcome to the Smart Home Light Control System!\n");
    printf("How many smart lights do you want to manage? (Max %d): ", MAX_DEVICES);
    scanf("%d", &count);

    if (count > MAX_DEVICES || count <= 0) {
        printf("Invalid number of lights! Exiting...\n");
        return 1;
    }

    initializeLights(lights, count);

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                changeLightState(lights, count);
                break;
            case 2:
                displayLightStatus(lights, count);
                break;
            case 3:
                printf("Exiting the Smart Home Light Control System.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
                break;
        }
    }

    return 0;
}

void initializeLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name for light %d: ", i + 1);
        setLightName(&lights[i]);
        lights[i].state = OFF;
    }
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Change Light State\n");
    printf("2. Display Light Status\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void changeLightState(SmartLight lights[], int count) {
    int index;
    printf("Enter the light number (1 to %d) to toggle: ", count);
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Invalid light number. Please try again.\n");
        return;
    }

    toggleLightState(&lights[index - 1]);
}

void displayLightStatus(SmartLight lights[], int count) {
    printf("\nLight Status:\n");
    for (int i = 0; i < count; i++) {
        printf("Light %d (%s): %s\n", i + 1, lights[i].name, lights[i].state == ON ? "ON" : "OFF");
    }
}

void toggleLightState(SmartLight *light) {
    light->state = (light->state == ON) ? OFF : ON;
    printf("Light '%s' is now %s.\n", light->name, light->state == ON ? "ON" : "OFF");
}

void setLightName(SmartLight *light) {
    char name[NAME_LENGTH];
    scanf("%s", name);
    strncpy(light->name, name, NAME_LENGTH - 1);
    light->name[NAME_LENGTH - 1] = '\0';  // Ensure null termination
}