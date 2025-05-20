//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the units to convert from and to
#define UNITS \
    "Celsius to Fahrenheit, Fahrenheit to Celsius, " \
    "Miles to Kilometers, Kilometers to Miles, " \
    "Pounds to Kilograms, Kilograms to Pounds"

// Define the conversion factors
#define CONVERSION_FACTORS \
    "5/9, 32/98, 1.609344, 0.621371, " \
    "0.453592, 2.204623"

// Define the function prototypes
void convert_celsius_to_fahrenheit(float celsius);
void convert_fahrenheit_to_celsius(float fahrenheit);
void convert_miles_to_kilometers(float miles);
void convert_kilometers_to_miles(float kilometers);
void convert_pounds_to_kilograms(float pounds);
void convert_kilograms_to_pounds(float kilograms);

int main() {
    // Get the user's input
    float input;
    printf("Enter a value: ");
    scanf("%f", &input);

    // Prompt the user for the desired unit
    char unit[20];
    printf("Enter the unit (C/F, M/K, P/K): ");
    fgets(unit, 20, stdin);

    // Convert the input value to the desired unit
    if (strcmp(unit, "C") == 0) {
        convert_celsius_to_fahrenheit(input);
    } else if (strcmp(unit, "F") == 0) {
        convert_fahrenheit_to_celsius(input);
    } else if (strcmp(unit, "M") == 0) {
        convert_miles_to_kilometers(input);
    } else if (strcmp(unit, "K") == 0) {
        convert_kilometers_to_miles(input);
    } else if (strcmp(unit, "P") == 0) {
        convert_pounds_to_kilograms(input);
    } else if (strcmp(unit, "KG") == 0) {
        convert_kilograms_to_pounds(input);
    } else {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    // Print the result
    printf("Result: %f\n", input);

    return 0;
}

// Function to convert Celsius to Fahrenheit
void convert_celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    printf("Celsius: %f, Fahrenheit: %f\n", celsius, fahrenheit);
}

// Function to convert Fahrenheit to Celsius
void convert_fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    printf("Fahrenheit: %f, Celsius: %f\n", fahrenheit, celsius);
}

// Function to convert Miles to Kilometers
void convert_miles_to_kilometers(float miles) {
    float kilometers = miles * 1.609344;
    printf("Miles: %f, Kilometers: %f\n", miles, kilometers);
}

// Function to convert Kilometers to Miles
void convert_kilometers_to_miles(float kilometers) {
    float miles = kilometers / 1.609344;
    printf("Kilometers: %f, Miles: %f\n", kilometers, miles);
}

// Function to convert Pounds to Kilograms
void convert_pounds_to_kilograms(float pounds) {
    float kilograms = pounds / 2.204623;
    printf("Pounds: %f, Kilograms: %f\n", pounds, kilograms);
}

// Function to convert Kilograms to Pounds
void convert_kilograms_to_pounds(float kilograms) {
    float pounds = kilograms * 2.204623;
    printf("Kilograms: %f, Pounds: %f\n", kilograms, pounds);
}