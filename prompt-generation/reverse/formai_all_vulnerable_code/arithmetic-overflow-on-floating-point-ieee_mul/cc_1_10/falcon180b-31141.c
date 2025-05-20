//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Function to convert Celsius to Fahrenheit */
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

/* Function to convert Fahrenheit to Celsius */
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    int choice;
    double temperature;
    char unit;

    /* Initialize variables */
    temperature = 0;
    unit = 'C';

    /* Loop until user wants to quit */
    while (1) {
        printf("Enter temperature (e.g. 25.5C): ");
        scanf("%lf%c", &temperature, &unit);

        /* Convert temperature to Celsius */
        if (unit == 'F') {
            temperature = celsius_to_fahrenheit(temperature);
            unit = 'C';
        }

        /* Display temperature */
        printf("Temperature: %.2lf%c\n", temperature, unit);

        /* Convert temperature to Fahrenheit */
        if (unit == 'C') {
            temperature = fahrenheit_to_celsius(temperature);
            unit = 'F';
        }

        /* Display temperature */
        printf("Temperature: %.2lf%c\n", temperature, unit);

        /* Ask user if they want to continue */
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);

        /* Exit loop if user wants to quit */
        if (choice == 'N' || choice == 'n') {
            break;
        }
    }

    return 0;
}