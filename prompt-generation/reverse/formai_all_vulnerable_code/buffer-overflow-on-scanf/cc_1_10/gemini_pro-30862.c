//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Constants for conversion factors
#define METERS_PER_KILOMETER (1000)
#define FEET_PER_METER (3.28084)
#define INCHES_PER_FOOT (12)
#define CENTIMETERS_PER_INCH (2.54)

// Function to convert kilometers to meters
double kilometers_to_meters(double kilometers) {
    return kilometers * METERS_PER_KILOMETER;
}

// Function to convert meters to feet
double meters_to_feet(double meters) {
    return meters * FEET_PER_METER;
}

// Function to convert feet to inches
double feet_to_inches(double feet) {
    return feet * INCHES_PER_FOOT;
}

// Function to convert inches to centimeters
double inches_to_centimeters(double inches) {
    return inches * CENTIMETERS_PER_INCH;
}

// Main function
int main() {
    // Declare variables
    double value;
    char unit_from[50];
    char unit_to[50];

    // Get input from the user
    printf("Enter a value: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from (e.g., km, m, ft, in): ");
    scanf("%s", unit_from);
    printf("Enter the unit to convert to (e.g., km, m, ft, in): ");
    scanf("%s", unit_to);

    // Convert the value
    double result;
    if (strcmp(unit_from, "km") == 0 && strcmp(unit_to, "m") == 0) {
        result = kilometers_to_meters(value);
    } else if (strcmp(unit_from, "m") == 0 && strcmp(unit_to, "ft") == 0) {
        result = meters_to_feet(value);
    } else if (strcmp(unit_from, "ft") == 0 && strcmp(unit_to, "in") == 0) {
        result = feet_to_inches(value);
    } else if (strcmp(unit_from, "in") == 0 && strcmp(unit_to, "cm") == 0) {
        result = inches_to_centimeters(value);
    } else {
        printf("Invalid unit conversion specified.\n");
        return EXIT_FAILURE;
    }

    // Print the result
    printf("%lf %s is equal to %lf %s\n", value, unit_from, result, unit_to);

    return EXIT_SUCCESS;
}