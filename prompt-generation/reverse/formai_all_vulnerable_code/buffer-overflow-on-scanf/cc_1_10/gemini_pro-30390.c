//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the temperature scale options
#define CELSIUS 'C'
#define FAHRENHEIT 'F'
#define KELVIN 'K'

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

// Function to convert Kelvin to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

// Function to print the conversion results
void print_results(float value, char from_scale, char to_scale) {
    switch (from_scale) {
        case CELSIUS:
            printf("%.2f degrees Celsius is equal to: ", value);
            break;
        case FAHRENHEIT:
            printf("%.2f degrees Fahrenheit is equal to: ", value);
            break;
        case KELVIN:
            printf("%.2f degrees Kelvin is equal to: ", value);
            break;
    }
    switch (to_scale) {
        case CELSIUS:
            printf("%.2f degrees Celsius\n", value);
            break;
        case FAHRENHEIT:
            printf("%.2f degrees Fahrenheit\n", value);
            break;
        case KELVIN:
            printf("%.2f degrees Kelvin\n", value);
            break;
    }
}

// Function to get the user input
void get_user_input(float *value, char *from_scale, char *to_scale) {
    printf("Enter the temperature value: ");
    scanf("%f", value);
    printf("Enter the original temperature scale (C/F/K): ");
    scanf(" %c", from_scale);
    printf("Enter the target temperature scale (C/F/K): ");
    scanf(" %c", to_scale);
}

// Main function
int main() {
    float value;
    char from_scale, to_scale;

    // Get the user input
    get_user_input(&value, &from_scale, &to_scale);

    // Convert the temperature based on the user's input
    switch (from_scale) {
        case CELSIUS:
            switch (to_scale) {
                case FAHRENHEIT:
                    print_results(value, CELSIUS, FAHRENHEIT);
                    break;
                case KELVIN:
                    print_results(value, CELSIUS, KELVIN);
                    break;
            }
            break;
        case FAHRENHEIT:
            switch (to_scale) {
                case CELSIUS:
                    print_results(value, FAHRENHEIT, CELSIUS);
                    break;
                case KELVIN:
                    print_results(value, FAHRENHEIT, KELVIN);
                    break;
            }
            break;
        case KELVIN:
            switch (to_scale) {
                case CELSIUS:
                    print_results(value, KELVIN, CELSIUS);
                    break;
                case FAHRENHEIT:
                    print_results(value, KELVIN, FAHRENHEIT);
                    break;
            }
            break;
    }

    return 0;
}