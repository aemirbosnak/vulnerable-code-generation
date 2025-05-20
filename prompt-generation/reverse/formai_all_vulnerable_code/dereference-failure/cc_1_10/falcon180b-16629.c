//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Function to validate user input as a temperature value
bool is_valid_temperature(const char *input) {
    int len = strlen(input);
    if (len == 0) {
        return false;
    }
    char *endptr = NULL;
    double temperature = strtod(input, &endptr);
    if (temperature == HUGE_VAL || temperature == -HUGE_VAL) {
        return false;
    }
    if (*endptr!= '\0') {
        return false;
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

// Function to print the usage instructions
void print_usage() {
    printf("Usage:./temperature_converter [Celsius or Fahrenheit] [Temperature]\n");
    printf("Example:./temperature_converter Celsius 100\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }

    // Get the temperature scale and input temperature from command line arguments
    char *scale = argv[1];
    char *input = argv[3];

    // Validate the input temperature
    if (!is_valid_temperature(input)) {
        printf("Invalid temperature value.\n");
        return 1;
    }

    // Convert the temperature based on the given scale
    if (strcmp(scale, "Celsius") == 0) {
        double fahrenheit = celsius_to_fahrenheit(strtod(input, NULL));
        printf("%.1f Celsius is %.1f Fahrenheit.\n", strtod(input, NULL), fahrenheit);
    } else if (strcmp(scale, "Fahrenheit") == 0) {
        double celsius = fahrenheit_to_celsius(strtod(input, NULL));
        printf("%.1f Fahrenheit is %.1f Celsius.\n", strtod(input, NULL), celsius);
    } else {
        printf("Invalid temperature scale.\n");
        return 1;
    }

    return 0;
}