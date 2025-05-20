//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: expert-level
/*
 * Temperature Converter
 *
 * Converts a temperature from one scale to another.
 *
 * Usage:
 *  temperature_converter <scale> <value> <to_scale>
 *
 * where <scale> is the current temperature scale (C for Celsius, F for Fahrenheit, K for Kelvin)
 * and <value> is the temperature value
 * and <to_scale> is the desired temperature scale
 *
 * Example:
 *  temperature_converter C 20 K
 *  temperature_converter F 70 C
 *  temperature_converter K 300 F
 */

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void convert_celsius_to_fahrenheit(double temperature);
void convert_celsius_to_kelvin(double temperature);
void convert_fahrenheit_to_celsius(double temperature);
void convert_fahrenheit_to_kelvin(double temperature);
void convert_kelvin_to_celsius(double temperature);
void convert_kelvin_to_fahrenheit(double temperature);

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is passed
    if (argc != 4) {
        printf("Usage: temperature_converter <scale> <value> <to_scale>\n");
        return 1;
    }

    // Get the current temperature scale and value
    char *scale = argv[1];
    double value = atof(argv[2]);

    // Get the desired temperature scale
    char *to_scale = argv[3];

    // Convert the temperature
    if (strcmp(scale, "C") == 0) {
        if (strcmp(to_scale, "F") == 0) {
            convert_celsius_to_fahrenheit(value);
        } else if (strcmp(to_scale, "K") == 0) {
            convert_celsius_to_kelvin(value);
        } else {
            printf("Invalid temperature scale\n");
            return 1;
        }
    } else if (strcmp(scale, "F") == 0) {
        if (strcmp(to_scale, "C") == 0) {
            convert_fahrenheit_to_celsius(value);
        } else if (strcmp(to_scale, "K") == 0) {
            convert_fahrenheit_to_kelvin(value);
        } else {
            printf("Invalid temperature scale\n");
            return 1;
        }
    } else if (strcmp(scale, "K") == 0) {
        if (strcmp(to_scale, "C") == 0) {
            convert_kelvin_to_celsius(value);
        } else if (strcmp(to_scale, "F") == 0) {
            convert_kelvin_to_fahrenheit(value);
        } else {
            printf("Invalid temperature scale\n");
            return 1;
        }
    } else {
        printf("Invalid temperature scale\n");
        return 1;
    }

    return 0;
}

// Function definitions
void convert_celsius_to_fahrenheit(double temperature) {
    double converted_temperature = (temperature * 9.0 / 5.0) + 32.0;
    printf("Temperature in Fahrenheit: %.2f\n", converted_temperature);
}

void convert_celsius_to_kelvin(double temperature) {
    double converted_temperature = temperature + 273.15;
    printf("Temperature in Kelvin: %.2f\n", converted_temperature);
}

void convert_fahrenheit_to_celsius(double temperature) {
    double converted_temperature = (temperature - 32.0) * 5.0 / 9.0;
    printf("Temperature in Celsius: %.2f\n", converted_temperature);
}

void convert_fahrenheit_to_kelvin(double temperature) {
    double converted_temperature = ((temperature - 32.0) * 5.0 / 9.0) + 273.15;
    printf("Temperature in Kelvin: %.2f\n", converted_temperature);
}

void convert_kelvin_to_celsius(double temperature) {
    double converted_temperature = temperature - 273.15;
    printf("Temperature in Celsius: %.2f\n", converted_temperature);
}

void convert_kelvin_to_fahrenheit(double temperature) {
    double converted_temperature = (temperature - 273.15) * 9.0 / 5.0 + 32.0;
    printf("Temperature in Fahrenheit: %.2f\n", converted_temperature);
}