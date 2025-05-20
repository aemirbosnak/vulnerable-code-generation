//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the conversion formulas
#define CELSIUS_TO_FAHRENHEIT(c) ((c * 9) / 5) + 32
#define FAHRENHEIT_TO_CELSIUS(f) ((f - 32) * 5) / 9

// Define the temperature unit enum
typedef enum {
    CELSIUS,
    FAHRENHEIT
} TemperatureUnit;

// Get the temperature unit from the user
TemperatureUnit getTemperatureUnit(void) {
    char unit;
    printf("Enter the temperature unit (C/F): ");
    scanf(" %c", &unit);
    if (unit == 'C') {
        return CELSIUS;
    } else if (unit == 'F') {
        return FAHRENHEIT;
    } else {
        printf("Invalid temperature unit. Please enter C or F.\n");
        exit(EXIT_FAILURE);
    }
}

// Get the temperature value from the user
double getTemperatureValue(TemperatureUnit unit) {
    double temperature;
    if (unit == CELSIUS) {
        printf("Enter the temperature in Celsius: ");
    } else {
        printf("Enter the temperature in Fahrenheit: ");
    }
    scanf(" %lf", &temperature);
    return temperature;
}

// Convert the temperature to the other unit
double convertTemperature(TemperatureUnit fromUnit, TemperatureUnit toUnit, double temperature) {
    if (fromUnit == CELSIUS && toUnit == FAHRENHEIT) {
        return CELSIUS_TO_FAHRENHEIT(temperature);
    } else if (fromUnit == FAHRENHEIT && toUnit == CELSIUS) {
        return FAHRENHEIT_TO_CELSIUS(temperature);
    } else {
        printf("Invalid temperature units. Please enter C or F for both units.\n");
        exit(EXIT_FAILURE);
    }
}

// Print the converted temperature
void printConvertedTemperature(TemperatureUnit toUnit, double temperature) {
    if (toUnit == CELSIUS) {
        printf("The temperature in Celsius is: %.2f\n", temperature);
    } else {
        printf("The temperature in Fahrenheit is: %.2f\n", temperature);
    }
}

// Main function
int main(void) {
    // Get the temperature unit from the user
    TemperatureUnit fromUnit = getTemperatureUnit();

    // Get the temperature value from the user
    double temperature = getTemperatureValue(fromUnit);

    // Convert the temperature to the other unit
    TemperatureUnit toUnit = (fromUnit == CELSIUS) ? FAHRENHEIT : CELSIUS;
    double convertedTemperature = convertTemperature(fromUnit, toUnit, temperature);

    // Print the converted temperature
    printConvertedTemperature(toUnit, convertedTemperature);

    return 0;
}