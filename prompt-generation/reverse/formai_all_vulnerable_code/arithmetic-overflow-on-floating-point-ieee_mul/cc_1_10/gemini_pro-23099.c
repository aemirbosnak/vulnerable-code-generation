//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Temperature Monitor Activated!\n");
    printf("----------------------------\n");

    // Declare variables
    float tempCelsius, tempFahrenheit;
    char choice;

    // Welcome message
    printf("Hello there, temperature enthusiast!\n");
    printf("Welcome to the ultimate Temperature Monitor!\n");
    printf("Let's dive into the world of temperature and have some fun!\n\n");

    // Loop to continue the program
    while (1) {
        // Display menu
        printf("Temperature Monitor Menu:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Handle user choice
        switch (choice) {
            case '1':
                // Convert Celsius to Fahrenheit
                printf("Enter the temperature in Celsius: ");
                scanf(" %f", &tempCelsius);
                tempFahrenheit = (tempCelsius * 9 / 5) + 32;
                printf("Temperature in Fahrenheit: %.2f°F\n", tempFahrenheit);
                break;
            case '2':
                // Convert Fahrenheit to Celsius
                printf("Enter the temperature in Fahrenheit: ");
                scanf(" %f", &tempFahrenheit);
                tempCelsius = (tempFahrenheit - 32) * 5 / 9;
                printf("Temperature in Celsius: %.2f°C\n", tempCelsius);
                break;
            case '3':
                // Exit the program
                printf("Thank you for using Temperature Monitor!\n");
                printf("Goodbye!\n");
                exit(0);
            default:
                // Invalid choice
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
        printf("\n");
    }

    return 0;
}