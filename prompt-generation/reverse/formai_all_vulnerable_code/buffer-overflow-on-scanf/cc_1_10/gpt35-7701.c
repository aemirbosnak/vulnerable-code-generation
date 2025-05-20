//FormAI DATASET v1.0 Category: Smart home automation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate random numbers
int generateRandom(int min, int max) {
   return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare variables
    bool powerOn = true;
    int temperature = 72;
    int humidity = 50;
    int lightIntensity = 100;
    int airQuality = 0;
    int menuChoice;

    // Print welcome message
    printf("Welcome to the Smart Home Automation System\n");

    // Main program loop
    while(powerOn) {
        // Print status of system
        printf("\nCurrent System Status:\n");
        printf("Temperature: %d degrees\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Light Intensity: %d%%\n", lightIntensity);
        printf("Air Quality: %d ppm\n", airQuality);

        // Print menu options
        printf("\nMenu Options:\n");
        printf("1. Change temperature\n");
        printf("2. Change humidity\n");
        printf("3. Change light intensity\n");
        printf("4. Run air filtration system\n");
        printf("5. Quit\n");

        // Get user input
        printf("Enter choice: ");
        scanf("%d", &menuChoice);

        // Process user input
        switch(menuChoice) {
            case 1:
                // Change temperature
                printf("\nEnter new temperature value: ");
                scanf("%d", &temperature);
                break;
            case 2:
                // Change humidity
                printf("\nEnter new humidity value: ");
                scanf("%d", &humidity);
                break;
            case 3:
                // Change light intensity
                printf("\nEnter new light intensity value: ");
                scanf("%d", &lightIntensity);
                break;
            case 4:
                // Run air filtration system
                airQuality = generateRandom(0, 500);
                break;
            case 5:
                // Quit program
                printf("\nShutting down Smart Home Automation System...\n");
                powerOn = false;
                break;
            default:
                // Handle invalid input
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    }

    // End program
    return 0;
}