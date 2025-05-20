//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

int main() {
    float temperature;
    char unit;
    char choice;

    // Get user input for temperature and unit of measurement
    printf("Enter temperature value: ");
    scanf("%f", &temperature);

    printf("Enter unit of measurement (F/C/K): ");
    scanf(" %c", &unit);

    // Convert temperature based on user's choice of unit
    switch(unit) {
        case 'F':
            temperature = celsiusToFahrenheit(temperature);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, fahrenheitToCelsius(temperature));
            break;
        case 'C':
            temperature = fahrenheitToCelsius(temperature);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
            break;
        case 'K':
            temperature = celsiusToKelvin(temperature);
            printf("%.2f degrees Celsius is equal to %.2f Kelvin.\n", temperature, kelvinToCelsius(temperature));
            break;
        default:
            printf("Invalid unit of measurement.\n");
            exit(0);
    }

    // Allow user to convert another temperature
    printf("Convert another temperature? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        main();
    } else {
        exit(0);
    }

    return 0;
}