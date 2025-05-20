//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert meters to feet and inches
void meterToFeet(double meters) {
    int feet = meters * 3.28084;
    double inches = (meters * 3.28084) - feet;

    printf("%.2f meters is equal to %d feet and %.2f inches.\n", meters, feet, inches);
}

// Function to convert kilometers to miles
void kilometerToMiles(double kilometers) {
    double miles = kilometers * 0.621371;

    printf("%.2f kilometers is equal to %0.2f miles.\n", kilometers, miles);
}

// Function to convert kilometers per hour to miles per hour
void kphToMph(double kph) {
    double mph = kph * 0.621371;

    printf("%.2f kph is equal to %0.2f mph.\n", kph, mph);
}

// Function to convert Celsius to Fahrenheit
void celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;

    printf("%.2f Celsius is equal to %0.2f Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert Fahrenheit to Celsius
void fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;

    printf("%.2f Fahrenheit is equal to %0.2f Celsius.\n", fahrenheit, celsius);
}

// Function to convert gallons to liters
void gallonsToLiters(double gallons) {
    double liters = gallons * 3.78541;

    printf("%.2f gallons is equal to %0.2f liters.\n", gallons, liters);
}

// Function to convert pounds to kilograms
void poundsToKilograms(double pounds) {
    double kilograms = pounds * 0.453592;

    printf("%.2f pounds is equal to %0.2f kilograms.\n", pounds, kilograms);
}

int main() {
    double meters, kilometers, kph, celsius, fahrenheit, gallons, pounds;

    // Get user input for meters
    printf("Enter the value in meters: ");
    scanf("%lf", &meters);

    // Convert meters to feet and inches
    meterToFeet(meters);

    // Get user input for kilometers
    printf("Enter the value in kilometers: ");
    scanf("%lf", &kilometers);

    // Convert kilometers to miles
    kilometerToMiles(kilometers);

    // Get user input for kph
    printf("Enter the value in kph: ");
    scanf("%lf", &kph);

    // Convert kph to mph
    kphToMph(kph);

    // Get user input for Celsius
    printf("Enter the value in Celsius: ");
    scanf("%lf", &celsius);

    // Convert Celsius to Fahrenheit
    celsiusToFahrenheit(celsius);

    // Get user input for Fahrenheit
    printf("Enter the value in Fahrenheit: ");
    scanf("%lf", &fahrenheit);

    // Convert Fahrenheit to Celsius
    fahrenheitToCelsius(fahrenheit);

    // Get user input for gallons
    printf("Enter the value in gallons: ");
    scanf("%lf", &gallons);

    // Convert gallons to liters
    gallonsToLiters(gallons);

    // Get user input for pounds
    printf("Enter the value in pounds: ");
    scanf("%lf", &pounds);

    // Convert pounds to kilograms
    poundsToKilograms(pounds);

    return 0;
}