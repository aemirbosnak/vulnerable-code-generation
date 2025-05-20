//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <math.h>

// Define the unit conversion functions
double inchesToCentimeters(double inches) {
    return inches * 2.54;
}

double centimetersToInches(double centimeters) {
    return centimeters / 2.54;
}

double poundsToKilograms(double pounds) {
    return pounds * 0.453592;
}

double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Define the main function
int main() {
    // Declare the variables
    double value;
    char unitFrom;
    char unitTo;

    // Get the input from the user
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value (i/cm, lb/kg, f/c): ");
    scanf(" %c/%c", &unitFrom, &unitTo);

    // Convert the value
    double convertedValue;
    switch (unitFrom) {
        case 'i':
            if (unitTo == 'cm') {
                convertedValue = inchesToCentimeters(value);
            } else {
                printf("Invalid unit conversion.");
                return 1;
            }
            break;
        case 'cm':
            if (unitTo == 'i') {
                convertedValue = centimetersToInches(value);
            } else {
                printf("Invalid unit conversion.");
                return 1;
            }
            break;
        case 'lb':
            if (unitTo == 'kg') {
                convertedValue = poundsToKilograms(value);
            } else {
                printf("Invalid unit conversion.");
                return 1;
            }
            break;
        case 'kg':
            if (unitTo == 'lb') {
                convertedValue = kilogramsToPounds(value);
            } else {
                printf("Invalid unit conversion.");
                return 1;
            }
            break;
        case 'f':
            if (unitTo == 'c') {
                convertedValue = fahrenheitToCelsius(value);
            } else {
                printf("Invalid unit conversion.");
                return 1;
            }
            break;
        case 'c':
            if (unitTo == 'f') {
                convertedValue = celsiusToFahrenheit(value);
            } else {
                printf("Invalid unit conversion.");
                return 1;
            }
            break;
        default:
            printf("Invalid unit.");
            return 1;
    }

    // Print the result
    printf("The converted value is: %lf", convertedValue);

    return 0;
}