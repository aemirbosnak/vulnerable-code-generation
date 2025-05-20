//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>

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
    return kilograms / 0.453592;
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
    double value, result;
    char unitFrom, unitTo;

    // Get the user input
    printf("Enter the value: ");
    scanf("%lf", &value);
    printf("Enter the unit you are converting from (i for inches, c for centimeters, p for pounds, k for kilograms, f for fahrenheit, C for Celsius): ");
    scanf(" %c", &unitFrom);
    printf("Enter the unit you are converting to (i for inches, c for centimeters, p for pounds, k for kilograms, f for fahrenheit, C for Celsius): ");
    scanf(" %c", &unitTo);

    // Convert the value
    switch (unitFrom) {
        case 'i':
            switch (unitTo) {
                case 'c':
                    result = inchesToCentimeters(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    return 1;
            }
            break;
        case 'c':
            switch (unitTo) {
                case 'i':
                    result = centimetersToInches(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    return 1;
            }
            break;
        case 'p':
            switch (unitTo) {
                case 'k':
                    result = poundsToKilograms(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    return 1;
            }
            break;
        case 'k':
            switch (unitTo) {
                case 'p':
                    result = kilogramsToPounds(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    return 1;
            }
            break;
        case 'f':
            switch (unitTo) {
                case 'C':
                    result = fahrenheitToCelsius(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    return 1;
            }
            break;
        case 'C':
            switch (unitTo) {
                case 'f':
                    result = celsiusToFahrenheit(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    return 1;
            }
            break;
        default:
            printf("Invalid unit conversion\n");
            return 1;
    }

    // Print the result
    printf("The converted value is: %lf %c\n", result, unitTo);

    return 0;
}