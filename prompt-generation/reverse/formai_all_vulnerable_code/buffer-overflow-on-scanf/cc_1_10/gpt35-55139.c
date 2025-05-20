//FormAI DATASET v1.0 Category: Smart home light control ; Style: enthusiastic
#include <stdio.h>

int main() {
    // Initialise variables
    int lightOn = 0;
    int brightness = 0;
    int red = 0;
    int green = 0;
    int blue = 0;

    // Display welcome message
    printf("Welcome to Smart Home Light Control!\n");

    // Loop indefinitely
    while (1) {
        // Display menu options
        printf("\nChoose an option:\n");
        printf("1. Turn the light on/off\n");
        printf("2. Adjust the brightness\n");
        printf("3. Change the color\n");
        printf("4. Exit\n");

        // Get user input
        int option;
        scanf("%d", &option);

        // Handle user input
        switch(option) {
            case 1:
                // Toggle light on/off
                if (lightOn == 0) {
                    printf("Turning the light on...\n");
                    lightOn = 1;
                } else {
                    printf("Turning the light off...\n");
                    lightOn = 0;
                }
                break;
            case 2:
                // Adjust brightness
                printf("Enter the brightness level (0-100):\n");
                scanf("%d", &brightness);
                printf("Setting brightness to %d...\n", brightness);
                break;
            case 3:
                // Change color
                printf("Enter the red value (0-255):\n");
                scanf("%d", &red);
                printf("Enter the green value (0-255):\n");
                scanf("%d", &green);
                printf("Enter the blue value (0-255):\n");
                scanf("%d", &blue);
                printf("Setting color to (%d, %d, %d)...\n", red, green, blue);
                break;
            case 4:
                // Exit program
                printf("Exiting Smart Home Light Control!\n");
                return 0;
            default:
                // Handle invalid input
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}