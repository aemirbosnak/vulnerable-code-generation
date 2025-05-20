//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    return celsiusToFahrenheit(kelvinToCelsius(kelvin));
}

// Function to convert Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    return celsiusToKelvin(fahrenheitToCelsius(fahrenheit));
}

int main() {
    double temperature, result;
    char input[10], choice;

    // Prompt user to input temperature and unit
    printf("Enter temperature and unit (e.g. 25C): ");
    scanf("%s%c", input, &choice);

    // Convert input temperature to double
    temperature = atof(input);

    // Convert Celsius to Fahrenheit
    result = celsiusToFahrenheit(temperature);
    printf("%.2fC is %.2fF\n", temperature, result);

    // Convert Celsius to Kelvin
    result = celsiusToKelvin(temperature);
    printf("%.2fC is %.2fK\n", temperature, result);

    // Convert Fahrenheit to Celsius
    result = fahrenheitToCelsius(temperature);
    printf("%.2fF is %.2fC\n", temperature, result);

    // Convert Fahrenheit to Kelvin
    result = fahrenheitToKelvin(temperature);
    printf("%.2fF is %.2fK\n", temperature, result);

    // Convert Kelvin to Celsius
    result = kelvinToCelsius(temperature);
    printf("%.2fK is %.2fC\n", temperature, result);

    // Convert Kelvin to Fahrenheit
    result = kelvinToFahrenheit(temperature);
    printf("%.2fK is %.2fF\n", temperature, result);

    return 0;
}