//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert length from meters to feet
float metersToFeet(float meters) {
    return meters * 3.28084;
}

// Function to convert length from feet to meters
float feetToMeters(float feet) {
    return feet * 0.3048;
}

// Function to convert weight from kilograms to pounds
float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

// Function to convert weight from pounds to kilograms
float poundsToKilograms(float pounds) {
    return pounds * 0.453592;
}

// Function to convert volume from liters to gallons
float litersToGallons(float liters) {
    return liters * 0.264172;
}

// Function to convert volume from gallons to liters
float gallonsToLiters(float gallons) {
    return gallons * 3.78541;
}

int main() {
    float celsius, fahrenheit, meters, feet, kilograms, pounds, liters, gallons;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    printf("Temperature in Celsius is %.2f degrees Celsius.\n", celsius);
    printf("Temperature in Fahrenheit is %.2f degrees Fahrenheit.\n", celsiusToFahrenheit(celsius));

    printf("\nEnter length in meters: ");
    scanf("%f", &meters);

    // Convert meters to feet
    printf("Length in meters is %.2f meters.\n", meters);
    printf("Length in feet is %.2f feet.\n", metersToFeet(meters));

    printf("\nEnter weight in kilograms: ");
    scanf("%f", &kilograms);

    // Convert kilograms to pounds
    printf("Weight in kilograms is %.2f kilograms.\n", kilograms);
    printf("Weight in pounds is %.2f pounds.\n", kilogramsToPounds(kilograms));

    printf("\nEnter volume in liters: ");
    scanf("%f", &liters);

    // Convert liters to gallons
    printf("Volume in liters is %.2f liters.\n", liters);
    printf("Volume in gallons is %.2f gallons.\n", litersToGallons(liters));

    return 0;
}