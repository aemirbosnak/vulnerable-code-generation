//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to print the temperature in Celsius and Fahrenheit
void printTemperature(double temperature, char unit) {
    printf("%.2f %c\n", temperature, unit);
}

// Function to read the temperature from the user
double readTemperature() {
    char input[10];
    double temperature;

    printf("Enter the temperature: ");
    scanf("%s", input);

    // Check if the input is a valid number
    if (sscanf(input, "%lf", &temperature)!= 1) {
        printf("Invalid input. Please enter a valid temperature.\n");
        exit(1);
    }

    return temperature;
}

// Function to get the temperature unit from the user
char getTemperatureUnit() {
    char unit;

    printf("Enter the temperature unit (C or F): ");
    scanf(" %c", &unit);

    // Check if the input is a valid unit
    if (unit!= 'C' && unit!= 'F') {
        printf("Invalid unit. Please enter C or F.\n");
        exit(1);
    }

    return unit;
}

// Main function
int main() {
    double temperature;
    char unit;

    // Read the temperature and unit from the user
    temperature = readTemperature();
    unit = getTemperatureUnit();

    // Convert the temperature if necessary
    if (unit == 'F') {
        temperature = celsiusToFahrenheit(temperature);
        printTemperature(temperature, 'F');
    } else {
        temperature = fahrenheitToCelsius(temperature);
        printTemperature(temperature, 'C');
    }

    return 0;
}