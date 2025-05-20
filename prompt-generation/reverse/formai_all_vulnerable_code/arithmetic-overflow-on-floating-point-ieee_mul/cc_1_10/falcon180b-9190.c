//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    char choice;
    double temperature;

    // Prompt user for choice
    printf("Enter C for Celsius to Fahrenheit conversion, F for Fahrenheit to Celsius conversion, or Q to quit: ");
    scanf("%c", &choice);

    // Convert choice to uppercase
    choice = toupper(choice);

    // Validate choice
    if (choice!= 'C' && choice!= 'F' && choice!= 'Q') {
        printf("Invalid choice. Program will now exit.\n");
        return 0;
    }

    // Prompt user for temperature
    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    // Convert Celsius to Fahrenheit
    if (choice == 'C') {
        printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
    }

    // Convert Fahrenheit to Celsius
    else if (choice == 'F') {
        printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, fahrenheitToCelsius(temperature));
    }

    // Quit program
    else if (choice == 'Q') {
        printf("Program will now exit.\n");
        return 0;
    }

    return 0;
}