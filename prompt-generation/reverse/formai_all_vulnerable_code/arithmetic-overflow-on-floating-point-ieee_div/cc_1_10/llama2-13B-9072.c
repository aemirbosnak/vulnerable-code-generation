//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the unit types and their symbols
typedef enum {
    UNIT_NONE = 0,
    UNIT_METRIC = 1,
    UNIT_IMPERIAL = 2,
    UNIT_ANGULAR = 3
} UnitType;

typedef struct {
    char *name;
    char *symbol;
    double factor;
} Unit;

// Define the available units
Unit units[] = {
    {"meter", "m", 1.0},
    {"kilometer", "km", 1000.0},
    {"centimeter", "cm", 0.01},
    {" millimeter", "mm", 0.001},
    {"foot", "ft", 0.3048},
    {"yard", "yd", 0.9144},
    {"mile", "mi", 1609.34},
    {"inch", "in", 0.0254},
    {"pound", "lb", 0.453592},
    {"ounce", "oz", 0.0283495},
    {"gram", "g", 0.001},
    {"kilogram", "kg", 1000.0}
};

// Define the number of units
#define NUM_UNITS (sizeof(units) / sizeof(units[0]))

// Define the function to convert between units
void convert(UnitType from, UnitType to, double value) {
    // Calculate the factor for the conversion
    double factor = units[to].factor / units[from].factor;

    // Perform the conversion
    value *= factor;

    // Print the result
    printf("%.2f %s = %.2f %s\n", value, units[from].symbol, value, units[to].symbol);
}

int main() {
    // Ask the user for the value and the from/to units
    double value;
    UnitType from, to;
    printf("Enter a value: ");
    scanf("%lf", &value);
    printf("Enter the from unit (m/km/cm/etc.): ");
    scanf("%d", &from);
    printf("Enter the to unit (m/km/cm/etc.): ");
    scanf("%d", &to);

    // Convert the value between the units
    convert(from, to, value);

    return 0;
}