//FormAI DATASET v1.0 Category: Smart home automation ; Style: authentic
#include <stdio.h>
#include <stdbool.h>

/* Function to turn on lights*/
void turnOnLights() {
    printf("Lights are now ON.\n");
}

/* Function to turn off lights*/
void turnOffLights() {
    printf("Lights are now OFF.\n");
}

/* Function to turn on AC*/
void turnOnAC() {
    printf("AC is now ON.\n");
}

/* Function to turn off AC*/
void turnOffAC() {
    printf("AC is now OFF.\n");
}

int main() {
    bool lightsOn = false;
    bool acOn = false;

    char userInput = ' ';
    printf("Welcome to Smart Home Automation!\n");

    while (true) {
        printf("Press 'L' to toggle lights and 'A' to toggle AC or 'Q' to quit: ");
        scanf(" %c", &userInput);

        switch (userInput) {
            case 'L':
            case 'l':
                if (lightsOn) {
                    turnOffLights();
                    lightsOn = false;
                }
                else {
                    turnOnLights();
                    lightsOn = true;
                }
                break;
            case 'A':
            case 'a':
                if (acOn) {
                    turnOffAC();
                    acOn = false;
                }
                else {
                    turnOnAC();
                    acOn = true;
                }
                break;
            case 'Q':
            case 'q':
                printf("Thank you for using Smart Home Automation!\n");
                return 0;
            default:
                printf("Invalid input! Try again.\n");
                break;
        }
    }

    return 0;
}