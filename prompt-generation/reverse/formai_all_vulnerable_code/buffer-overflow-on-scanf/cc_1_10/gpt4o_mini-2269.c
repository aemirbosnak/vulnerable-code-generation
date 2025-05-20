//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void displayMenu();
void convertTemperature();

// Main function
int main() {
    printf("Welcome to Temperature Converter!\n");
    printf("This program allows you to convert temperatures between Celsius and Fahrenheit.\n");
    convertTemperature();
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nTemperature Conversion Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

// Function to convert temperature
void convertTemperature() {
    int choice;
    float temperature, result;
    
    while (1) {
        displayMenu();
        // Read user choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 3.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue; // Repeat the menu
        }

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter the temperature to convert: ");
        if (scanf("%f", &temperature) != 1) {
            printf("Invalid temperature input! Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue; // Repeat the menu
        }

        switch (choice) {
            case 1: // Celsius to Fahrenheit
                result = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, result);
                break;
            case 2: // Fahrenheit to Celsius
                result = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, result);
                break;
            default:
                printf("Invalid choice! Please select a valid option (1-3).\n");
        }
    }
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}