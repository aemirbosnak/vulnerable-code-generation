//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of lights in the smart home
#define MAX_LIGHTS 10

// Light state enumeration
typedef enum {
    OFF,
    ON
} LightState;

// Structure to represent a light
typedef struct {
    char name[30];
    LightState state;
} Light;

// Function prototypes
void initializeLights(Light lights[], int count);
void displayLightStatus(const Light lights[], int count);
void toggleLight(Light lights[], int count, const char *name);
void setLightState(Light lights[], int count, const char *name, LightState state);
void displayMenu();

int main() {
    Light lights[MAX_LIGHTS];
    int lightCount = 5; // Number of lights in the home
    char command[50];
    char lightName[30];

    // Initialize lights
    initializeLights(lights, lightCount);

    // Main loop for user interactions
    while (1) {
        displayLightStatus(lights, lightCount);
        displayMenu();

        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strcmp(command, "exit") == 0) {
            printf("Exiting smart home light control system.\n");
            break; // Exit the program
        }

        if (sscanf(command, "toggle %s", lightName) == 1) {
            toggleLight(lights, lightCount, lightName);
        } else if (sscanf(command, "turn on %s", lightName) == 1) {
            setLightState(lights, lightCount, lightName, ON);
        } else if (sscanf(command, "turn off %s", lightName) == 1) {
            setLightState(lights, lightCount, lightName, OFF);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}

// Function to initialize lights with default names and states
void initializeLights(Light lights[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].state = OFF;
    }
}

// Function to display the status of all lights
void displayLightStatus(const Light lights[], int count) {
    printf("\n--- Current Lights Status ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", lights[i].name, (lights[i].state == ON) ? "ON" : "OFF");
    }
}

// Function to toggle the state of a light
void toggleLight(Light lights[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].state = (lights[i].state == ON) ? OFF : ON;
            printf("%s toggled %s.\n", lights[i].name, (lights[i].state == ON) ? "ON" : "OFF");
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

// Function to set the state of a light
void setLightState(Light lights[], int count, const char *name, LightState state) {
    for (int i = 0; i < count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].state = state;
            printf("%s turned %s.\n", lights[i].name, (state == ON) ? "ON" : "OFF");
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

// Function to display the menu of commands
void displayMenu() {
    printf("\nAvailable commands:\n");
    printf("1. toggle [light name]\n");
    printf("2. turn on [light name]\n");
    printf("3. turn off [light name]\n");
    printf("4. exit\n");
}