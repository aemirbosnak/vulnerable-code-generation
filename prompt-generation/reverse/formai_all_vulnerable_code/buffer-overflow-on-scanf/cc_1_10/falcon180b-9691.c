//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function to convert length from meters to feet
float metersToFeet(float meters) {
    float feet = meters * 3.28084;
    return feet;
}

// Function to convert length from feet to meters
float feetToMeters(float feet) {
    float meters = feet / 3.28084;
    return meters;
}

// Function to convert weight from kilograms to pounds
float kgToLbs(float kg) {
    float lbs = kg * 2.20462;
    return lbs;
}

// Function to convert weight from pounds to kilograms
float lbsToKg(float lbs) {
    float kg = lbs / 2.20462;
    return kg;
}

// Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = celsius * 1.8 + 32;
    return fahrenheit;
}

// Function to convert temperature from Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

int main() {
    float meters, feet;
    float kg, lbs;
    float celsius, fahrenheit;

    // Get user input for length in meters
    printf("Enter length in meters: ");
    scanf("%f", &meters);

    // Convert meters to feet
    feet = metersToFeet(meters);

    // Display the result
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);

    // Get user input for weight in kilograms
    printf("Enter weight in kilograms: ");
    scanf("%f", &kg);

    // Convert kilograms to pounds
    lbs = kgToLbs(kg);

    // Display the result
    printf("%.2f kilograms is equal to %.2f pounds.\n", kg, lbs);

    // Get user input for temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = celsiusToFahrenheit(celsius);

    // Display the result
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    // Get user input for temperature in Fahrenheit
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Convert Fahrenheit to Celsius
    celsius = fahrenheitToCelsius(fahrenheit);

    // Display the result
    printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);

    return 0;
}