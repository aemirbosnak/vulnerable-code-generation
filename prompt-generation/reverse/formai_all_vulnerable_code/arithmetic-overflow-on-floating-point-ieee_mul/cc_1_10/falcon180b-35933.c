//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

int main() {
    char choice;
    double temperature;

    // Initializing the temperature as 0
    temperature = 0;

    // Looping until the user enters 'q' to quit the program
    do {
        // Displaying the menu
        printf("\nTemperature Converter\n");
        printf("------------------------\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Quit\n");

        // Taking input from the user
        printf("\nEnter your choice: ");
        scanf("%c", &choice);

        // Switching on the user's choice
        switch (choice) {
            // Celsius to Fahrenheit conversion
            case '1':
                printf("\nEnter temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("\n%.2lf Celsius = %.2lf Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
                break;

            // Fahrenheit to Celsius conversion
            case '2':
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("\n%.2lf Fahrenheit = %.2lf Celsius\n", temperature, fahrenheit_to_celsius(temperature));
                break;

            // Quit the program
            case '3':
                printf("\nExiting the program...\n");
                break;

            // Invalid choice
            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice!= 'q');

    return 0;
}