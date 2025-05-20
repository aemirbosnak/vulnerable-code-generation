//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <math.h>

// Define a structure for unit conversions
typedef struct UnitConversion {
    char fromUnit;
    char toUnit;
    double conversionFactor;
} UnitConversion;

// Create an array of unit conversion factors
UnitConversion conversions[] = {
    {'m', 'km', 1000},
    {'g', 'kg', 1000},
    {'L', 'ml', 1000},
    {'s', 'min', 60},
    {'min', 'h', 60}
};

// Function to convert units
double convertUnits(char fromUnit, char toUnit, double value) {
    for (int i = 0; i < sizeof(conversions) / sizeof(UnitConversion); i++) {
        if (conversions[i].fromUnit == fromUnit && conversions[i].toUnit == toUnit) {
            return value * conversions[i].conversionFactor;
        }
    }

    return -1;
}

int main() {
    double value;
    char fromUnit;
    char toUnit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit: ");
    scanf("%c", &fromUnit);

    printf("Enter the to unit: ");
    scanf("%c", &toUnit);

    double convertedValue = convertUnits(fromUnit, toUnit, value);

    if (convertedValue != -1) {
        printf("The converted value is: %.2lf %s", convertedValue, toUnit);
    } else {
        printf("Error: Unit conversion not found.");
    }

    return 0;
}