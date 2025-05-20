//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define ERROR_MSG_LENGTH 80
#define ERROR_MSG "Invalid input. Please enter a valid temperature in the format <value> <unit>, where unit is C or F."

/* Function prototypes */
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double kelvin_to_celsius(double kelvin);
double celsius_to_kelvin(double celsius);

/* Function to convert Celsius to Fahrenheit */
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

/* Function to convert Fahrenheit to Celsius */
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

/* Function to convert Kelvin to Celsius */
double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

/* Function to convert Celsius to Kelvin */
double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

int main() {
    setlocale(LC_ALL, "");
    printf("Enter a temperature in the format <value> <unit>, where unit is C or F.\n");
    char input[ERROR_MSG_LENGTH];
    if (scanf("%s", input)!= 1) {
        printf(ERROR_MSG);
        return 1;
    }
    double value = strtod(input, NULL);
    char unit = input[strcspn(input, " ")] = '\0';
    if (unit!= 'C' && unit!= 'F') {
        printf(ERROR_MSG);
        return 1;
    }
    if (unit == 'C') {
        printf("%.2f C = %.2f F\n", value, celsius_to_fahrenheit(value));
    } else if (unit == 'F') {
        printf("%.2f F = %.2f C\n", value, fahrenheit_to_celsius(value));
    }
    return 0;
}