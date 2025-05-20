//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: calm
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
int main(void) {
    // Declare variables
    char choice;
    float temperature;

    // Display menu
    printf("\n\nTemperature Converter\n\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n\n");

    // Get user choice
    printf("Enter your choice (1-3): ");
    scanf("%c", &choice);

    // Convert temperature based on user choice
    switch (choice) {
        case '1':
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("Temperature in Fahrenheit: %.2f\n", celsius_to_fahrenheit(temperature));
            break;
        case '2':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("Temperature in Celsius: %.2f\n", fahrenheit_to_celsius(temperature));
            break;
        case '3':
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
            break;
    }

    // Return 0 to indicate successful execution
    return 0;
}