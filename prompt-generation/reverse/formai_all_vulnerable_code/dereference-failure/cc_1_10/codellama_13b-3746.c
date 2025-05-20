//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: statistical
// A unique C Unit converter example program in a statistical style
#include <stdio.h>
#include <stdlib.h>

// Define constants for the conversion factors
const float C_TO_F = 9.0 / 5.0;
const float F_TO_C = 5.0 / 9.0;
const float K_TO_C = 1.0;
const float C_TO_K = -273.15;

// Define a structure to hold the unit conversions
struct Unit {
    char name[10];
    float conversion;
};

// Define an array of Unit structures
struct Unit units[] = {
    {"Celsius", C_TO_F},
    {"Fahrenheit", F_TO_C},
    {"Kelvin", K_TO_C}
};

// Define a function to convert temperatures
void convert(char *input, char *output) {
    // Get the temperature from the input string
    float temp = atof(input);

    // Find the unit of measurement in the input string
    char *unit = strtok(input, " ");

    // Find the unit in the units array
    for (int i = 0; i < sizeof(units) / sizeof(struct Unit); i++) {
        if (strcmp(units[i].name, unit) == 0) {
            // Convert the temperature to the output unit
            float converted = temp * units[i].conversion;

            // Print the converted temperature
            printf("%f %s\n", converted, output);
            break;
        }
    }
}

int main() {
    // Prompt the user for a temperature and unit of measurement
    char input[100];
    printf("Enter a temperature and unit of measurement (e.g. 32 F): ");
    fgets(input, 100, stdin);

    // Convert the temperature to Celsius
    convert(input, "Celsius");

    // Convert the temperature to Fahrenheit
    convert(input, "Fahrenheit");

    // Convert the temperature to Kelvin
    convert(input, "Kelvin");

    return 0;
}