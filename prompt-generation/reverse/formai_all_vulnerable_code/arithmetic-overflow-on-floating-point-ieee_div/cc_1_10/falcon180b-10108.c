//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>

// Function to convert meters to feet
double metersToFeet(double meters) {
    return meters * 3.28084;
}

// Function to convert feet to meters
double feetToMeters(double feet) {
    return feet / 3.28084;
}

// Function to convert kilograms to pounds
double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

// Function to convert pounds to kilograms
double poundsToKilograms(double pounds) {
    return pounds / 2.20462;
}

// Function to convert liters to gallons
double litersToGallons(double liters) {
    return liters * 0.264172;
}

// Function to convert gallons to liters
double gallonsToLiters(double gallons) {
    return gallons / 0.264172;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    double meters, feet, kilograms, pounds, liters, gallons, celsius, fahrenheit;

    // Get user input
    printf("Enter the value to convert:\n");
    scanf("%lf", &meters);

    // Convert meters to feet
    printf("%.2lf meters = %.2lf feet\n", meters, metersToFeet(meters));

    // Convert feet to meters
    printf("%.2lf feet = %.2lf meters\n", metersToFeet(meters), feetToMeters(meters));

    // Convert kilograms to pounds
    printf("%.2lf kilograms = %.2lf pounds\n", kilograms, kilogramsToPounds(kilograms));

    // Convert pounds to kilograms
    printf("%.2lf pounds = %.2lf kilograms\n", pounds, poundsToKilograms(kilograms));

    // Convert liters to gallons
    printf("%.2lf liters = %.2lf gallons\n", liters, litersToGallons(liters));

    // Convert gallons to liters
    printf("%.2lf gallons = %.2lf liters\n", gallons, gallonsToLiters(gallons));

    // Convert Celsius to Fahrenheit
    printf("%.2lf Celsius = %.2lf Fahrenheit\n", celsius, celsiusToFahrenheit(celsius));

    // Convert Fahrenheit to Celsius
    printf("%.2lf Fahrenheit = %.2lf Celsius\n", fahrenheit, fahrenheitToCelsius(fahrenheit));

    return 0;
}