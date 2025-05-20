//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

int main() {
    double temperature, convertedTemperature;
    char choice;

    do {
        // Display menu
        printf("Temperature Conversion Menu:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        // Convert temperature based on user choice
        switch (choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", temperature, convertedTemperature);
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", temperature, convertedTemperature);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Ask user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}