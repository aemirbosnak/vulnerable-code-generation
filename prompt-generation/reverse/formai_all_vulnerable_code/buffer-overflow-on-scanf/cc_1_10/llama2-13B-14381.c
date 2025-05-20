//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_CONVERTIONS 5

typedef struct unit {
    char *name;
    double conversion[UNIT_CONVERTER_MAX_CONVERTIONS];
} unit_t;

unit_t units[UNIT_CONVERTER_MAX_UNITS] = {
    {"meter", {1, 100, 1000, 10000, 100000}},
    {"kilometer", {1, 1000, 10000, 100000, 1000000}},
    {"inch", {1, 10, 100, 1000, 10000}},
    {"foot", {1, 12, 36, 60, 100}},
    {"yard", {1, 3, 30, 90, 180}},
    {"mile", {1, 5280, 16093, 40232, 64000}},
    {"centimeter", {1, 100, 1000, 10000, 100000}},
    {" millimeter", {1, 10, 100, 1000, 10000}},
    {"gram", {1, 1000, 10000, 100000, 1000000}},
    {"kilogram", {1, 1000, 10000, 100000, 1000000}}
};

int main() {
    int i, j;
    double value, converted_value;
    char input_unit[20];
    char output_unit[20];

    printf("Welcome to the Unit Converter!\n");

    // Get the input value
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Get the input unit
    printf("Enter the unit of the value (e.g. meter, kilometer, inch, etc.): ");
    fgets(input_unit, 20, stdin);

    // Convert the value to the desired unit
    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(units[i].name, input_unit) == 0) {
            // Calculate the conversion factor
            for (j = 0; j < UNIT_CONVERTER_MAX_CONVERTIONS; j++) {
                if (value < units[i].conversion[j]) {
                    converted_value = value * units[i].conversion[j];
                    break;
                }
            }
            // Print the converted value and unit
            printf("%.2f %s\n", converted_value, units[i].name);
            return 0;
        }
    }

    // If the input unit is not found, print an error message
    printf("Invalid unit. Please try again.\n");

    return 1;
}