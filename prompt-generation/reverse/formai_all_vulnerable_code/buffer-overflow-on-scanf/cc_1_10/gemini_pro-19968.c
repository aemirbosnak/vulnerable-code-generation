//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Constants for unit conversion factors
#define INCHES_TO_CENTIMETERS 2.54
#define CENTIMETERS_TO_INCHES 0.393701
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462

// Function to convert inches to centimeters
double inches_to_centimeters(double inches) {
    return inches * INCHES_TO_CENTIMETERS;
}

// Function to convert centimeters to inches
double centimeters_to_inches(double centimeters) {
    return centimeters * CENTIMETERS_TO_INCHES;
}

// Function to convert pounds to kilograms
double pounds_to_kilograms(double pounds) {
    return pounds * POUNDS_TO_KILOGRAMS;
}

// Function to convert kilograms to pounds
double kilograms_to_pounds(double kilograms) {
    return kilograms * KILOGRAMS_TO_POUNDS;
}

// Main function
int main() {
    // Initialize variables
    double inches, centimeters, pounds, kilograms;

    // Get user input
    printf("Enter a value in inches: ");
    scanf("%lf", &inches);
    printf("Enter a value in centimeters: ");
    scanf("%lf", &centimeters);
    printf("Enter a value in pounds: ");
    scanf("%lf", &pounds);
    printf("Enter a value in kilograms: ");
    scanf("%lf", &kilograms);

    // Convert units
    double converted_inches = inches_to_centimeters(inches);
    double converted_centimeters = centimeters_to_inches(centimeters);
    double converted_pounds = pounds_to_kilograms(pounds);
    double converted_kilograms = kilograms_to_pounds(kilograms);

    // Print results
    printf("\nInches converted to centimeters: %lf\n", converted_inches);
    printf("Centimeters converted to inches: %lf\n", converted_centimeters);
    printf("Pounds converted to kilograms: %lf\n", converted_pounds);
    printf("Kilograms converted to pounds: %lf\n", converted_kilograms);

    return 0;
}