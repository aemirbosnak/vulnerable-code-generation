//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

int main() {
    double celsius, fahrenheit, kelvin;

    // Get user input for temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    // Convert Celsius to Fahrenheit and display result
    printf("Temperature in Fahrenheit: %.2lf\n", celsiusToFahrenheit(celsius));

    // Convert Celsius to Kelvin and display result
    printf("Temperature in Kelvin: %.2lf\n", celsiusToKelvin(celsius));

    // Get user input for temperature in Fahrenheit
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);

    // Convert Fahrenheit to Celsius and display result
    printf("Temperature in Celsius: %.2lf\n", fahrenheitToCelsius(fahrenheit));

    // Convert Fahrenheit to Kelvin and display result
    printf("Temperature in Kelvin: %.2lf\n", celsiusToKelvin(fahrenheitToCelsius(fahrenheit)));

    // Get user input for temperature in Kelvin
    printf("Enter temperature in Kelvin: ");
    scanf("%lf", &kelvin);

    // Convert Kelvin to Celsius and display result
    printf("Temperature in Celsius: %.2lf\n", kelvinToCelsius(kelvin));

    // Convert Kelvin to Fahrenheit and display result
    printf("Temperature in Fahrenheit: %.2lf\n", celsiusToFahrenheit(kelvinToCelsius(kelvin)));

    return 0;
}