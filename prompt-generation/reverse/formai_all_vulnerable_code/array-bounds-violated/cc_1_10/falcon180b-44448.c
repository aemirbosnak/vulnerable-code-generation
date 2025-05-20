//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    double (*convert)(double);
} conversion_t;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvin_to_fahrenheit(double kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

conversion_t conversions[] = {
    {"Celsius to Fahrenheit", celsius_to_fahrenheit},
    {"Celsius to Kelvin", celsius_to_kelvin},
    {"Fahrenheit to Celsius", fahrenheit_to_celsius},
    {"Fahrenheit to Kelvin", fahrenheit_to_kelvin},
    {"Kelvin to Celsius", kelvin_to_celsius},
    {"Kelvin to Fahrenheit", kelvin_to_fahrenheit}
};

int main() {
    int choice;
    double temperature, converted_temperature;
    char input[MAX_LEN];

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature you want to convert (e.g. 25 C): ");
    fgets(input, MAX_LEN, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Get the temperature and unit from user input
    sscanf(input, "%lf %c", &temperature, &choice);

    // Convert the temperature
    converted_temperature = (*conversions[choice].convert)(temperature);

    // Print the result
    printf("%.2lf %c = %.2lf %c\n", temperature, choice, converted_temperature, 'K');

    return 0;
}