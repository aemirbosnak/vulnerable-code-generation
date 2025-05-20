//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: configurable
/*
 * Temperature Converter
 *
 * This program converts between Celsius, Fahrenheit, and Kelvin.
 *
 * Usage:
 *      ./temperature_converter [-h] [-c <celsius>] [-f <fahrenheit>] [-k <kelvin>]
 *
 * Options:
 *      -h               Display this help message
 *      -c <celsius>     Convert to Celsius from Fahrenheit or Kelvin
 *      -f <fahrenheit>  Convert to Fahrenheit from Celsius or Kelvin
 *      -k <kelvin>      Convert to Kelvin from Celsius or Fahrenheit
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    bool celsius = false;
    bool fahrenheit = false;
    bool kelvin = false;
    double value;

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            printf("Usage: ./temperature_converter [-h] [-c <celsius>] [-f <fahrenheit>] [-k <kelvin>]\n");
            return 0;
        } else if (strcmp(argv[i], "-c") == 0) {
            celsius = true;
            value = atof(argv[++i]);
        } else if (strcmp(argv[i], "-f") == 0) {
            fahrenheit = true;
            value = atof(argv[++i]);
        } else if (strcmp(argv[i], "-k") == 0) {
            kelvin = true;
            value = atof(argv[++i]);
        } else {
            fprintf(stderr, "Error: Invalid option '%s'\n", argv[i]);
            return 1;
        }
    }

    // Convert temperature
    if (celsius) {
        printf("Celsius: %.2lf\n", value);
        printf("Fahrenheit: %.2lf\n", (value * 1.8) + 32);
        printf("Kelvin: %.2lf\n", value + 273.15);
    } else if (fahrenheit) {
        printf("Celsius: %.2lf\n", (value - 32) / 1.8);
        printf("Fahrenheit: %.2lf\n", value);
        printf("Kelvin: %.2lf\n", (value + 459.67) * (5.0 / 9.0));
    } else if (kelvin) {
        printf("Celsius: %.2lf\n", value - 273.15);
        printf("Fahrenheit: %.2lf\n", (value * (9.0 / 5.0)) - 459.67);
        printf("Kelvin: %.2lf\n", value);
    } else {
        printf("Error: No conversion specified\n");
        return 1;
    }

    return 0;
}