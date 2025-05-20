//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>

// Function to convert meters to feet
float metersToFeet(float meters) {
    return meters * 3.28084;
}

// Function to convert kilometers to miles
float kilometersToMiles(float kilometers) {
    return kilometers * 0.621371;
}

// Function to convert liters to gallons
float litersToGallons(float liters) {
    return liters * 0.264172;
}

// Function to convert grams to ounces
float gramsToOunces(float grams) {
    return grams * 0.035274;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

int main() {
    float meters, feet, kilometers, miles, liters, gallons, grams, ounces, celsius, fahrenheit;

    // Get input from user
    printf("Enter the value to convert: ");
    scanf("%f", &meters);

    // Convert meters to feet
    feet = metersToFeet(meters);

    // Convert meters to kilometers
    kilometers = meters / 1000;

    // Convert kilometers to miles
    miles = kilometersToMiles(kilometers);

    // Convert liters to gallons
    liters = meters / 1000;
    gallons = litersToGallons(liters);

    // Convert grams to ounces
    grams = meters / 1000;
    ounces = gramsToOunces(grams);

    // Convert Celsius to Fahrenheit
    celsius = meters / 1000;
    fahrenheit = celsiusToFahrenheit(celsius);

    // Convert Fahrenheit to Celsius
    fahrenheit = meters / 1000;
    celsius = fahrenheitToCelsius(fahrenheit);

    // Print the results
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
    printf("%.2f meters is equal to %.2f kilometers.\n", meters, kilometers);
    printf("%.2f kilometers is equal to %.2f miles.\n", kilometers, miles);
    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);
    printf("%.2f grams is equal to %.2f ounces.\n", grams, ounces);
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    return 0;
}