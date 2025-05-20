//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to print a temperature conversion table
void print_temperature_conversion_table() {
    // Print the table header
    printf("%-10s%-10s%-10s\n", "Celsius", "Fahrenheit", "Difference");

    // Iterate through a range of Celsius temperatures
    for (float celsius = 0; celsius <= 100; celsius += 10) {
        // Convert the Celsius temperature to Fahrenheit
        float fahrenheit = celsius_to_fahrenheit(celsius);

        // Calculate the difference between the Celsius and Fahrenheit temperatures
        float difference = fahrenheit - celsius;

        // Print the temperature conversion data
        printf("%-10.1f%-10.1f%-10.1f\n", celsius, fahrenheit, difference);
    }
}

// Main function
int main() {
    // Print a welcome message
    printf("Welcome to the Temperature Converter!\n");

    // Print a temperature conversion table
    print_temperature_conversion_table();

    // Prompt the user to enter a Celsius temperature
    printf("\nEnter a Celsius temperature: ");
    float celsius;
    scanf("%f", &celsius);

    // Convert the Celsius temperature to Fahrenheit
    float fahrenheit = celsius_to_fahrenheit(celsius);

    // Print the converted Fahrenheit temperature
    printf("The Fahrenheit equivalent of %.1f degrees Celsius is %.1f degrees Fahrenheit.\n", celsius, fahrenheit);

    // Exit the program
    return 0;
}