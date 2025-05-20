//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    METERS,
    KILOMETERS,
    MILES,
    FEET,
    INCHES,
    CENTIMETERS,
    MILLIMETERS,
    YARDS,
    UNIT_COUNT
} UnitType;

const char *unitNames[UNIT_COUNT] = {
    "Meters", 
    "Kilometers", 
    "Miles", 
    "Feet", 
    "Inches", 
    "Centimeters", 
    "Millimeters", 
    "Yards"
};

double conversionFactors[UNIT_COUNT][UNIT_COUNT] = {
    {1, 0.001, 0.000621371, 3.28084, 39.3701, 100, 1000, 1.09361},    // Meters
    {1000, 1, 0.621371, 3280.84, 39370.1, 100000, 1000000, 1094},    // Kilometers
    {1609.34, 1.60934, 1, 5280, 63360, 160934, 1609340, 1760},       // Miles
    {0.3048, 0.0003048, 0.000189394, 1, 12, 30.48, 304.8, 0.333333}, // Feet
    {0.0254, 0.0000254, 0.0000157828, 0.0833333, 1, 2.54, 25.4, 0.0277778}, // Inches
    {0.01, 0.00001, 0.00000621371, 0.0328084, 0.393701, 1, 10, 0.01}, // Centimeters
    {0.001, 0.000001, 0.000000621371, 0.000328084, 0.0393701, 0.1, 1, 0.000001}, // Millimeters
    {0.9144, 0.0009144, 0.000568182, 3, 36, 91.44, 914.4, 1}        // Yards
};

void displayUnits() {
    printf("Available Units of Length:\n");
    for (int i = 0; i < UNIT_COUNT; i++) {
        printf("%d: %s\n", i + 1, unitNames[i]);
    }
}

double convert(double value, UnitType from, UnitType to) {
    return value * conversionFactors[from][to];
}

int main() {
    double value;
    int fromUnit, toUnit;

    printf("Welcome to the Length Unit Converter!\n");
    
    while (1) {
        displayUnits();
        
        printf("Enter the unit number to convert from (0 to exit): ");
        scanf("%d", &fromUnit);
        if (fromUnit == 0) break;
        fromUnit--; // Adjusting for zero-index

        if (fromUnit < 0 || fromUnit >= UNIT_COUNT) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        printf("Enter the unit number to convert to: ");
        scanf("%d", &toUnit);
        toUnit--; // Adjusting for zero-index
        
        if (toUnit < 0 || toUnit >= UNIT_COUNT) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        printf("Enter the value to convert: ");
        scanf("%lf", &value);

        double convertedValue = convert(value, fromUnit, toUnit);
        printf("%.2f %s is equivalent to %.2f %s\n", value, unitNames[fromUnit], convertedValue, unitNames[toUnit]);
    }

    printf("Thank you for using the Length Unit Converter. Goodbye!\n");
    return 0;
}