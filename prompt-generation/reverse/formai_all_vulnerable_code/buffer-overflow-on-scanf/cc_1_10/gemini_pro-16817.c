//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // Array of conversion factors
    double conversionFactors[] = {
        1.0,          // Meters to meters
        0.3048,       // Meters to feet
        0.9144,       // Meters to yards
        1609.34,      // Meters to miles
        0.0254,       // Inches to meters
        2.54,         // Centimeters to inches
        0.453592,     // Kilograms to pounds
        0.000980665,  // Atomic mass units to kilograms
        3.78541,      // Liters to gallons
        0.264172,     // Gallons to liters
        0.0283168,    // Ounces to kilograms
        35.274,       // Ounces to grams
        1.0,          // Celsius to Celsius
        1.8,          // Celsius to Fahrenheit
        0.555556,     // Fahrenheit to Celsius
    };

    // Array of unit names
    char *unitNames[] = {
        "meters",
        "feet",
        "yards",
        "miles",
        "inches",
        "centimeters",
        "kilograms",
        "atomic mass units",
        "liters",
        "gallons",
        "ounces",
        "grams",
        "Celsius",
        "Fahrenheit",
        "Celsius",
    };

    // Get the input from the user
    printf("Enter the value to be converted: ");
    double value;
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    char unit[100];
    scanf("%s", unit);

    // Find the index of the unit in the array of unit names
    int unitIndex;
    for (unitIndex = 0; unitIndex < 15; unitIndex++) {
        if (strcmp(unit, unitNames[unitIndex]) == 0) {
            break;
        }
    }

    // Check if the unit is valid
    if (unitIndex == 15) {
        printf("Invalid unit. Please enter a valid unit.\n");
        return 1;
    }

    // Get the conversion factor for the unit
    double conversionFactor = conversionFactors[unitIndex];

    // Convert the value to the new unit
    double convertedValue = value * conversionFactor;

    // Print the converted value
    printf("The converted value is: %.2f %s\n", convertedValue, unitNames[unitIndex + 1]);

    return 0;
}