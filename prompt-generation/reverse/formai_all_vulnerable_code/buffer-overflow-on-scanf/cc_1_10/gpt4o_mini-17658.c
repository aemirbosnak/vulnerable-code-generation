//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void displayMenu();
void convertCelsiusToFahrenheit(float celsius);
void convertFahrenheitToCelsius(float fahrenheit);
float getValidTemperature(char scale);
void handleConversion(int choice);

int main() {
    int userChoice;

    do {
        displayMenu();
        printf("Enter your choice (1-3): ");
        
        // Get and validate the user's choice
        if (scanf("%d", &userChoice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        handleConversion(userChoice);

    } while (userChoice != 3);

    printf("Thank you for using the Temperature Converter. Goodbye!\n");
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n*** Temperature Converter ***\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

// Function to convert Celsius to Fahrenheit
void convertCelsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert Fahrenheit to Celsius
void convertFahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
}

// Function to get a valid temperature input
float getValidTemperature(char scale) {
    float temperature;
    printf("Enter the temperature in %s: ", scale == 'C' ? "Celsius" : "Fahrenheit");
    while (1) {
        if (scanf("%f", &temperature) == 1) {
            return temperature;
        } else {
            printf("Invalid input. Please enter a valid temperature: ");
            while (getchar() != '\n'); // Clear input buffer
        }
    }
}

// Function to handle the conversion based on user choice
void handleConversion(int choice) {
    float temperature;
    switch (choice) {
        case 1:
            temperature = getValidTemperature('C');
            convertCelsiusToFahrenheit(temperature);
            break;
        case 2:
            temperature = getValidTemperature('F');
            convertFahrenheitToCelsius(temperature);
            break;
        case 3:
            break; // Exit the program
        default:
            printf("Invalid choice. Please select 1, 2, or 3.\n");
            break;
    }
}