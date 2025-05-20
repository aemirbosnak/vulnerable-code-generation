//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: shocked
// Holy smokes! Prepare for a mind-blowing unit conversion experience!

#include <stdio.h>
#include <stdlib.h>

// An array of units to convert from
const char *fromUnits[] = {"meters", "kilometers", "miles", "inches", "feet", "yards"};

// An array of units to convert to
const char *toUnits[] = {"meters", "kilometers", "miles", "inches", "feet", "yards"};

// A 2D array of conversion factors
const double conversionFactors[6][6] = {
    {1.0, 0.001, 0.000621371, 39.3701, 3.28084, 1.09361},
    {1000.0, 1.0, 0.621371, 39370.1, 3280.84, 1093.61},
    {1609.34, 1.60934, 1.0, 63360.0, 5280.0, 1760.0},
    {0.0254, 0.0000254, 0.000157828, 1.0, 0.0833333, 0.0277778},
    {0.3048, 0.0003048, 0.000189394, 12.0, 1.0, 0.333333},
    {0.9144, 0.0009144, 0.000568182, 36.0, 3.0, 1.0}
};

// Get the unit index from a string
int getUnitIndex(const char *unit) {
    for (int i = 0; i < 6; i++) {
        if (strcmp(unit, fromUnits[i]) == 0 || strcmp(unit, toUnits[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Print a conversion table
void printConversionTable() {
    printf("Conversion Table:\n");
    printf("%-10s", "");
    for (int i = 0; i < 6; i++) {
        printf("%-10s", toUnits[i]);
    }
    printf("\n");
    for (int i = 0; i < 6; i++) {
        printf("%-10s", fromUnits[i]);
        for (int j = 0; j < 6; j++) {
            printf("%-10.6f", conversionFactors[i][j]);
        }
        printf("\n");
    }
}

// Convert a value from one unit to another
double convertValue(double value, const char *fromUnit, const char *toUnit) {
    int fromIndex = getUnitIndex(fromUnit);
    int toIndex = getUnitIndex(toUnit);
    if (fromIndex == -1 || toIndex == -1) {
        printf("Invalid unit(s) specified.\n");
        return -1.0;
    }
    return value * conversionFactors[fromIndex][toIndex];
}

// Get user input
void getUserInput(double *value, char *fromUnit, char *toUnit) {
    printf("Enter the value to convert: ");
    scanf("%lf", value);
    printf("Enter the unit to convert from: ");
    scanf("%s", fromUnit);
    printf("Enter the unit to convert to: ");
    scanf("%s", toUnit);
}

// Print the converted value
void printConvertedValue(double value, const char *toUnit) {
    printf("Converted value: %.6f %s\n", value, toUnit);
}

// Main function
int main() {
    // Print a welcome message
    printf("Welcome to the Ultimate Unit Converter!\n");

    // Print the conversion table
    printConversionTable();

    // Get user input
    double value;
    char fromUnit[20];
    char toUnit[20];
    getUserInput(&value, fromUnit, toUnit);

    // Convert the value
    double convertedValue = convertValue(value, fromUnit, toUnit);

    // Print the converted value
    printConvertedValue(convertedValue, toUnit);

    return 0;
}