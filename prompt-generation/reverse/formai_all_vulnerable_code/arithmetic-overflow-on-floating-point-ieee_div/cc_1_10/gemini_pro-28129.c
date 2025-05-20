//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Declare the conversion functions
double fahrenheit_to_celsius(double fahrenheit);
double celsius_to_fahrenheit(double celsius);
double miles_to_kilometers(double miles);
double kilometers_to_miles(double kilometers);
double pounds_to_kilograms(double pounds);
double kilograms_to_pounds(double kilograms);

// Main function
int main() {
    // Declare the variables
    double value, result;
    char unit_from, unit_to;

    // Get the input from the user
    printf("Enter the value: ");
    scanf("%lf", &value);
    printf("Enter the unit from (F/C/M/K/P/L): ");
    scanf(" %c", &unit_from);
    printf("Enter the unit to (F/C/M/K/P/L): ");
    scanf(" %c", &unit_to);

    // Convert the value
    switch (unit_from) {
        case 'F':
            switch (unit_to) {
                case 'C':
                    result = fahrenheit_to_celsius(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    break;
            }
            break;
        case 'C':
            switch (unit_to) {
                case 'F':
                    result = celsius_to_fahrenheit(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    break;
            }
            break;
        case 'M':
            switch (unit_to) {
                case 'K':
                    result = miles_to_kilometers(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    break;
            }
            break;
        case 'K':
            switch (unit_to) {
                case 'M':
                    result = kilometers_to_miles(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    break;
            }
            break;
        case 'P':
            switch (unit_to) {
                case 'L':
                    result = pounds_to_kilograms(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    break;
            }
            break;
        case 'L':
            switch (unit_to) {
                case 'P':
                    result = kilograms_to_pounds(value);
                    break;
                default:
                    printf("Invalid unit conversion\n");
                    break;
            }
            break;
        default:
            printf("Invalid unit\n");
            break;
    }

    // Print the result
    printf("The converted value is: %.2f\n", result);

    return 0;
}

// Conversion functions
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double miles_to_kilometers(double miles) {
    return miles * 1.60934;
}

double kilometers_to_miles(double kilometers) {
    return kilometers / 1.60934;
}

double pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms / 0.453592;
}