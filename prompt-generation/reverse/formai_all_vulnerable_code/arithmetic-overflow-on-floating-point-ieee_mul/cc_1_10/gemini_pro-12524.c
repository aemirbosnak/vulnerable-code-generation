//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the supported units
#define UNITS_COUNT 10
const char *units[] = {
    "meters", "centimeters", "millimeters",
    "kilometers", "inches", "feet",
    "yards", "miles", "nautical miles",
    "astronomical units"
};

// Define the conversion factors
const double conversion_factors[] = {
    1.0, 0.01, 0.001,
    1000.0, 0.0254, 0.3048,
    0.9144, 1609.34, 1852.0,
    149597870700.0
};

// Print the list of supported units
void print_units() {
    printf("Supported units:\n");
    for (int i = 0; i < UNITS_COUNT; i++) {
        printf("  %s\n", units[i]);
    }
}

// Get the index of the unit from the string
int get_unit_index(const char *unit) {
    for (int i = 0; i < UNITS_COUNT; i++) {
        if (strcmp(unit, units[i]) == 0) {
            return i;
        }
    }

    return -1;
}

// Convert the value from one unit to another
double convert(double value, int from_unit, int to_unit) {
    return value * conversion_factors[to_unit] / conversion_factors[from_unit];
}

// Print the converted value
void print_converted_value(double value, const char *from_unit, const char *to_unit) {
    printf("%f %s is equal to %f %s\n", value, from_unit, convert(value, get_unit_index(from_unit), get_unit_index(to_unit)), to_unit);
}

int main() {
    // Print the list of supported units
    print_units();

    // Get the input value, from unit, and to unit from the user
    double value;
    char from_unit[20];
    char to_unit[20];

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    // Convert the value and print the result
    print_converted_value(value, from_unit, to_unit);

    return 0;
}