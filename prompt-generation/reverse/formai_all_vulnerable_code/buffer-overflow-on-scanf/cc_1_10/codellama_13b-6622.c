//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
// A unique C unit converter example program in an enthusiastic style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNITS_COUNT 6

// Define a structure to represent a unit and its conversion factor
typedef struct {
    char name[16];
    double conversion_factor;
} unit_t;

// Define the units
unit_t units[UNITS_COUNT] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {"millimeter", 0.001},
    {"yard", 0.9144},
    {"foot", 0.3048}
};

// Define a function to convert a value from one unit to another
double convert_unit(double value, const char* from_unit, const char* to_unit) {
    // Find the conversion factor for the "from" unit
    double from_factor = 1.0;
    for (int i = 0; i < UNITS_COUNT; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_factor = units[i].conversion_factor;
            break;
        }
    }

    // Find the conversion factor for the "to" unit
    double to_factor = 1.0;
    for (int i = 0; i < UNITS_COUNT; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            to_factor = units[i].conversion_factor;
            break;
        }
    }

    // Perform the conversion
    return value * (to_factor / from_factor);
}

int main(void) {
    // Get the value to convert from the user
    double value;
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Get the "from" unit from the user
    char from_unit[16];
    printf("Enter the unit of the value (%s): ", units[0].name);
    scanf("%15s", from_unit);

    // Get the "to" unit from the user
    char to_unit[16];
    printf("Enter the unit to convert to (%s): ", units[1].name);
    scanf("%15s", to_unit);

    // Perform the conversion
    double converted_value = convert_unit(value, from_unit, to_unit);

    // Print the result
    printf("The value in %s is %f\n", to_unit, converted_value);

    return 0;
}