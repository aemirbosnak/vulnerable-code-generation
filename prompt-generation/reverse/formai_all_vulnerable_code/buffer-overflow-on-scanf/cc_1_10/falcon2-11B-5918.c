//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert length from centimeters to inches
float centimetersToInches(float centimeters) {
    return centimeters * 0.393700787;
}

// Function to convert length from inches to centimeters
float inchesToCentimeters(float inches) {
    return inches * 2.54;
}

// Function to convert weight from grams to pounds
float gramsToPounds(float grams) {
    return grams * 0.0022046226218487495;
}

// Function to convert weight from pounds to grams
float poundsToGrams(float pounds) {
    return pounds * 453.59237;
}

int main() {
    float celsius;
    float fahrenheit;
    float inches;
    float centimeters;
    float grams;
    float pounds;

    // Input Celsius temperature
    printf("Enter Celsius temperature: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = celsiusToFahrenheit(celsius);

    // Print Fahrenheit temperature
    printf("Fahrenheit temperature: %.2f\n", fahrenheit);

    // Input length in centimeters
    printf("Enter length in centimeters: ");
    scanf("%f", &centimeters);

    // Convert centimeters to inches
    inches = centimetersToInches(centimeters);

    // Print length in inches
    printf("Length in inches: %.2f\n", inches);

    // Input weight in grams
    printf("Enter weight in grams: ");
    scanf("%f", &grams);

    // Convert grams to pounds
    pounds = gramsToPounds(grams);

    // Print weight in pounds
    printf("Weight in pounds: %.2f\n", pounds);

    return 0;
}