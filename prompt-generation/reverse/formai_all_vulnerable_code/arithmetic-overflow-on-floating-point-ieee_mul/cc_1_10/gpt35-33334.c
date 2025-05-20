//FormAI DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Convert Fahrenheit to Celsius 
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Convert Celsius to Kelvin 
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Convert Kelvin to Celsius 
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Convert Fahrenheit to Kelvin 
double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5/9;
}

// Convert Kelvin to Fahrenheit 
double kelvinToFahrenheit(double kelvin) {
    return (kelvin * 9/5) - 459.67;
}

int main() {
    // Welcome message
    printf("Welcome to the Unit Converter!\n\n");

    // Prompt user for input unit
    printf("What unit are you converting from?\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    int inputUnit;
    scanf("%d", &inputUnit);

    // Prompt user for output unit
    printf("\nWhat unit are you converting to?\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    int outputUnit;
    scanf("%d", &outputUnit);

    // Prompt user for input value
    printf("\nEnter the value you are converting: ");
    double inputValue;
    scanf("%lf", &inputValue);

    // Convert input to output and display result
    double outputValue;
    if (inputUnit == 1) {
        // Celsius to something
        if (outputUnit == 1) {
            // Celsius to Celsius
            outputValue = inputValue;
        } else if (outputUnit == 2) {
            // Celsius to Fahrenheit
            outputValue = celsiusToFahrenheit(inputValue);
        } else if (outputUnit == 3) {
            // Celsius to Kelvin 
            outputValue = celsiusToKelvin(inputValue);
        }
    } else if (inputUnit == 2) {
        // Fahrenheit to something
        if (outputUnit == 1) {
            // Fahrenheit to Celsius
            outputValue = fahrenheitToCelsius(inputValue);
        } else if (outputUnit == 2) {
            // Fahrenheit to Fahrenheit
            outputValue = inputValue;
        } else if (outputUnit == 3) {
            // Fahrenheit to Kelvin 
            outputValue = fahrenheitToKelvin(inputValue);
        }
    } else if (inputUnit == 3) {
        // Kelvin to something
        if (outputUnit == 1) {
            // Kelvin to Celsius
            outputValue = kelvinToCelsius(inputValue);
        } else if (outputUnit == 2) {
            // Kelvin to Fahrenheit
            outputValue = kelvinToFahrenheit(inputValue);
        } else if (outputUnit == 3) {
            // Kelvin to Kelvin 
            outputValue = inputValue;
        }
    }
    // Display output
    printf("\n%.2f converted from ", inputValue);
    if (inputUnit == 1) {
        printf("Celsius ");
    } else if (inputUnit == 2) {
        printf("Fahrenheit ");
    } else if (inputUnit == 3) {
        printf("Kelvin ");
    }

    printf("to ");
    if (outputUnit == 1) {
        printf("Celsius ");
    } else if (outputUnit == 2) {
        printf("Fahrenheit ");
    } else if (outputUnit == 3) {
        printf("Kelvin ");
    }

    printf("is %.2f", outputValue);

    return 0;
}