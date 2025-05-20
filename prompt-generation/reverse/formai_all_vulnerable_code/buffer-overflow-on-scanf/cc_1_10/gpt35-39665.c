//FormAI DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

// Global variables
bool isLightsOn = false;
bool isACOn = false;
bool isTVOn = false;

// Function to toggle lights
void toggleLights() {
    if (isLightsOn) {
        isLightsOn = false;
        printf("Turning lights off...\n");
    } else {
        isLightsOn = true;
        printf("Turning lights on...\n");
    }
}

// Function to toggle AC
void toggleAC() {
    if (isACOn) {
        isACOn = false;
        printf("Turning AC off...\n");
    } else {
        isACOn = true;
        printf("Turning AC on...\n");
    }
}

// Function to toggle TV
void toggleTV() {
    if (isTVOn) {
        isTVOn = false;
        printf("Turning TV off...\n");
    } else {
        isTVOn = true;
        printf("Turning TV on...\n");
    }
}

// Main function
int main() {
    char input;
    printf("Welcome to Smart Home Automation!\n");
    printf("Press L to toggle lights, A to toggle AC, T to toggle TV, and Q to quit.\n");
    while(true) {
        scanf(" %c", &input);
        if (input == 'L' || input == 'l') {
            toggleLights();
        } else if (input == 'A' || input == 'a') {
            toggleAC();
        } else if (input == 'T' || input == 't') {
            toggleTV();
        } else if (input == 'Q' || input == 'q') {
            printf("Exiting Smart Home Automation...\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}