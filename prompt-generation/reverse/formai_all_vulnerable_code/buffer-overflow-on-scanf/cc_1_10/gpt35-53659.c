//FormAI DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void turnOnLights();
void turnOffLights();
void adjustTemperature();
void lockDoors();
void unlockDoors();

// Global variables
bool lightsOn = false;
int temperature = 68;
bool doorsLocked = true;

// Main function
int main() {
    char input;

    printf("\nWelcome to Smart Home Automation!\n");

    while (true) {
        printf("\nWhat would you like to do? Enter the corresponding letter.\n");
        printf("a) Turn on lights\n");
        printf("b) Turn off lights\n");
        printf("c) Adjust temperature\n");
        printf("d) Lock doors\n");
        printf("e) Unlock doors\n");
        printf("q) Quit\n");

        scanf(" %c", &input);

        switch (input) {
            case 'a':
                turnOnLights();
                break;
            case 'b':
                turnOffLights();
                break;
            case 'c':
                adjustTemperature();
                break;
            case 'd':
                lockDoors();
                break;
            case 'e':
                unlockDoors();
                break;
            case 'q':
                printf("\nGoodbye!\n");
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("\nInvalid input. Please try again.\n");
        }
    }

    return 0;
}

void turnOnLights() {
    if (!lightsOn) {
        printf("\nTurning on lights...\n");
        lightsOn = true;
    } else {
        printf("\nLights are already on.\n");
    }
}

void turnOffLights() {
    if (lightsOn) {
        printf("\nTurning off lights...\n");
        lightsOn = false;
    } else {
        printf("\nLights are already off.\n");
    }
}

void adjustTemperature() {
    int newTemperature;

    printf("\nEnter desired temperature: ");
    scanf("%d", &newTemperature);

    if (newTemperature >= 60 && newTemperature <= 80) {
        temperature = newTemperature;
        printf("\nTemperature set to %d degrees.\n", temperature);
    } else {
        printf("\nInvalid temperature. Please enter a value between 60 and 80 degrees.\n");
    }
}

void lockDoors() {
    if (!doorsLocked) {
        printf("\nLocking doors...\n");
        doorsLocked = true;
    } else {
        printf("\nDoors are already locked.\n");
    }
}

void unlockDoors() {
    if (doorsLocked) {
        printf("\nUnlocking doors...\n");
        doorsLocked = false;
    } else {
        printf("\nDoors are already unlocked.\n");
    }
}