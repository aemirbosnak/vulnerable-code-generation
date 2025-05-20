//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
#include <stdio.h>

// Constants
#define FAHRENHEIT_MIN  -459.67
#define FAHRENHEIT_MAX  5726.85
#define CELSIUS_MIN     -273.15
#define CELSIUS_MAX     5126.85

// Type definitions
typedef enum {
    FAHRENHEIT,
    CELSIUS
} TemperatureUnit;

// Function prototypes
double convert_temperature(double temperature, TemperatureUnit from_unit, TemperatureUnit to_unit);
void print_temperature(double temperature, TemperatureUnit unit);

// Main function
int main() {
    // Declare variables
    double temperature;
    TemperatureUnit from_unit, to_unit;

    // Get the input temperature
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);

    // Get the from unit
    printf("Enter the from unit (Fahrenheit or Celsius): ");
    char unit_string[10];
    scanf("%s", unit_string);
    if (strcmp(unit_string, "Fahrenheit") == 0) {
        from_unit = FAHRENHEIT;
    } else if (strcmp(unit_string, "Celsius") == 0) {
        from_unit = CELSIUS;
    } else {
        printf("Invalid unit: %s\n", unit_string);
        return 1;
    }

    // Get the to unit
    printf("Enter the to unit (Fahrenheit or Celsius): ");
    scanf("%s", unit_string);
    if (strcmp(unit_string, "Fahrenheit") == 0) {
        to_unit = FAHRENHEIT;
    } else if (strcmp(unit_string, "Celsius") == 0) {
        to_unit = CELSIUS;
    } else {
        printf("Invalid unit: %s\n", unit_string);
        return 1;
    }

    // Convert the temperature
    double converted_temperature = convert_temperature(temperature, from_unit, to_unit);

    // Print the converted temperature
    print_temperature(converted_temperature, to_unit);

    return 0;
}

// Function to convert the temperature
double convert_temperature(double temperature, TemperatureUnit from_unit, TemperatureUnit to_unit) {
    // Check if the temperature is within the valid range
    if (from_unit == FAHRENHEIT) {
        if (temperature < FAHRENHEIT_MIN || temperature > FAHRENHEIT_MAX) {
            printf("Invalid temperature: %f\n", temperature);
            return 0.0;
        }
    } else if (from_unit == CELSIUS) {
        if (temperature < CELSIUS_MIN || temperature > CELSIUS_MAX) {
            printf("Invalid temperature: %f\n", temperature);
            return 0.0;
        }
    }

    // Convert the temperature
    if (from_unit == FAHRENHEIT && to_unit == CELSIUS) {
        return (temperature - 32) * 5 / 9;
    } else if (from_unit == CELSIUS && to_unit == FAHRENHEIT) {
        return (temperature * 9 / 5) + 32;
    } else {
        return temperature;
    }
}

// Function to print the temperature
void print_temperature(double temperature, TemperatureUnit unit) {
    // Print the temperature
    printf("The temperature is: %.2f ", temperature);

    // Print the unit
    if (unit == FAHRENHEIT) {
        printf("Fahrenheit\n");
    } else if (unit == CELSIUS) {
        printf("Celsius\n");
    }
}