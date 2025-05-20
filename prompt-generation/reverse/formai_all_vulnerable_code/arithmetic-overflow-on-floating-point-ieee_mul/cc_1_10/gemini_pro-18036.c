//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Declare the conversion functions
double convert_celsius_to_fahrenheit(double celsius);
double convert_fahrenheit_to_celsius(double fahrenheit);
double convert_meters_to_feet(double meters);
double convert_feet_to_meters(double feet);
double convert_kilograms_to_pounds(double kilograms);
double convert_pounds_to_kilograms(double pounds);

// Define the main function
int main() {
    // Declare the variables
    double value;
    char unit_from;
    char unit_to;

    // Get the input from the user
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);
    printf("Enter the unit of the value to be converted (C/F/M/FT/KG/LB): ");
    scanf(" %c", &unit_from);
    printf("Enter the unit to which the value should be converted (C/F/M/FT/KG/LB): ");
    scanf(" %c", &unit_to);

    // Convert the value according to the user's input
    double converted_value;
    switch (unit_from) {
        case 'C':
            if (unit_to == 'F') {
                converted_value = convert_celsius_to_fahrenheit(value);
            } else {
                printf("Invalid conversion: Celsius to %c", unit_to);
                return 1;
            }
            break;
        case 'F':
            if (unit_to == 'C') {
                converted_value = convert_fahrenheit_to_celsius(value);
            } else {
                printf("Invalid conversion: Fahrenheit to %c", unit_to);
                return 1;
            }
            break;
        case 'M':
            if (unit_to == 'FT') {
                converted_value = convert_meters_to_feet(value);
            } else {
                printf("Invalid conversion: Meters to %c", unit_to);
                return 1;
            }
            break;
        case 'FT':
            if (unit_to == 'M') {
                converted_value = convert_feet_to_meters(value);
            } else {
                printf("Invalid conversion: Feet to %c", unit_to);
                return 1;
            }
            break;
        case 'KG':
            if (unit_to == 'LB') {
                converted_value = convert_kilograms_to_pounds(value);
            } else {
                printf("Invalid conversion: Kilograms to %c", unit_to);
                return 1;
            }
            break;
        case 'LB':
            if (unit_to == 'KG') {
                converted_value = convert_pounds_to_kilograms(value);
            } else {
                printf("Invalid conversion: Pounds to %c", unit_to);
                return 1;
            }
            break;
        default:
            printf("Invalid unit: %c", unit_from);
            return 1;
    }

    // Print the converted value
    printf("The converted value is: %.2f %c\n", converted_value, unit_to);

    return 0;
}

// Define the conversion functions
double convert_celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double convert_fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convert_meters_to_feet(double meters) {
    return meters * 3.28084;
}

double convert_feet_to_meters(double feet) {
    return feet / 3.28084;
}

double convert_kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double convert_pounds_to_kilograms(double pounds) {
    return pounds / 2.20462;
}