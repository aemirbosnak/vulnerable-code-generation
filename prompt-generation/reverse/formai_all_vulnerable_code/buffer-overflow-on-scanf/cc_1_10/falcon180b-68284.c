//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    float celsius = fahrenheitToCelsius(fahrenheit);
    float kelvin = celsius + 273.15;
    return kelvin;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    float celsius = kelvinToCelsius(kelvin);
    float fahrenheit = celsiusToFahrenheit(celsius);
    return fahrenheit;
}

int main() {
    float temperature, converted_temperature;
    char choice;

    // Get user input for temperature and temperature scale
    printf("Enter the temperature: ");
    scanf("%f", &temperature);
    printf("Enter the temperature scale (C/F/K): ");
    scanf(" %c", &choice);

    // Convert temperature based on user input
    switch(choice) {
        case 'C':
            printf("%.2f degrees Celsius is equal to: ", temperature);
            converted_temperature = celsiusToFahrenheit(temperature);
            printf("%.2f degrees Fahrenheit\n", converted_temperature);
            break;
        case 'F':
            printf("%.2f degrees Fahrenheit is equal to: ", temperature);
            converted_temperature = fahrenheitToCelsius(temperature);
            printf("%.2f degrees Celsius\n", converted_temperature);
            break;
        case 'K':
            printf("%.2f degrees Celsius is equal to: ", temperature);
            converted_temperature = celsiusToKelvin(temperature);
            printf("%.2f Kelvin\n", converted_temperature);
            break;
        default:
            printf("Invalid temperature scale entered.\n");
    }

    return 0;
}