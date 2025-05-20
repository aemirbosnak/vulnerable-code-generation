//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>

// Function prototypes
void printMenu();
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayResult(float result, char scale);

int main() {
    int choice;
    float temperature, convertedTemperature;

    while (1) {
        printMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        // Check for exit condition (option 3)
        if (choice == 3) {
            printf("Thank you for using the Temperature Converter! Goodbye!\n");
            break;
        }

        // Get temperature input based on user's choice
        if (choice == 1) {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            // Convert Celsius to Fahrenheit
            convertedTemperature = celsiusToFahrenheit(temperature);
            displayResult(convertedTemperature, 'F');
        } else if (choice == 2) {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            // Convert Fahrenheit to Celsius
            convertedTemperature = fahrenheitToCelsius(temperature);
            displayResult(convertedTemperature, 'C');
        } else {
            printf("Invalid choice! Please select a valid option.\n");
        }

        printf("\n-----------------------------------\n");
    }
    return 0;
}

void printMenu() {
    printf("\nWelcome to the Temperature Converter!\n");
    printf("====================================\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("====================================\n");
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void displayResult(float result, char scale) {
    if (scale == 'F') {
        printf("Converted Temperature: %.2f °F\n", result);
    } else {
        printf("Converted Temperature: %.2f °C\n", result);
    }
}