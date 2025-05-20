//FormAI DATASET v1.0 Category: Smart home light control ; Style: cheerful
#include <stdio.h>

int main() {

    // Welcome message
    printf("Welcome to Smart Home Light Control!\n");

    // Initialize variables
    int lightsOn = 0;
    int brightness = 0;
    int mode = 0;

    // Main control loop
    while (1) {

        // Display current settings
        printf("\nCurrent settings:\n");
        if (lightsOn) {
            printf("Lights: ON\n");
            printf("Brightness: %d\n", brightness);
            printf("Mode: %d\n", mode);
        } else {
            printf("Lights: OFF\n");
        }

        // Prompt user for input
        printf("\nEnter a command:\n");
        printf("1 - Turn lights ON\n");
        printf("2 - Turn lights OFF\n");
        printf("3 - Adjust brightness\n");
        printf("4 - Change mode\n");
        printf("5 - Exit\n");

        // Get user's choice
        int choice;
        scanf("%d", &choice);

        // Handle user's choice
        switch (choice) {
            case 1: // Turn lights ON
                printf("Turning lights ON...\n");
                lightsOn = 1;
                break;
            case 2: // Turn lights OFF
                printf("Turning lights OFF...\n");
                lightsOn = 0;
                break;
            case 3: // Adjust brightness
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                printf("Setting brightness to %d...\n", brightness);
                break;
            case 4: // Change mode
                printf("Enter mode (1-5): ");
                scanf("%d", &mode);
                printf("Setting mode to %d...\n", mode);
                break;
            case 5: // Exit
                printf("Exiting Smart Home Light Control...\n");
                return 0;
            default: // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }

    }

}