//FormAI DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to turn the lights on
void turnOnLights() {
    printf("Lights turned on!\n");
}

// function to turn the lights off
void turnOffLights() {
    printf("Lights turned off!\n");
}

// function to adjust the brightness level of the lights
void adjustBrightness(int brightnessLevel) {
    printf("Lights brightness adjusted to %d!\n", brightnessLevel);
}

// function to set a timer for the lights
void setTimer(int minutes) {
    printf("Timer set for %d minutes!\n", minutes);
}

int main() {
    char userInput[50];

    printf("Welcome to your Smart Home Light Control!\n");
    printf("Please select an option by typing the corresponding number:\n");
    printf("1. Turn lights on\n");
    printf("2. Turn lights off\n");
    printf("3. Adjust brightness level\n");
    printf("4. Set timer for lights\n");

    // continuously prompting user for input until they choose to exit
    while (1) {
        scanf("%s", userInput);

        // handling user input
        if (strcmp(userInput, "1") == 0) {
            turnOnLights();
        } else if (strcmp(userInput, "2") == 0) {
            turnOffLights();
        } else if (strcmp(userInput, "3") == 0) {
            printf("Please input brightness level (0-100):\n");
            int brightnessLevel;
            scanf("%d", &brightnessLevel);
            adjustBrightness(brightnessLevel);
        } else if (strcmp(userInput, "4") == 0) {
            printf("Please input timer length (minutes):\n");
            int minutes;
            scanf("%d", &minutes);
            setTimer(minutes);
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}