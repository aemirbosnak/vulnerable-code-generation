//FormAI DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
    float celsius = fahrenheitToCelsius(fahrenheit);
    return celsiusToKelvin(celsius);
}

// Function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
    float celsius = kelvinToCelsius(kelvin);
    return celsiusToFahrenheit(celsius);
}

int main() {
    int choice;
    float inputValue, outputValue;
    char fromUnit[20], toUnit[20];
    
    printf("Welcome to the Unit Converter!\n");
    printf("Which unit would you like to convert from? (Celsius/Fahrenheit/Kelvin): ");
    scanf("%s", fromUnit);
    printf("Which unit would you like to convert to? (Celsius/Fahrenheit/Kelvin): ");
    scanf("%s", toUnit);
    printf("Enter the value you would like to convert: ");
    scanf("%f", &inputValue);
    
    if (strcmp(fromUnit, "Celsius") == 0) {
        if (strcmp(toUnit, "Fahrenheit") == 0) {
            outputValue = celsiusToFahrenheit(inputValue);
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", inputValue, outputValue);
        } else if (strcmp(toUnit, "Kelvin") == 0) {
            outputValue = celsiusToKelvin(inputValue);
            printf("%.2f degrees Celsius is %.2f Kelvin.\n", inputValue, outputValue);
        } else {
            printf("Invalid unit. Please try again.\n");
        }
    } else if (strcmp(fromUnit, "Fahrenheit") == 0) {
        if (strcmp(toUnit, "Celsius") == 0) {
            outputValue = fahrenheitToCelsius(inputValue);
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", inputValue, outputValue);
        } else if (strcmp(toUnit, "Kelvin") == 0) {
            outputValue = fahrenheitToKelvin(inputValue);
            printf("%.2f degrees Fahrenheit is %.2f Kelvin.\n", inputValue, outputValue);
        } else {
            printf("Invalid unit. Please try again.\n");
        }
    } else if (strcmp(fromUnit, "Kelvin") == 0) {
        if (strcmp(toUnit, "Celsius") == 0) {
            outputValue = kelvinToCelsius(inputValue);
            printf("%.2f Kelvin is %.2f degrees Celsius.\n", inputValue, outputValue);
        } else if (strcmp(toUnit, "Fahrenheit") == 0) {
            outputValue = kelvinToFahrenheit(inputValue);
            printf("%.2f Kelvin is %.2f degrees Fahrenheit.\n", inputValue, outputValue);
        } else {
            printf("Invalid unit. Please try again.\n");
        }
    } else {
        printf("Invalid unit. Please try again.\n");
    }
    
    return 0;
}