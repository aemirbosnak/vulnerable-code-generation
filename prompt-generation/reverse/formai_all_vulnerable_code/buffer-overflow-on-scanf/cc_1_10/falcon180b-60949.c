//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to get valid input from user
double getValidInput(char* message) {
    double input;
    while (1) {
        printf("%s", message);
        if (scanf("%lf", &input) == 1) {
            return input;
        } else {
            printf("Invalid input. Please enter a valid number.\n");
            fflush(stdin);
        }
    }
}

int main() {
    char choice;
    double temperature;

    // Get user input for temperature and unit
    printf("Enter temperature: ");
    temperature = getValidInput("");
    printf("Enter unit (C/F): ");
    scanf(" %c", &choice);

    // Convert temperature based on user input
    if (choice == 'C' || choice == 'c') {
        printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
    } else if (choice == 'F' || choice == 'f') {
        printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", temperature, fahrenheitToCelsius(temperature));
    } else {
        printf("Invalid unit. Please enter C or F.\n");
    }

    return 0;
}