//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Define the conversion formulas
#define CELSIUS_TO_FAHRENHEIT(c) ((c) * 9 / 5 + 32)
#define FAHRENHEIT_TO_CELSIUS(f) ((f) - 32) * 5 / 9

// Define the input and output units
enum UNIT { CELSIUS, FAHRENHEIT };

// Get the input temperature and unit
void get_input(double *temperature, enum UNIT *unit) {
    char input[100];
    printf("Enter the temperature and unit (e.g. 25C or 77F): ");
    scanf("%s", input);
    sscanf(input, "%lf%c", temperature, unit);
}

// Convert the temperature to the desired unit
double convert_temperature(double temperature, enum UNIT input_unit, enum UNIT output_unit) {
    if (input_unit == CELSIUS && output_unit == FAHRENHEIT) {
        return CELSIUS_TO_FAHRENHEIT(temperature);
    } else if (input_unit == FAHRENHEIT && output_unit == CELSIUS) {
        return FAHRENHEIT_TO_CELSIUS(temperature);
    } else {
        return temperature;
    }
}

// Print the converted temperature
void print_output(double temperature, enum UNIT unit) {
    if (unit == CELSIUS) {
        printf("%.2lf degrees Celsius\n", temperature);
    } else if (unit == FAHRENHEIT) {
        printf("%.2lf degrees Fahrenheit\n", temperature);
    }
}

// Main function
int main() {
    // Get the input temperature and unit
    double temperature;
    enum UNIT input_unit, output_unit;
    get_input(&temperature, &input_unit);

    // Convert the temperature to the desired unit
    output_unit = (input_unit == CELSIUS) ? FAHRENHEIT : CELSIUS;
    double converted_temperature = convert_temperature(temperature, input_unit, output_unit);

    // Print the converted temperature
    print_output(converted_temperature, output_unit);

    return 0;
}