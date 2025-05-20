//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double kelvinToCelsius(double kelvin);
double celsiusToKelvin(double celsius);

int main() {
    double temperature, convertedTemperature;
    char choice;

    // Prompt user for input temperature and unit of measurement
    printf("Enter the temperature and unit of measurement (e.g. 20.5 C): ");
    scanf("%lf %c", &temperature, &choice);

    // Convert temperature to Celsius
    if (choice == 'C' || choice == 'c') {
        convertedTemperature = temperature;
    } 
    // Convert temperature to Fahrenheit
    else if (choice == 'F' || choice == 'f') {
        convertedTemperature = celsiusToFahrenheit(temperature);
    } 
    // Convert temperature to Kelvin
    else if (choice == 'K' || choice == 'k') {
        convertedTemperature = celsiusToKelvin(temperature);
    } 
    // Invalid input
    else {
        printf("Invalid input. Please enter a valid temperature and unit of measurement.\n");
        return 1;
    }

    // Output the converted temperature
    printf("The converted temperature is: %.2lf\n", convertedTemperature);

    return 0;
}

// Celsius to Fahrenheit conversion function
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

// Fahrenheit to Celsius conversion function
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

// Kelvin to Celsius conversion function
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Celsius to Kelvin conversion function
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}