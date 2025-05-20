//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>

// Helper function to validate user input
bool is_valid_input(const char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to convert Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Kelvin
double fahrenheit_to_kelvin(double fahrenheit) {
    return (celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit)));
}

// Function to convert Kelvin to Celsius
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
double kelvin_to_fahrenheit(double kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Function to get user input for temperature conversion
double get_user_input(const char* prompt) {
    double input;
    printf("%s", prompt);
    if (scanf("%lf", &input)!= 1 ||!is_valid_input(prompt)) {
        printf("Invalid input. Please enter a valid temperature.\n");
        exit(1);
    }
    return input;
}

// Function to print temperature conversion result
void print_result(double input, double result, const char* unit) {
    printf("%.2lf %s = %.2lf %s\n", input, unit, result, unit);
}

int main() {
    srand(time(NULL));
    int choice = rand() % 6;

    double input;
    switch (choice) {
        case 0:
            input = get_user_input("Enter temperature in Celsius: ");
            print_result(input, celsius_to_fahrenheit(input), "Fahrenheit");
            break;
        case 1:
            input = get_user_input("Enter temperature in Fahrenheit: ");
            print_result(input, fahrenheit_to_celsius(input), "Celsius");
            break;
        case 2:
            input = get_user_input("Enter temperature in Celsius: ");
            print_result(input, celsius_to_kelvin(input), "Kelvin");
            break;
        case 3:
            input = get_user_input("Enter temperature in Fahrenheit: ");
            print_result(input, fahrenheit_to_kelvin(input), "Kelvin");
            break;
        case 4:
            input = get_user_input("Enter temperature in Kelvin: ");
            print_result(input, kelvin_to_celsius(input), "Celsius");
            break;
        case 5:
            input = get_user_input("Enter temperature in Kelvin: ");
            print_result(input, kelvin_to_fahrenheit(input), "Fahrenheit");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return 1;
    }

    return 0;
}