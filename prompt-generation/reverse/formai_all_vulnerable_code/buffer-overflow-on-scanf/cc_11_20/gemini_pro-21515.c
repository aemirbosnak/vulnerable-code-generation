//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the unit conversion functions
double convert_length(double value, char from_unit, char to_unit) {
    if (from_unit == 'm' && to_unit == 'cm') {
        return value * 100.0;
    } else if (from_unit == 'cm' && to_unit == 'm') {
        return value / 100.0;
    } else if (from_unit == 'm' && to_unit == 'in') {
        return value * 39.3701;
    } else if (from_unit == 'in' && to_unit == 'm') {
        return value / 39.3701;
    } else {
        printf("Error: Invalid unit conversion specified.\n");
        return NAN;
    }
}

double convert_area(double value, char from_unit, char to_unit) {
    if (from_unit == 'm^2' && to_unit == 'cm^2') {
        return value * 10000.0;
    } else if (from_unit == 'cm^2' && to_unit == 'm^2') {
        return value / 10000.0;
    } else if (from_unit == 'm^2' && to_unit == 'ft^2') {
        return value * 10.7639;
    } else if (from_unit == 'ft^2' && to_unit == 'm^2') {
        return value / 10.7639;
    } else {
        printf("Error: Invalid unit conversion specified.\n");
        return NAN;
    }
}

double convert_volume(double value, char from_unit, char to_unit) {
    if (from_unit == 'm^3' && to_unit == 'cm^3') {
        return value * 1000000.0;
    } else if (from_unit == 'cm^3' && to_unit == 'm^3') {
        return value / 1000000.0;
    } else if (from_unit == 'm^3' && to_unit == 'ft^3') {
        return value * 35.3147;
    } else if (from_unit == 'ft^3' && to_unit == 'm^3') {
        return value / 35.3147;
    } else {
        printf("Error: Invalid unit conversion specified.\n");
        return NAN;
    }
}

// Define the main function
int main() {
    // Declare the variables
    double value;
    char from_unit, to_unit;

    // Get the user input
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from (m, cm, in): ");
    scanf(" %c", &from_unit);
    printf("Enter the unit to convert to (m, cm, in, m^2, cm^2, ft^2, m^3, cm^3, ft^3): ");
    scanf(" %c", &to_unit);

    // Check if the units are valid
    if (from_unit != 'm' && from_unit != 'cm' && from_unit != 'in' &&
        to_unit != 'm' && to_unit != 'cm' && to_unit != 'in' &&
        to_unit != 'm^2' && to_unit != 'cm^2' && to_unit != 'ft^2' &&
        to_unit != 'm^3' && to_unit != 'cm^3' && to_unit != 'ft^3') {
        printf("Error: Invalid unit specified.\n");
        return EXIT_FAILURE;
    }

    // Convert the value
    double converted_value;
    if (from_unit == to_unit) {
        converted_value = value;
    } else if (from_unit == 'm' || from_unit == 'cm' || from_unit == 'in') {
        converted_value = convert_length(value, from_unit, to_unit);
    } else if (from_unit == 'm^2' || from_unit == 'cm^2' || from_unit == 'ft^2') {
        converted_value = convert_area(value, from_unit, to_unit);
    } else if (from_unit == 'm^3' || from_unit == 'cm^3' || from_unit == 'ft^3') {
        converted_value = convert_volume(value, from_unit, to_unit);
    }

    // Print the converted value
    printf("The converted value is %.2f %c.\n", converted_value, to_unit);

    return EXIT_SUCCESS;
}