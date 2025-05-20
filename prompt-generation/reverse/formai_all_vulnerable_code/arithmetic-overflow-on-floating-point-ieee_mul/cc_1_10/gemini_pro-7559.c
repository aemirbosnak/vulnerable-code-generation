//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the conversion formulas
#define C_TO_F(celsius) (celsius * 9 / 5) + 32
#define F_TO_C(fahrenheit) (fahrenheit - 32) * 5 / 9

// Define the temperature units
typedef enum {
    CELSIUS,
    FAHRENHEIT
} temperature_unit;

// Define the configuration struct
typedef struct {
    temperature_unit input_unit;
    temperature_unit output_unit;
    double input_temperature;
} configuration;

// Get the user input
configuration get_input() {
    configuration config;

    // Get the input unit
    printf("Enter the input unit (C/F): ");
    char input_unit;
    scanf(" %c", &input_unit);
    if (input_unit == 'C') {
        config.input_unit = CELSIUS;
    } else if (input_unit == 'F') {
        config.input_unit = FAHRENHEIT;
    } else {
        printf("Invalid input unit\n");
        exit(1);
    }

    // Get the output unit
    printf("Enter the output unit (C/F): ");
    char output_unit;
    scanf(" %c", &output_unit);
    if (output_unit == 'C') {
        config.output_unit = CELSIUS;
    } else if (output_unit == 'F') {
        config.output_unit = FAHRENHEIT;
    } else {
        printf("Invalid output unit\n");
        exit(1);
    }

    // Get the input temperature
    printf("Enter the input temperature: ");
    scanf(" %lf", &config.input_temperature);

    return config;
}

// Convert the temperature
double convert_temperature(configuration config) {
    if (config.input_unit == CELSIUS && config.output_unit == FAHRENHEIT) {
        return C_TO_F(config.input_temperature);
    } else if (config.input_unit == FAHRENHEIT && config.output_unit == CELSIUS) {
        return F_TO_C(config.input_temperature);
    } else {
        printf("Invalid conversion\n");
        exit(1);
    }
}

// Print the result
void print_result(double temperature, temperature_unit unit) {
    if (unit == CELSIUS) {
        printf("The temperature in Celsius is: %.2f\n", temperature);
    } else if (unit == FAHRENHEIT) {
        printf("The temperature in Fahrenheit is: %.2f\n", temperature);
    }
}

// Main function
int main() {
    // Get the user input
    configuration config = get_input();

    // Convert the temperature
    double temperature = convert_temperature(config);

    // Print the result
    print_result(temperature, config.output_unit);

    return 0;
}