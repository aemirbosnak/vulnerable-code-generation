//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Declare constants for conversion rates
const float CELSIUS_TO_FAHRENHEIT_RATE = 1.8;
const float FAHRENHEIT_TO_CELSIUS_RATE = 0.5555555555555556;

// Declare function prototypes
float convertCelsiusToFahrenheit(float celsius);
float convertFahrenheitToCelsius(float fahrenheit);
void displayConversionResults(float convertedValue, char *unit);

// Main function
int main() {
    // Get the input temperature and unit from the user
    float temperature;
    char unit[10];
    printf("Enter the temperature: ");
    scanf("%f", &temperature);
    printf("Enter the unit (Celsius/Fahrenheit): ");
    scanf("%s", unit);

    // Check the entered unit
    bool isCelsius = strcmp(unit, "Celsius") == 0;
    bool isFahrenheit = strcmp(unit, "Fahrenheit") == 0;

    if (!isCelsius && !isFahrenheit) {
        printf("Invalid unit. Please enter either Celsius or Fahrenheit.\n");
        return 1;
    }

    // Convert the temperature to the desired unit
    float convertedValue;
    if (isCelsius) {
        convertedValue = convertCelsiusToFahrenheit(temperature);
    } else if (isFahrenheit) {
        convertedValue = convertFahrenheitToCelsius(temperature);
    }

    // Display the conversion results
    displayConversionResults(convertedValue, isCelsius ? "Fahrenheit" : "Celsius");

    return 0;
}

// Convert Celsius to Fahrenheit
float convertCelsiusToFahrenheit(float celsius) {
    return celsius * CELSIUS_TO_FAHRENHEIT_RATE + 32.0;
}

// Convert Fahrenheit to Celsius
float convertFahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * FAHRENHEIT_TO_CELSIUS_RATE;
}

// Display the conversion results
void displayConversionResults(float convertedValue, char *unit) {
    printf("Converted value: %.2f %s\n", convertedValue, unit);
}