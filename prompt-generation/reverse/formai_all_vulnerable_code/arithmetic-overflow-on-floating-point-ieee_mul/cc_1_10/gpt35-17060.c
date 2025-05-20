//FormAI DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>

// Function for converting Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function for converting Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

int main() {
    int choice;
    float value, convertedValue;

    // Display welcome message
    printf("Cyberpunk Unit Converter\n");
    printf("========================\n\n");

    while (1) {
        // Display menu
        printf("Select the conversion type:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n\n");

        // Get user input for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Check for valid input
        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please try again.\n\n");
            continue;
        }

        // Exit program if choice is 3
        if (choice == 3) {
            printf("\nThanks for using Cyberpunk Unit Converter.\n");
            break;
        }

        // Get user input for value to be converted
        printf("\nEnter the value to be converted: ");
        scanf("%f", &value);

        // Convert value based on user choice
        if (choice == 1) {
            convertedValue = celsiusToFahrenheit(value);
            printf("%.2f Celsius = %.2f Fahrenheit\n\n", value, convertedValue);
        } else if (choice == 2) {
            convertedValue = fahrenheitToCelsius(value);
            printf("%.2f Fahrenheit = %.2f Celsius\n\n", value, convertedValue);
        }
    }

    return 0;
}