//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a structure to hold unit information
typedef struct {
    char name[20];  // unit name (e.g. "meter", "foot", etc.)
    double conversion_factor;  // conversion factor from base unit to this unit
} Unit;

// Define a table of predefined units
Unit units[] = {
    {"meter", 1.0},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {" millimeter", 0.001},
    {"gram", 0.001},
    {"ounce", 0.0283168},
    {"pound", 0.453592},
    {"ton", 1000.0}
};

// Define a function to convert between units
double convert_unit(double value, Unit from_unit, Unit to_unit) {
    return value * from_unit.conversion_factor / to_unit.conversion_factor;
}

int main() {
    double value;
    Unit from_unit, to_unit;

    // Get the value to convert from the user
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Get the units to convert from and to from the user
    printf("Enter the units to convert from (e.g. 'meter' or 'foot'): ");
    fgets(from_unit.name, 20, stdin);
    from_unit.conversion_factor = units[0].conversion_factor;

    printf("Enter the units to convert to (e.g. 'meter' or 'foot'): ");
    fgets(to_unit.name, 20, stdin);
    to_unit.conversion_factor = units[0].conversion_factor;

    // Perform the conversion
    double converted_value = convert_unit(value, from_unit, to_unit);

    // Print the converted value and the original units
    printf("The value is: %f %s\n", converted_value, to_unit.name);

    return 0;
}