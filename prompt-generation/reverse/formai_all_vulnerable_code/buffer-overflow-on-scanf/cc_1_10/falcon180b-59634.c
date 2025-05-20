//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheitToCelsius(fahrenheit) + 273.15);
}

int main() {
    int choice;
    double temperature;

    // Prompt user for input
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    // Prompt user for conversion choice
    printf("Enter the conversion choice:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Celsius to Kelvin\n4. Fahrenheit to Kelvin\n");
    scanf("%d", &choice);

    // Perform conversion and display result
    switch(choice) {
        case 1:
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
            break;
        case 2:
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", temperature, fahrenheitToCelsius(temperature));
            break;
        case 3:
            printf("%.2lf Celsius is equal to %.2lf Kelvin.\n", temperature, celsiusToKelvin(temperature));
            break;
        case 4:
            printf("%.2lf Fahrenheit is equal to %.2lf Kelvin.\n", temperature, fahrenheitToKelvin(temperature));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}