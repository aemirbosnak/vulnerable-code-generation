//FormAI DATASET v1.0 Category: Smart home light control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to turn on the light
void turnOnLight() {
    printf("Turning on the light...\n");
    // Call code to turn on the light
}

// Function to turn off the light
void turnOffLight() {
    printf("Turning off the light...\n");
    // Call code to turn off the light
}

// Function to dim the light
void dimLight(int level) {
    printf("Dimming the light to level %d...\n", level);
    // Call code to adjust the light level
}

int main() {
    // Initialize variables
    int choice, level;
    // Display menu options
    printf("Welcome to the Smart Home Light Control System\n");
    printf("1) Turn on the light\n");
    printf("2) Turn off the light\n");
    printf("3) Dim the light\n");

    // Get choice from user
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Process user choice
    switch(choice) {
        case 1:
            turnOnLight();
            break;
        case 2:
            turnOffLight();
            break;
        case 3:
            printf("Enter the desired light level (1-10): ");
            scanf("%d", &level);
            dimLight(level);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}