//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    double temperature, converted_temperature;
    char input_unit, output_unit;
    bool valid_input = true;

    // Prompt user for temperature and units
    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    printf("Enter input unit (C or F): ");
    scanf(" %c", &input_unit);

    if (input_unit!= 'C' && input_unit!= 'F') {
        printf("Invalid input unit. Please enter C or F.\n");
        valid_input = false;
    }

    if (valid_input) {
        printf("Enter output unit (C or F): ");
        scanf(" %c", &output_unit);

        // Convert temperature
        if (output_unit == 'C' && input_unit == 'F') {
            converted_temperature = celsius_to_fahrenheit(temperature);
        } else if (output_unit == 'F' && input_unit == 'C') {
            converted_temperature = fahrenheit_to_celsius(temperature);
        } else {
            converted_temperature = temperature;
        }

        // Print result
        printf("%.2lf %c = %.2lf %c\n", temperature, input_unit, converted_temperature, output_unit);
    }

    return 0;
}