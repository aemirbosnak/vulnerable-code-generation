//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: standalone
/*
 * Unit Converter
 *
 * This program converts units of length, mass, and time.
 *
 * Author: [Your Name]
 */

#include <stdio.h>

// Define the unit conversion factors
#define KILOMETERS_TO_MILES 0.621371
#define METERS_TO_CENTIMETERS 100
#define GRAMS_TO_OUNCES 0.035274
#define SECONDS_TO_HOURS 0.000277778

// Define the conversion functions
double kilometers_to_miles(double kilometers) {
    return kilometers * KILOMETERS_TO_MILES;
}

double meters_to_centimeters(double meters) {
    return meters * METERS_TO_CENTIMETERS;
}

double grams_to_ounces(double grams) {
    return grams * GRAMS_TO_OUNCES;
}

double seconds_to_hours(double seconds) {
    return seconds * SECONDS_TO_HOURS;
}

// Define the main function
int main() {
    // Declare variables
    double kilometers, meters, grams, seconds, miles, centimeters, ounces, hours;

    // Ask for input
    printf("Enter a value in kilometers: ");
    scanf("%lf", &kilometers);

    printf("Enter a value in meters: ");
    scanf("%lf", &meters);

    printf("Enter a value in grams: ");
    scanf("%lf", &grams);

    printf("Enter a value in seconds: ");
    scanf("%lf", &seconds);

    // Perform conversions
    miles = kilometers_to_miles(kilometers);
    centimeters = meters_to_centimeters(meters);
    ounces = grams_to_ounces(grams);
    hours = seconds_to_hours(seconds);

    // Print results
    printf("Kilometers to miles: %f\n", miles);
    printf("Meters to centimeters: %f\n", centimeters);
    printf("Grams to ounces: %f\n", ounces);
    printf("Seconds to hours: %f\n", hours);

    return 0;
}