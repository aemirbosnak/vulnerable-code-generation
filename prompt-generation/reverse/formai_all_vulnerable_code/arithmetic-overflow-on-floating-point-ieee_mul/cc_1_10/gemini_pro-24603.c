//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Constants
#define CELSIUS_TO_FAHRENHEIT_FACTOR 1.8
#define FAHRENHEIT_TO_CELSIUS_FACTOR 0.5555555555555556 // 1 / 1.8

// Function prototypes
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main() {
    // Variables
    double celsius, fahrenheit;
    char choice;

    // Get the user's choice
    printf("Enter your choice (C/F): ");
    scanf(" %c", &choice);

    // Convert the temperature based on the user's choice
    switch (choice) {
        case 'C':
        case 'c':
            printf("Enter the temperature in Celsius: ");
            scanf(" %lf", &celsius);
            fahrenheit = celsius_to_fahrenheit(celsius);
            printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
            break;
        case 'F':
        case 'f':
            printf("Enter the temperature in Fahrenheit: ");
            scanf(" %lf", &fahrenheit);
            celsius = fahrenheit_to_celsius(fahrenheit);
            printf("The temperature in Celsius is: %.2f\n", celsius);
            break;
        default:
            printf("Invalid choice. Please enter C or F.\n");
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * CELSIUS_TO_FAHRENHEIT_FACTOR) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * FAHRENHEIT_TO_CELSIUS_FACTOR;
}