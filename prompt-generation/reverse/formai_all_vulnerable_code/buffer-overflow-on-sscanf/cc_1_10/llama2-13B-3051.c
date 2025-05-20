//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_LENGTH 50
#define UNIT_CONVERTER_DEFAULT_FROM_UNIT "cm"
#define UNIT_CONVERTER_DEFAULT_TO_UNIT "in"

struct unit_converter {
    char *from_unit;
    char *to_unit;
    double factor;
};

static struct unit_converter unit_converters[] = {
    { "cm", "in", 1.0 },
    { "in", "cm", 0.875 },
    { "m", "ft", 3.28084 },
    { "ft", "m", 0.3048 },
    { "kg", "lb", 2.20462 },
    { "lb", "kg", 0.453592 },
    { "°C", "°F", 1.8 * (3.0 / 2.0) - 273.15 },
    { "°F", "°C", 2.0 * (3.0 / 2.0) + 273.15 },
};

int main() {
    int i;
    char from_unit[UNIT_CONVERTER_MAX_LENGTH];
    char to_unit[UNIT_CONVERTER_MAX_LENGTH];
    double value;

    printf("Enter a value and a unit (e.g. '5 apples cm'): ");
    fgets(from_unit, UNIT_CONVERTER_MAX_LENGTH, stdin);

    // Parse the input
    if (sscanf(from_unit, "%lf %s", &value, from_unit) != 2) {
        printf("Invalid input. Please enter a number and a unit (e.g. '5 apples cm').\n");
        return 1;
    }

    // Find the corresponding unit converter
    for (i = 0; i < sizeof(unit_converters) / sizeof(unit_converters[0]); i++) {
        if (strcmp(from_unit, unit_converters[i].from_unit) == 0) {
            break;
        }
    }

    if (i == sizeof(unit_converters) / sizeof(unit_converters[0])) {
        printf("Invalid unit. Please enter a valid unit (e.g. 'cm', 'in', 'm', 'ft', 'kg', 'lb', '°C', or '°F').\n");
        return 1;
    }

    // Perform the conversion
    value *= unit_converters[i].factor;

    // Print the result
    printf("The value of %s is %f %s.\n", from_unit, value, to_unit);

    // Ask the user for the next conversion
    printf("Enter another value and a unit (e.g. '5 apples cm'): ");

    return 0;
}