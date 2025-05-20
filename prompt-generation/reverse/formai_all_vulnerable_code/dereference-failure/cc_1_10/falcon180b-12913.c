//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

// Function prototypes
int get_temperature_unit(char *unit);
double convert_temperature(double temperature, int from_unit, int to_unit);

int main() {
    char input_line[MAX_LINE];
    char *token;
    int from_unit, to_unit;
    double temperature;

    // Prompt the user for the input
    printf("Enter the temperature to convert (e.g. 20 C to F): ");

    // Read the input
    if (fgets(input_line, MAX_LINE, stdin) == NULL) {
        printf("Error reading input.\n");
        exit(1);
    }

    // Parse the input
    token = strtok(input_line, " ");
    temperature = strtod(token, NULL);
    from_unit = get_temperature_unit(token);
    token = strtok(NULL, " ");
    to_unit = get_temperature_unit(token);

    // Convert the temperature
    temperature = convert_temperature(temperature, from_unit, to_unit);

    // Print the result
    printf("%.2f %c = %.2f %c\n", temperature, from_unit, temperature, to_unit);

    return 0;
}

// Function to get the temperature unit from a string
int get_temperature_unit(char *unit) {
    if (strcmp(unit, "C") == 0) {
        return 0;
    } else if (strcmp(unit, "F") == 0) {
        return 1;
    } else {
        return -1;
    }
}

// Function to convert temperature between Celsius and Fahrenheit
double convert_temperature(double temperature, int from_unit, int to_unit) {
    double result;

    if (from_unit == 0 && to_unit == 1) {
        // Celsius to Fahrenheit
        result = (temperature * 9.0 / 5.0) + 32;
    } else if (from_unit == 1 && to_unit == 0) {
        // Fahrenheit to Celsius
        result = (temperature - 32) * 5.0 / 9.0;
    } else {
        result = temperature;
    }

    return result;
}