//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_LENGTH 50
#define UNIT_CONVERTER_DEFAULT_FROM_UNIT "cm"
#define UNIT_CONVERTER_DEFAULT_TO_UNIT "m"

struct unit_converter {
    char *from_unit;
    char *to_unit;
    double conversion_factor;
};

static struct unit_converter unit_converters[] = {
    {"cm", "m", 100.0},
    {"m", "cm", 0.1},
    {"mm", "cm", 0.01},
    {"cm", "mm", 0.01},
    {"m", "mm", 0.001},
    {"mm", "m", 0.001},
    {"ft", "in", 12.0},
    {"in", "ft", 0.08333333333333333},
    {"yd", "ft", 0.3048},
    {"ft", "yd", 0.3333333333333333},
    {"in", "yd", 0.25},
    {"yd", "in", 0.25},
    {"mile", "ft", 5280.0},
    {"ft", "mile", 0.000621371},
    {"yd", "mile", 0.000160934},
    {"mile", "yd", 0.000160934},
};

int main() {
    int i, j;
    char from_unit[UNIT_CONVERTER_MAX_LENGTH];
    char to_unit[UNIT_CONVERTER_MAX_LENGTH];
    double value;

    printf("Welcome to the Unit Converter!\n");

    // Initialize the from and to units with the default values
    strcpy(from_unit, UNIT_CONVERTER_DEFAULT_FROM_UNIT);
    strcpy(to_unit, UNIT_CONVERTER_DEFAULT_TO_UNIT);

    // Print the list of available units
    printf("Available units:\n");
    for (i = 0; i < sizeof(unit_converters) / sizeof(unit_converters[0]); i++) {
        printf("%s -> %s (%f)\n", unit_converters[i].from_unit, unit_converters[i].to_unit, unit_converters[i].conversion_factor);
    }

    // Read the input from the user
    printf("Enter the value in the from unit: ");
    scanf("%lf", &value);
    printf("Enter the to unit: ");
    gets(from_unit);
    gets(to_unit);

    // Find the corresponding conversion factor
    for (i = 0; i < sizeof(unit_converters) / sizeof(unit_converters[0]); i++) {
        if (strcmp(from_unit, unit_converters[i].from_unit) == 0) {
            j = i;
            break;
        }
    }

    // Perform the conversion
    value *= unit_converters[j].conversion_factor;

    // Print the result
    printf("The value in the %s unit is %f\n", to_unit, value);

    return 0;
}