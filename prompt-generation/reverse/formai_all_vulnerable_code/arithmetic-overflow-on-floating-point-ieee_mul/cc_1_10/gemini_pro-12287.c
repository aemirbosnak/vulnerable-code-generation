//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the temperature conversion formulas
#define CELSIUS_TO_FAHRENHEIT(c) ((c * 9) / 5) + 32
#define FAHRENHEIT_TO_CELSIUS(f) ((f - 32) * 5) / 9

// Define the temperature unit enum
typedef enum {
    CELSIUS,
    FAHRENHEIT
} temperature_unit;

// Get the temperature value from the user
double get_temperature_value(temperature_unit unit) {
    double temperature;

    printf("Enter the temperature value in %s: ", unit == CELSIUS ? "Celsius" : "Fahrenheit");
    scanf("%lf", &temperature);

    return temperature;
}

// Convert the temperature value to the specified unit
double convert_temperature(double temperature, temperature_unit from_unit, temperature_unit to_unit) {
    if (from_unit == CELSIUS && to_unit == FAHRENHEIT) {
        return CELSIUS_TO_FAHRENHEIT(temperature);
    } else if (from_unit == FAHRENHEIT && to_unit == CELSIUS) {
        return FAHRENHEIT_TO_CELSIUS(temperature);
    } else {
        printf("Invalid temperature conversion from %s to %s\n", from_unit == CELSIUS ? "Celsius" : "Fahrenheit", to_unit == CELSIUS ? "Celsius" : "Fahrenheit");
        exit(1);
    }
}

// Print the converted temperature value
void print_converted_temperature(double temperature, temperature_unit unit) {
    printf("The converted temperature value in %s is: %.2f\n", unit == CELSIUS ? "Celsius" : "Fahrenheit", temperature);
}

// Main function
int main() {
    // Get the temperature value from the user
    double temperature = get_temperature_value(CELSIUS);

    // Convert the temperature value to Fahrenheit
    double fahrenheit_temperature = convert_temperature(temperature, CELSIUS, FAHRENHEIT);

    // Print the converted temperature value
    print_converted_temperature(fahrenheit_temperature, FAHRENHEIT);

    return 0;
}