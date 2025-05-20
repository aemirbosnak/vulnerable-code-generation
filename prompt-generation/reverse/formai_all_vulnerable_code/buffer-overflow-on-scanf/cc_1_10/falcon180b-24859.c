//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

// Function to convert length from meters to feet
double metersToFeet(double meters) {
    double feet = meters * 3.28084;
    return feet;
}

// Function to convert length from feet to meters
double feetToMeters(double feet) {
    double meters = feet / 3.28084;
    return meters;
}

// Function to convert weight from kilograms to pounds
double kgToPounds(double kg) {
    double pounds = kg * 2.20462;
    return pounds;
}

// Function to convert weight from pounds to kilograms
double poundsToKg(double pounds) {
    double kg = pounds / 2.20462;
    return kg;
}

// Function to convert temperature from Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9.0) / 5.0 + 32;
    return fahrenheit;
}

// Function to convert temperature from Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5.0 / 9.0;
    return celsius;
}

int main() {
    double length, weight, temperature;
    char choice;

    // Prompt user for input
    printf("Enter 'L' for length conversion, 'W' for weight conversion, or 'T' for temperature conversion:\n");
    scanf("%c", &choice);

    // Perform conversion based on user input
    switch (choice) {
        case 'L':
            printf("Enter length in meters:\n");
            scanf("%lf", &length);
            printf("%.2lf meters is equal to %.2lf feet.\n", length, metersToFeet(length));
            break;
        case 'W':
            printf("Enter weight in kilograms:\n");
            scanf("%lf", &weight);
            printf("%.2lf kilograms is equal to %.2lf pounds.\n", weight, kgToPounds(weight));
            break;
        case 'T':
            printf("Enter temperature in Celsius:\n");
            scanf("%lf", &temperature);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, celsiusToFahrenheit(temperature));
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}