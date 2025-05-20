//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Main function
int main() {
    // Variable to store the temperature
    float temperature;

    // Variable to store the user's choice
    int choice;

    // Main loop
    while (1) {
        // Display the menu
        printf("Temperature Converter\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Get the user's choice
        scanf("%d", &choice);

        // Switch on the user's choice
        switch (choice) {
            case 1:
                // Get the temperature in Celsius
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &temperature);

                // Convert the temperature to Fahrenheit
                float fahrenheit = celsius_to_fahrenheit(temperature);

                // Display the temperature in Fahrenheit
                printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
                break;
            case 2:
                // Get the temperature in Fahrenheit
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &temperature);

                // Convert the temperature to Celsius
                float celsius = fahrenheit_to_celsius(temperature);

                // Display the temperature in Celsius
                printf("The temperature in Celsius is: %.2f\n", celsius);
                break;
            case 3:
                // Exit the program
                exit(0);
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
                break;
        }
    }

    return 0;
}