//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 10

struct unit {
    char name[20];
    double factor;
};

struct conversion {
    char from[20];
    char to[20];
    double factor;
};

int main() {
    // Initialize unit array
    struct unit units[MAX_UNITS] = {
        {"meter", 1.0},
        {"kilometer", 1000.0},
        {"foot", 0.3048},
        {"yard", 0.9144},
        {"mile", 1609.34}
    };

    // Initialize conversion array
    struct conversion conversions[MAX_CONVERSIONS] = {
        {"foot", "meter", 0.3048},
        {"yard", "meter", 0.9144},
        {"mile", "kilometer", 1609.34},
        {"kilometer", "foot", 1000.0 / 0.3048},
        {"kilometer", "yard", 1000.0 / 0.9144}
    };

    // Print welcome message
    printf("Welcome to the Unit Converter!\n");

    // Print available units
    printf("Available units:\n");
    for (int i = 0; i < MAX_UNITS; i++) {
        printf("  %s (%f)\n", units[i].name, units[i].factor);
    }

    // Print available conversions
    printf("Available conversions:\n");
    for (int i = 0; i < MAX_CONVERSIONS; i++) {
        printf("  %s (%s) = %f\n", conversions[i].from, conversions[i].to, conversions[i].factor);
    }

    // Get input from user
    char input_unit[20];
    char input_conversion[20];
    double input_value;

    printf("Enter a value in a unit (e.g. 5 meter): ");
    scanf("%lf %s %s", &input_value, input_unit, input_conversion);

    // Perform conversion
    double output_value = input_value * units[atoi(input_unit)].factor;

    // Print output
    printf("Equivalent value in %s: %f\n", input_conversion, output_value);

    // Print additional information
    printf("Additional information:\n");
    printf("  * The %s unit is defined as %f meters\n", input_unit, units[atoi(input_unit)].factor);
    printf("  * The %s conversion is defined as %f %s per %s\n", input_conversion, conversions[atoi(input_conversion)].factor, conversions[atoi(input_conversion)].from, conversions[atoi(input_conversion)].to);

    return 0;
}