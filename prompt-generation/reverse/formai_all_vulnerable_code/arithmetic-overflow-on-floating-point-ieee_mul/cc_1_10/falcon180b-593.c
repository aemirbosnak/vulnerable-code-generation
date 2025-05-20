//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
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

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    float kelvin = (fahrenheit + 459.67) * 5/9;
    return kelvin;
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    float fahrenheit = (kelvin - 459.67) * 9/5 + 32;
    return fahrenheit;
}

int main() {
    int choice;
    float temperature, convertedTemperature;
    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter your choice:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    scanf("%d", &choice);
    printf("Enter the temperature to convert: ");
    scanf("%f", &temperature);
    switch(choice) {
        case 1:
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", temperature, convertedTemperature);
            break;
        case 2:
            convertedTemperature = fahrenheitToCelsius(temperature);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", temperature, convertedTemperature);
            break;
        case 3:
            convertedTemperature = kelvinToCelsius(temperature);
            printf("%.2f degrees Celsius is equal to %.2f Kelvin.", temperature, convertedTemperature);
            break;
        case 4:
            convertedTemperature = celsiusToFahrenheit(temperature);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", temperature, convertedTemperature);
            break;
        case 5:
            convertedTemperature = kelvinToCelsius(temperature);
            printf("%.2f Kelvin is equal to %.2f degrees Celsius.", temperature, convertedTemperature);
            break;
        case 6:
            convertedTemperature = kelvinToFahrenheit(temperature);
            printf("%.2f Kelvin is equal to %.2f degrees Fahrenheit.", temperature, convertedTemperature);
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}