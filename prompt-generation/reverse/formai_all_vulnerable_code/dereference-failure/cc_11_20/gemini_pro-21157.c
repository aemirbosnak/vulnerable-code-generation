//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize the unit conversion table.
    typedef enum {
        CELSIUS_TO_FAHRENHEIT = 101,
        FAHRENHEIT_TO_CELSIUS = 102,
        METERS_TO_FEET = 201,
        FEET_TO_METERS = 202,
        POUNDS_TO_KILOGRAMS = 301,
        KILOGRAMS_TO_POUNDS = 302
    } UnitConversion;

    static const double unitConversions[] = {
        // Temperature conversions.
        [CELSIUS_TO_FAHRENHEIT] = 32.0,  // Celsius to Fahrenheit
        [FAHRENHEIT_TO_CELSIUS] = 1.8,  // Fahrenheit to Celsius

        // Length conversions.
        [METERS_TO_FEET] = 3.28084,  // Meters to feet
        [FEET_TO_METERS] = 0.3048,  // Feet to meters

        // Weight conversions.
        [POUNDS_TO_KILOGRAMS] = 2.20462,  // Pounds to kilograms
        [KILOGRAMS_TO_POUNDS] = 0.453592,  // Kilograms to pounds
    };

    // Get the user's input.
    printf("Enter the unit conversion you want to perform (e.g. \"Celsius to Fahrenheit\"): ");
    char input[100];
    fgets(input, sizeof(input), stdin);

    // Parse the user's input.
    char *fromUnit = strtok(input, " ");
    char *toUnit = strtok(NULL, " ");

    // Look up the conversion factor in the unit conversion table.
    double conversionFactor;
    int conversionType = -1;
    for (int i = 0; i < sizeof(unitConversions) / sizeof(unitConversions[0]); i++) {
        if (strcmp(fromUnit, "Celsius") == 0 && strcmp(toUnit, "Fahrenheit") == 0) {
            conversionType = CELSIUS_TO_FAHRENHEIT;
        } else if (strcmp(fromUnit, "Fahrenheit") == 0 && strcmp(toUnit, "Celsius") == 0) {
            conversionType = FAHRENHEIT_TO_CELSIUS;
        } else if (strcmp(fromUnit, "Meters") == 0 && strcmp(toUnit, "Feet") == 0) {
            conversionType = METERS_TO_FEET;
        } else if (strcmp(fromUnit, "Feet") == 0 && strcmp(toUnit, "Meters") == 0) {
            conversionType = FEET_TO_METERS;
        } else if (strcmp(fromUnit, "Pounds") == 0 && strcmp(toUnit, "Kilograms") == 0) {
            conversionType = POUNDS_TO_KILOGRAMS;
        } else if (strcmp(fromUnit, "Kilograms") == 0 && strcmp(toUnit, "Pounds") == 0) {
            conversionType = KILOGRAMS_TO_POUNDS;
        }

        if (conversionType != -1) {
            conversionFactor = unitConversions[conversionType];
            break;
        }
    }

    // If the conversion type is not found, print an error message.
    if (conversionType == -1) {
        printf("Invalid unit conversion specified.\n");
        return EXIT_FAILURE;
    }

    // Get the value to be converted.
    printf("Enter the value to be converted: ");
    double value;
    scanf("%lf", &value);

    // Convert the value.
    double convertedValue = value * conversionFactor;

    // Print the converted value.
    printf("%lf %s is equal to %lf %s.\n", value, fromUnit, convertedValue, toUnit);

    return EXIT_SUCCESS;
}