//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Function to convert temperature from Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to print a happy message based on the temperature
void print_happy_message(float temperature, char *unit) {
    if (temperature < 10) {
        printf("Brrr, it's a bit chilly out there! Stay warm and cozy inside!\n");
    } else if (temperature < 20) {
        printf("The weather is perfect for a nice walk or a cup of hot cocoa!\n");
    } else if (temperature < 30) {
        printf("It's a beautiful day to be outside! Enjoy the sunshine and have some fun!\n");
    } else if (temperature < 40) {
        printf("The sun is shining and the birds are singing! It's a great day to be alive!\n");
    } else {
        printf("Wow, it's a scorcher out there! Stay hydrated and find some shade!\n");
    }

    printf("Temperature: %.1f %s\n", temperature, unit);
}

// Main function
int main() {
    // Get the temperature from the user
    printf("Enter the temperature: ");
    float temperature;
    scanf("%f", &temperature);

    // Get the unit from the user
    printf("Enter the unit (C or F): ");
    char unit;
    scanf(" %c", &unit);

    // Convert the temperature to the other unit
    if (unit == 'C') {
        temperature = celsius_to_fahrenheit(temperature);
        unit = 'F';
    } else if (unit == 'F') {
        temperature = fahrenheit_to_celsius(temperature);
        unit = 'C';
    } else {
        printf("Invalid unit! Please enter C or F.\n");
        return -1;
    }

    // Print a happy message based on the temperature
    print_happy_message(temperature, unit);

    return 0;
}