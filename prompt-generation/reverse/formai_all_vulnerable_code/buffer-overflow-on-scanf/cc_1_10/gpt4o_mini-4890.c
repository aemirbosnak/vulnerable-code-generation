//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

// Maximum number of lights in the system
#define MAX_LIGHTS 5

// Define the structure to represent a smart light
typedef struct {
    int id;
    char name[30];
    bool is_on;
} SmartLight;

// Function prototypes
void initializeLights(SmartLight lights[], int count);
void toggleLight(SmartLight *light);
void displayLightStatus(SmartLight lights[], int count);
void displayMenu();
int getUserChoice();

int main() {
    SmartLight lights[MAX_LIGHTS];
    initializeLights(lights, MAX_LIGHTS);

    int choice;
    while (true) {
        displayMenu();
        choice = getUserChoice();

        if (choice == 0) {
            printf("Exiting the Smart Home Light Control application.\n");
            break;
        } else if (choice > 0 && choice <= MAX_LIGHTS) {
            toggleLight(&lights[choice - 1]);
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        displayLightStatus(lights, MAX_LIGHTS);
        sleep(2); // Sleep for a while for better user experience
    }

    return 0;
}

void initializeLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        lights[i].id = i + 1;
        snprintf(lights[i].name, sizeof(lights[i].name), "Living Room Light %d", i + 1);
        lights[i].is_on = false; // Initially all lights are off
    }
}

void toggleLight(SmartLight *light) {
    light->is_on = !light->is_on; // Toggle the status
    if (light->is_on) {
        printf("%s is now ON.\n", light->name);
    } else {
        printf("%s is now OFF.\n", light->name);
    }
}

void displayLightStatus(SmartLight lights[], int count) {
    printf("\nCurrent Light Status:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].is_on ? "ON" : "OFF");
    }
}

void displayMenu() {
    printf("\nSmart Home Light Control Menu:\n");
    printf("0: Exit\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%d: Toggle %s\n", i + 1, (i + 1) == 1 ? "Living Room Light" : "Light");
    }
    printf("Please select an option: ");
}

int getUserChoice() {
    int choice;
    if (scanf("%d", &choice) != 1) {
        while(getchar() != '\n'); // clear invalid input
        return -1;
    }
    return choice;
}