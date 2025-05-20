//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ada Lovelace
// Ada Lovelace style Temperature Converter in C

// Introduction
/*
Hello! I am a Temperature Converter program written in C, inspired by Ada Lovelace. I can convert temperatures from Celsius to Fahrenheit and from Fahrenheit to Celsius. Let's get started!
*/

// Libraries
#include <stdio.h> // Standard I/O functions

// Function Prototypes
float celsiusToFahrenheit(float celsiusTemp);
float fahrenheitToCelsius(float fahrenheitTemp);

// Main Function
int main() {

    // Variables
    float celsiusTemp, fahrenheitTemp, choice;

    printf("----------------------------------\n");
    printf("Welcome to the Temperature Converter\n");
    printf("----------------------------------\n\n");

    // Menu
    printf("What would you like to do?\n\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n\n");

    // User input
    printf("Enter your choice (1-2): ");
    scanf("%f", &choice);

    // Processing user input
    switch ((int)choice) {

        // Celsius to Fahrenheit
        case 1:

            // Getting Celsius temperature from user
            printf("\nEnter the temperature in Celsius: ");
            scanf("%f", &celsiusTemp);

            // Calling Celsius to Fahrenheit function
            fahrenheitTemp = celsiusToFahrenheit(celsiusTemp);

            // Printing result
            printf("\n%.2f Celsius = %.2f Fahrenheit", celsiusTemp, fahrenheitTemp);

            break;

        // Fahrenheit to Celsius
        case 2:

            // Getting Fahrenheit temperature from user
            printf("\nEnter the temperature in Fahrenheit: ");
            scanf("%f", &fahrenheitTemp);

            // Calling Fahrenheit to Celsius function
            celsiusTemp = fahrenheitToCelsius(fahrenheitTemp);

            // Printing result
            printf("\n%.2f Fahrenheit = %.2f Celsius", fahrenheitTemp, celsiusTemp);

            break;

        // Invalid input
        default:
            printf("\nInvalid choice. Please enter 1 or 2.");
    }

    printf("\n\nThank you for using the Temperature Converter!");
    return 0;
}

// Celsius to Fahrenheit Function
float celsiusToFahrenheit(float celsiusTemp) {
    return (celsiusTemp * 1.8) + 32;
}

// Fahrenheit to Celsius Function
float fahrenheitToCelsius(float fahrenheitTemp) {
    return (fahrenheitTemp - 32) / 1.8;
}