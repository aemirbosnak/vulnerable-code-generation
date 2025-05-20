//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to get current temperature in Celsius
double getCurrentTemperatureCelsius() {
    FILE *fp;
    char line[50];
    double temperature;

    fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (fp == NULL) {
        printf("Error reading temperature\n");
        exit(1);
    }

    fgets(line, sizeof(line), fp);
    temperature = atof(line);
    fclose(fp);

    return temperature;
}

// Function to get current temperature in Fahrenheit
double getCurrentTemperatureFahrenheit() {
    double celsius = getCurrentTemperatureCelsius();
    return celsiusToFahrenheit(celsius);
}

// Function to print temperature in Celsius and Fahrenheit
void printTemperature(double celsius, double fahrenheit) {
    printf("Current temperature: %.2f°C / %.2f°F\n", celsius, fahrenheit);
}

int main() {
    // Get current temperature in Celsius and Fahrenheit
    double celsius = getCurrentTemperatureCelsius();
    double fahrenheit = getCurrentTemperatureFahrenheit();

    // Print temperature in Celsius and Fahrenheit
    printTemperature(celsius, fahrenheit);

    return 0;
}