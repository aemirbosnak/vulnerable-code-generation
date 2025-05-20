//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 20

typedef enum { OFF, ON } LightState;

typedef struct {
    char name[NAME_LENGTH];
    LightState state;
} SmartLight;

void initializeLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(lights[i].name, NAME_LENGTH, "Light %d", i + 1);
        lights[i].state = OFF;
    }
}

void switchLight(SmartLight *light) {
    light->state = (light->state == OFF) ? ON : OFF;
    printf("%s has been turned %s\n", light->name, light->state == ON ? "ON" : "OFF");
}

void displayLights(SmartLight lights[], int count) {
    printf("Current States of Lights:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].state == ON ? "ON" : "OFF");
    }
}

void controlLights(SmartLight lights[], int count) {
    char command[30];
    int lightIndex;

    while (1) {
        printf("Enter command (toggle <light number> or status to check lights, exit to quit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strncmp(command, "status", 6) == 0) {
            displayLights(lights, count);
        } else if (strncmp(command, "toggle", 6) == 0) {
            sscanf(command + 7, "%d", &lightIndex);
            if (lightIndex > 0 && lightIndex <= count) {
                switchLight(&lights[lightIndex - 1]);
            } else {
                printf("Invalid light number. Please enter a number between 1 and %d.\n", count);
            }
        } else if (strncmp(command, "exit", 4) == 0) {
            break;
        } else {
            printf("Unknown command, please try again.\n");
        }
    }
}

void simulateAutomation(SmartLight lights[], int count) {
    printf("Automation mode activated!\n");
    for (int i = 0; i < count; i++) {
        if (i % 2 == 0) {
            lights[i].state = ON;
        } else {
            lights[i].state = OFF;
        }
        printf("In automation, %s is now %s\n", lights[i].name, lights[i].state == ON ? "ON" : "OFF");
        sleep(1); // simulate time passing
    }
}

int main() {
    SmartLight lights[MAX_LIGHTS];
    initializeLights(lights, MAX_LIGHTS);

    int choice;
    printf("Welcome to the Mind-Bending Smart Home Light Control System!\n");
    printf("Choose your adventure:\n");
    printf("1. Manual Control Mode\n");
    printf("2. Automation Mode\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // clear the newline after scanf

    if (choice == 1) {
        controlLights(lights, MAX_LIGHTS);
    } else if (choice == 2) {
        simulateAutomation(lights, MAX_LIGHTS);
    } else {
        printf("Invalid choice! Exiting program.\n");
    }

    printf("Thank you for using the Smart Home Light Control System!\n");
    return 0;
}