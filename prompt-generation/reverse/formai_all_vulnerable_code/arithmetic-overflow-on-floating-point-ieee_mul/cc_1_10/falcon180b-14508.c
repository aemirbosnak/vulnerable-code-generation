//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>

// Function to convert meters to feet
double metersToFeet(double meters) {
    double feet = meters * 3.28084;
    return feet;
}

// Function to convert feet to meters
double feetToMeters(double feet) {
    double meters = feet / 3.28084;
    return meters;
}

// Function to convert kilograms to pounds
double kilogramsToPounds(double kilograms) {
    double pounds = kilograms * 2.20462;
    return pounds;
}

// Function to convert pounds to kilograms
double poundsToKilograms(double pounds) {
    double kilograms = pounds / 2.20462;
    return kilograms;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

int main() {
    double meters, feet, kilograms, pounds, celsius, fahrenheit;

    // Get input from user
    printf("Enter the value to be converted:\n");
    scanf("%lf", &meters);

    // Convert meters to feet
    feet = metersToFeet(meters);

    // Convert feet to meters
    meters = feetToMeters(feet);

    // Convert kilograms to pounds
    pounds = kilogramsToPounds(kilograms);

    // Convert pounds to kilograms
    kilograms = poundsToKilograms(pounds);

    // Convert Celsius to Fahrenheit
    fahrenheit = celsiusToFahrenheit(celsius);

    // Convert Fahrenheit to Celsius
    celsius = fahrenheitToCelsius(fahrenheit);

    // Display the converted values
    printf("\n%lf meters = %lf feet\n", meters, feet);
    printf("%lf feet = %lf meters\n", feet, meters);
    printf("%lf kilograms = %lf pounds\n", kilograms, pounds);
    printf("%lf pounds = %lf kilograms\n", pounds, kilograms);
    printf("%lf Celsius = %lf Fahrenheit\n", celsius, fahrenheit);
    printf("%lf Fahrenheit = %lf Celsius\n", fahrenheit, celsius);

    return 0;
}