//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_SIZE 100
#define MIN_TEMP -273.15

/* Function to check if a string is a number */
int is_number(const char *str) {
    int i = 0;
    while (str[i]) {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

/* Function to convert Celsius to Fahrenheit */
double celsius_to_fahrenheit(double c) {
    return (c * 1.8) + 32;
}

/* Function to convert Fahrenheit to Celsius */
double fahrenheit_to_celsius(double f) {
    return (f - 32) / 1.8;
}

/* Function to convert Kelvin to Celsius */
double kelvin_to_celsius(double k) {
    return k - 273.15;
}

/* Function to convert Celsius to Kelvin */
double celsius_to_kelvin(double c) {
    return c + 273.15;
}

int main() {
    char input[MAX_LINE_SIZE];
    double temperature;
    char unit[3];

    /* Prompt user for input */
    printf("Enter a temperature with its unit (e.g. 32C): ");
    fgets(input, MAX_LINE_SIZE, stdin);

    /* Extract temperature value and unit from input */
    sscanf(input, "%lf%s", &temperature, unit);

    /* Convert temperature to Celsius if not already in Celsius */
    if (strcmp(unit, "C")!= 0) {
        if (strcmp(unit, "F") == 0) {
            temperature = fahrenheit_to_celsius(temperature);
        } else if (strcmp(unit, "K") == 0) {
            temperature = kelvin_to_celsius(temperature);
        } else {
            printf("Invalid unit. Please enter temperature in Celsius (C), Fahrenheit (F), or Kelvin (K).\n");
            return 1;
        }
    }

    /* Convert Celsius to Fahrenheit and Kelvin */
    double fahrenheit = celsius_to_fahrenheit(temperature);
    double kelvin = celsius_to_kelvin(temperature);

    /* Output results */
    printf("%.2lfC is %.2lfF and %.2lfK\n", temperature, fahrenheit, kelvin);

    return 0;
}