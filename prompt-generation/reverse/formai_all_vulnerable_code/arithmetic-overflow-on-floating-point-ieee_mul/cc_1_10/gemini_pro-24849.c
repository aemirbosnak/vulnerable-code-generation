//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: decentralized
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
    return kilometers * 0.621371;
}

double convertInchesToCentimeters(double inches) {
    return inches * 2.54;
}

double convertCentimetersToInches(double centimeters) {
    return centimeters * 0.393701;
}

// Define the main function
int main() {
    // Get the input from the user
    printf("Enter the value you want to convert: ");
    double value;
    scanf("%lf", &value);

    printf("Enter the unit of the value (C for Celsius, F for Fahrenheit, M for Miles, K for Kilometers, I for Inches, CM for Centimeters): ");
    char unit;
    scanf(" %c", &unit);

    // Convert the value to the desired unit
    double convertedValue;
    switch (unit) {
        case 'C':
            convertedValue = convertCelsiusToFahrenheit(value);
            printf("The converted value is %.2f Fahrenheit.\n", convertedValue);
            break;
        case 'F':
            convertedValue = convertFahrenheitToCelsius(value);
            printf("The converted value is %.2f Celsius.\n", convertedValue);
            break;
        case 'M':
            convertedValue = convertMilesToKilometers(value);
            printf("The converted value is %.2f Kilometers.\n", convertedValue);
            break;
        case 'K':
            convertedValue = convertKilometersToMiles(value);
            printf("The converted value is %.2f Miles.\n", convertedValue);
            break;
        case 'I':
            convertedValue = convertInchesToCentimeters(value);
            printf("The converted value is %.2f Centimeters.\n", convertedValue);
            break;
        case 'CM':
            convertedValue = convertCentimetersToInches(value);
            printf("The converted value is %.2f Inches.\n", convertedValue);
            break;
        default:
            printf("Invalid unit entered.\n");
    }

    return 0;
}