//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 3

// Structure to hold unit information
typedef struct {
    char name[20];   // Unit name (e.g. "meter", "foot", "pound")
    double factor;   // Conversion factor (e.g. 1.0, 0.3048, 2.20462)
} Unit;

// Array to hold all units
Unit units[MAX_UNITS] = {
    {"meter", 1.0},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"pound", 2.20462},
    {"kilogram", 1.0}
};

// Function to convert a unit
void convert(Unit *unit, double value) {
    double new_value = value * unit->factor;
    printf("%.2f %s = %.2f %s\n", value, unit->name, new_value, unit->name);
}

int main() {
    // Prompt user for input
    printf("Enter a value to convert: ");
    double value;
    scanf("%lf", &value);

    // Prompt user for unit selection
    printf("Enter the unit to convert to (m/ft/in/lb/kg): ");
    char unit_selection;
    scanf(" %c", &unit_selection);

    // Find the unit in the array
    for (int i = 0; i < MAX_UNITS; i++) {
        if (unit_selection == units[i].name[0]) {
            Unit *unit = &units[i];
            convert(unit, value);
            break;
        }
    }

    // If the user selects an invalid unit, print an error message
    if (unit_selection == '?' || unit_selection == '\0') {
        printf("Invalid unit selection! Try again.\n");
        return 1;
    }

    return 0;
}