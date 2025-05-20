//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

// Define the units and their conversions
typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"pound", 0.453592},
    {"ounce", 0.0625},
    {"gram", 0.001},
    {"kilogram", 1000},
    {"meter", 0.3048},
    {"centimeter", 0.01},
    {" millimeter", 0.001}
};

int main() {
    int i, j;
    double value, converted_value;
    char input_unit[20];
    char output_unit[20];

    // Print the list of units and their conversions
    printf("Available units:\n");
    for (i = 0; i < MAX_UNITS; i++) {
        printf("%s (%f)\n", units[i].name, units[i].factor);
    }

    // Get the input value and unit from the user
    printf("Enter a value and the unit you want to convert from: ");
    fgets(input_unit, 20, stdin);
    input_unit[strcspn(input_unit, "\n")] = 0; // Remove the newline character
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    // Convert the value to the target unit
    value = atof(input_unit);
    for (j = 0; j < MAX_CONVERSIONS; j++) {
        converted_value = value * units[i].factor / units[j].factor;
        printf("Value in %s: %f\n", units[j].name, converted_value);
        if (strcmp(units[j].name, units[i].name) == 0) {
            break;
        }
    }

    // Print the final converted value and unit
    printf("Final converted value: %f %s\n", converted_value, units[j].name);

    return 0;
}