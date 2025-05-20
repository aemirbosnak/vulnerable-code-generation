//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return (celsiusToKelvin(fahrenheitToCelsius(fahrenheit)));
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return (celsiusToFahrenheit(kelvinToCelsius(kelvin)));
}

// Main function to take user input and display result
int main() {
    int choice;
    double value;

    // Menu to display options
    printf("Temperature Conversion Menu\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");

    // Taking user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Taking user input value
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    // Performing conversion based on user choice
    switch(choice) {
        case 1:
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", value, celsiusToFahrenheit(value));
            break;
        case 2:
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", value, fahrenheitToCelsius(value));
            break;
        case 3:
            printf("%.2lf Celsius is equal to %.2lf Kelvin.\n", value, celsiusToKelvin(value));
            break;
        case 4:
            printf("%.2lf Fahrenheit is equal to %.2lf Kelvin.\n", value, fahrenheitToKelvin(value));
            break;
        case 5:
            printf("%.2lf Kelvin is equal to %.2lf Celsius.\n", value, kelvinToCelsius(value));
            break;
        case 6:
            printf("%.2lf Kelvin is equal to %.2lf Fahrenheit.\n", value, kelvinToFahrenheit(value));
            break;
        case 7:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid choice.\n");
    }

    return 0;
}