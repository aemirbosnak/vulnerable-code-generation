//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double kelvinToCelsius(double kelvin);
double celsiusToKelvin(double celsius);

// Main function
int main() {
    int choice;
    double temperature;

    // Prompt user to enter temperature type and value
    printf("Enter temperature type: ");
    scanf("%d", &choice);
    printf("Enter temperature value: ");
    scanf("%lf", &temperature);

    // Convert temperature based on user input
    switch(choice) {
        case 1: // Celsius to Fahrenheit
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
            break;
        case 2: // Fahrenheit to Celsius
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", temperature, fahrenheitToCelsius(temperature));
            break;
        case 3: // Celsius to Kelvin
            printf("%.2lf Celsius is equal to %.2lf Kelvin.\n", temperature, celsiusToKelvin(temperature));
            break;
        case 4: // Kelvin to Celsius
            printf("%.2lf Kelvin is equal to %.2lf Celsius.\n", temperature, kelvinToCelsius(temperature));
            break;
        default:
            printf("Invalid temperature type.\n");
            break;
    }

    return 0;
}

// Celsius to Fahrenheit conversion function
double celsiusToFahrenheit(double celsius) {
    double fahrenheit;
    fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Fahrenheit to Celsius conversion function
double fahrenheitToCelsius(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Celsius to Kelvin conversion function
double celsiusToKelvin(double celsius) {
    double kelvin;
    kelvin = celsius + 273.15;
    return kelvin;
}

// Kelvin to Celsius conversion function
double kelvinToCelsius(double kelvin) {
    double celsius;
    celsius = kelvin - 273.15;
    return celsius;
}