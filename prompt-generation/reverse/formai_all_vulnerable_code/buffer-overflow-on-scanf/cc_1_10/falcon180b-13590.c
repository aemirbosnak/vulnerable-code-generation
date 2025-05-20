//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    char choice;
    float temperature, convertedTemperature;

    do {
        // Display menu
        printf("\nCelsius to Fahrenheit Converter\n");
        printf("---------------------------------\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        // Convert choice to integer for easier comparison in switch statement
        choice = choice - '0';

        // Perform conversion based on user choice
        switch(choice) {
            case 1:
                // Celsius to Fahrenheit conversion
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, convertedTemperature);
                break;

            case 2:
                // Fahrenheit to Celsius conversion
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, convertedTemperature);
                break;

            case 3:
                // Exit program
                printf("Exiting program...\n");
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 3);

    return 0;
}