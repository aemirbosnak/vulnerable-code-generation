//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double convertCelsiusToFahrenheit(double celsius) {
    return celsius * 9 / 5 + 32;
}

double convertFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convertMilesToKilometers(double miles) {
    return miles * 1.60934;
}

double convertKilometersToMiles(double kilometers) {
    return kilometers / 1.60934;
}

// Define the main function
int main() {
    // Print a welcome message
    printf("Welcome to the Unit Converter!\n");

    // Get the user's input
    printf("What unit would you like to convert? (C/F/M/K) ");
    char unit = getchar();

    printf("What is the value you would like to convert? ");
    double value;
    scanf("%lf", &value);

    // Convert the value based on the user's input
    double convertedValue;
    switch (unit) {
        case 'C':
            convertedValue = convertCelsiusToFahrenheit(value);
            printf("%lf degrees Celsius is %lf degrees Fahrenheit.\n", value, convertedValue);
            break;
        case 'F':
            convertedValue = convertFahrenheitToCelsius(value);
            printf("%lf degrees Fahrenheit is %lf degrees Celsius.\n", value, convertedValue);
            break;
        case 'M':
            convertedValue = convertMilesToKilometers(value);
            printf("%lf miles is %lf kilometers.\n", value, convertedValue);
            break;
        case 'K':
            convertedValue = convertKilometersToMiles(value);
            printf("%lf kilometers is %lf miles.\n", value, convertedValue);
            break;
        default:
            printf("Invalid unit entered.\n");
            break;
    }

    // Print a goodbye message
    printf("Thank you for using the Unit Converter!\n");

    return 0;
}