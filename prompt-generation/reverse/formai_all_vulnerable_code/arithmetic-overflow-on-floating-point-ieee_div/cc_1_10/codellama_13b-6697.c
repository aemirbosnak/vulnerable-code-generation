//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Function to convert temperature in Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert temperature in Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return celsius * 9 / 5 + 32;
}

// Function to convert distance in kilometers to miles
double kilometers_to_miles(double kilometers) {
    return kilometers * 0.621371;
}

// Function to convert distance in miles to kilometers
double miles_to_kilometers(double miles) {
    return miles / 0.621371;
}

int main() {
    double fahrenheit, celsius, kilometers, miles;

    // Prompt user for input
    printf("Enter a temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    printf("Enter a temperature in Celsius: ");
    scanf("%lf", &celsius);
    printf("Enter a distance in kilometers: ");
    scanf("%lf", &kilometers);
    printf("Enter a distance in miles: ");
    scanf("%lf", &miles);

    // Convert temperatures
    double celsius_converted = fahrenheit_to_celsius(fahrenheit);
    double fahrenheit_converted = celsius_to_fahrenheit(celsius);

    // Convert distances
    double kilometers_converted = miles_to_kilometers(miles);
    double miles_converted = kilometers_to_miles(kilometers);

    // Print results
    printf("Temperature in Celsius: %.2lf\n", celsius_converted);
    printf("Temperature in Fahrenheit: %.2lf\n", fahrenheit_converted);
    printf("Distance in kilometers: %.2lf\n", kilometers_converted);
    printf("Distance in miles: %.2lf\n", miles_converted);

    return 0;
}