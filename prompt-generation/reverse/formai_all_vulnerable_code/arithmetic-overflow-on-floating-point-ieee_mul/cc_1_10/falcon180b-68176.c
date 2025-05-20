//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to convert length from meters to feet
void meters_to_feet(double meters) {
    double feet = meters * 3.28084;
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
}

// Function to convert weight from kilograms to pounds
void kilograms_to_pounds(double kilograms) {
    double pounds = kilograms * 2.20462;
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);
}

// Function to convert temperature from Celsius to Fahrenheit
void celsius_to_fahrenheit(double celsius) {
    double fahrenheit = (celsius * 9.0 / 5.0) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert volume from liters to gallons
void liters_to_gallons(double liters) {
    double gallons = liters * 0.264172;
    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);
}

int main() {
    double meters, kilograms, celsius, liters;

    // Get user input for length in meters
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    meters_to_feet(meters);

    // Get user input for weight in kilograms
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    kilograms_to_pounds(kilograms);

    // Get user input for temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    celsius_to_fahrenheit(celsius);

    // Get user input for volume in liters
    printf("Enter volume in liters: ");
    scanf("%lf", &liters);
    liters_to_gallons(liters);

    return 0;
}