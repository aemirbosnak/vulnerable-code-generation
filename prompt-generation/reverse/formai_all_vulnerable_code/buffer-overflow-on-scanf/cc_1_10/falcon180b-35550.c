//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>

// Function to convert length from meters to feet
float metersToFeet(float meters) {
    return meters * 3.28084;
}

// Function to convert weight from kilograms to pounds
float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

// Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert volume from liters to gallons
float litersToGallons(float liters) {
    return liters * 0.264172;
}

int main() {
    float meters, feet, kilograms, pounds, celsius, fahrenheit, liters, gallons;

    // Get user input for length in meters
    printf("Enter length in meters: ");
    scanf("%f", &meters);

    // Convert length from meters to feet and display result
    feet = metersToFeet(meters);
    printf("%.2f meters is %.2f feet.\n", meters, feet);

    // Get user input for weight in kilograms
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);

    // Convert weight from kilograms to pounds and display result
    pounds = kilogramsToPounds(kilograms);
    printf("%.2f kilograms is %.2f pounds.\n", kilograms, pounds);

    // Get user input for temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert temperature from Celsius to Fahrenheit and display result
    fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2f Celsius is %.2f Fahrenheit.\n", celsius, fahrenheit);

    // Get user input for volume in liters
    printf("Enter volume in liters: ");
    scanf("%f", &liters);

    // Convert volume from liters to gallons and display result
    gallons = litersToGallons(liters);
    printf("%.2f liters is %.2f gallons.\n", liters, gallons);

    return 0;
}