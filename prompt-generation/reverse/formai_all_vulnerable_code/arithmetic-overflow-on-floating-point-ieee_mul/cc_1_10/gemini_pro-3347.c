//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>

// Define the conversion formulas
#define CELSIUS_TO_FAHRENHEIT(celsius) ((celsius * 9 / 5) + 32)
#define FAHRENHEIT_TO_CELSIUS(fahrenheit) ((fahrenheit - 32) * 5 / 9)

// Define the input and output units
enum Unit {
    CELSIUS,
    FAHRENHEIT
};

// Get the input temperature and unit from the user
double get_input_temperature(void) {
    double temperature;
    char unit;

    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    printf("Enter the unit (C/F): ");
    scanf(" %c", &unit);

    // Convert the unit to lowercase
    unit = tolower(unit);

    // Return the temperature and unit
    return temperature;
}

// Convert the temperature to the output unit
double convert_temperature(double temperature, enum Unit input_unit, enum Unit output_unit) {
    // Convert the temperature to Celsius
    if (input_unit == FAHRENHEIT) {
        temperature = FAHRENHEIT_TO_CELSIUS(temperature);
    }

    // Convert the temperature to Fahrenheit
    if (output_unit == FAHRENHEIT) {
        temperature = CELSIUS_TO_FAHRENHEIT(temperature);
    }

    // Return the converted temperature
    return temperature;
}

// Print the converted temperature
void print_converted_temperature(double temperature, enum Unit output_unit) {
    // Print the temperature in the output unit
    if (output_unit == CELSIUS) {
        printf("The temperature in Celsius is: %.2lf\n", temperature);
    } else if (output_unit == FAHRENHEIT) {
        printf("The temperature in Fahrenheit is: %.2lf\n", temperature);
    }
}

// Main function
int main(void) {
    // Get the input temperature and unit
    double input_temperature = get_input_temperature();

    // Convert the temperature to Celsius
    double celsius_temperature = convert_temperature(input_temperature, CELSIUS, CELSIUS);

    // Convert the temperature to Fahrenheit
    double fahrenheit_temperature = convert_temperature(input_temperature, FAHRENHEIT, FAHRENHEIT);

    // Print the converted temperatures
    print_converted_temperature(celsius_temperature, CELSIUS);
    print_converted_temperature(fahrenheit_temperature, FAHRENHEIT);

    return 0;
}