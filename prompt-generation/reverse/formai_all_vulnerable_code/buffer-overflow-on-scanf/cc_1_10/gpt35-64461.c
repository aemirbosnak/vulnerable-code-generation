//FormAI DATASET v1.0 Category: Smart home light control ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

// Define constants
#define NUM_LIGHTS 4
#define LIGHT_ON true
#define LIGHT_OFF false

// Define functions
void turnOnLight(int lightNum, bool* lights);
void turnOffLight(int lightNum, bool* lights);
void printStatus(bool* lights);

// Main program
int main() {
    // Initialize all lights to off
    bool lights[NUM_LIGHTS] = {LIGHT_OFF, LIGHT_OFF, LIGHT_OFF, LIGHT_OFF};

    printf("Welcome to the Smart Home Light Control System!\n\n");

    char choice;
    int lightNum;

    do {
        printf("Please select an option:\n");
        printf("1. Turn on a light\n");
        printf("2. Turn off a light\n");
        printf("3. View status of all lights\n");
        printf("4. Quit program\n");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Which light would you like to turn on? (1-%d)\n", NUM_LIGHTS);
                scanf("%d", &lightNum);
                turnOnLight(lightNum, lights);
                break;
            case '2':
                printf("Which light would you like to turn off? (1-%d)\n", NUM_LIGHTS);
                scanf("%d", &lightNum);
                turnOffLight(lightNum, lights);
                break;
            case '3':
                printStatus(lights);
                break;
            case '4':
                printf("Thank you for using the Smart Home Light Control System!\n");
                break;
            default:
                printf("Invalid option selected. Please try again.\n");
        }
    } while (choice != '4');

    return 0;
}

// Function to turn on a specified light
void turnOnLight(int lightNum, bool* lights) {
    if (lightNum > 0 && lightNum <= NUM_LIGHTS) {
        lights[lightNum-1] = LIGHT_ON;
        printf("Light %d turned on!\n", lightNum);
    } else {
        printf("Invalid light number. Please try again.\n");
    }
}

// Function to turn off a specified light
void turnOffLight(int lightNum, bool* lights) {
    if (lightNum > 0 && lightNum <= NUM_LIGHTS) {
        lights[lightNum-1] = LIGHT_OFF;
        printf("Light %d turned off!\n", lightNum);
    } else {
        printf("Invalid light number. Please try again.\n");
    }
}

// Function to print status of all lights
void printStatus(bool* lights) {
    printf("Current light status:\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("Light %d: %s\n", i+1, lights[i] ? "on" : "off");
    }
}