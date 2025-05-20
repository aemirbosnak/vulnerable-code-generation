//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP 100

// Function to convert temperature from Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert temperature from Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert temperature from Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert temperature from Fahrenheit to Kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit + 459.67) * 5 / 9;
}

// Function to convert temperature from Kelvin to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin * 9 / 5) - 459.67;
}

// Function to convert temperature from Celsius to Rankine
float celsius_to_rankine(float celsius) {
    return celsius * 9 / 5;
}

// Function to convert temperature from Rankine to Celsius
float rankine_to_celsius(float rankine) {
    return rankine * 5 / 9;
}

// Function to convert temperature from Fahrenheit to Rankine
float fahrenheit_to_rankine(float fahrenheit) {
    return fahrenheit + 459.67;
}

// Function to convert temperature from Rankine to Fahrenheit
float rankine_to_fahrenheit(float rankine) {
    return rankine - 459.67;
}

// Function to convert temperature from Kelvin to Rankine
float kelvin_to_rankine(float kelvin) {
    return kelvin * 9 / 5;
}

// Function to convert temperature from Rankine to Kelvin
float rankine_to_kelvin(float rankine) {
    return rankine * 5 / 9;
}

// Main function to run the program
int main() {
    float celsius, fahrenheit, kelvin, rankine;

    // Get input from user
    printf("Enter a temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert temperature to Fahrenheit
    fahrenheit = celsius_to_fahrenheit(celsius);

    // Convert temperature to Kelvin
    kelvin = celsius_to_kelvin(celsius);

    // Convert temperature to Rankine
    rankine = celsius_to_rankine(celsius);

    // Print results
    printf("Temperature in Celsius: %.2f\n", celsius);
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    printf("Temperature in Kelvin: %.2f\n", kelvin);
    printf("Temperature in Rankine: %.2f\n", rankine);

    return 0;
}