//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

/**
 * Function to convert Celsius to Fahrenheit
 * @param celsius Celsius temperature to convert
 * @return Fahrenheit temperature
 */
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

/**
 * Function to convert Fahrenheit to Celsius
 * @param fahrenheit Fahrenheit temperature to convert
 * @return Celsius temperature
 */
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    char input[MAX_LENGTH];
    double celsius, fahrenheit;

    // Prompt user for input
    printf("Enter temperature in Celsius or Fahrenheit: ");
    fgets(input, MAX_LENGTH, stdin);

    // Convert input string to temperature value
    if (sscanf(input, "%lf %s", &celsius, input) == 2) {
        // Celsius input
        if (strcmp(input, "C") == 0 || strcmp(input, "c") == 0) {
            // Convert Celsius to Fahrenheit
            fahrenheit = celsiusToFahrenheit(celsius);
            printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
        }
        else {
            // Invalid input
            printf("Invalid input. Please enter temperature in Celsius or Fahrenheit.\n");
        }
    }
    else if (sscanf(input, "%lf %s", &fahrenheit, input) == 2) {
        // Fahrenheit input
        if (strcmp(input, "F") == 0 || strcmp(input, "f") == 0) {
            // Convert Fahrenheit to Celsius
            celsius = fahrenheitToCelsius(fahrenheit);
            printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
        }
        else {
            // Invalid input
            printf("Invalid input. Please enter temperature in Celsius or Fahrenheit.\n");
        }
    }
    else {
        // Invalid input
        printf("Invalid input. Please enter temperature in Celsius or Fahrenheit.\n");
    }

    return 0;
}