//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct unit {
    const char *name;
    double factor;
} unit_t;

typedef struct conversion {
    const char *from_unit;
    const char *to_unit;
    double factor;
} conversion_t;

static unit_t units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"mi", 1609.344}
};

static conversion_t conversions[MAX_CONVERSIONS] = {
    {"m", "cm", 10.0},
    {"cm", "mm", 0.1},
    {"mm", "m", 0.01},
    {"m", "km", 0.001},
    {"km", "mi", 0.621371}
};

int main() {
    int i, j;
    double value, conversion_factor;
    char input_unit[32], output_unit[32];

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("Enter a value: ");
        scanf("%lf", &value);

        // Check if the input value is negative
        if (value < 0) {
            printf("Invalid input value. Please enter a positive value.\n");
            continue;
        }

        // Get the input unit from the user
        printf("Enter the unit: ");
        fgets(input_unit, sizeof(input_unit), stdin);
        input_unit[strcspn(input_unit, "\n")] = 0;

        // Find the conversion factor for the input unit
        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(input_unit, units[i].name) == 0) {
                conversion_factor = units[i].factor;
                break;
            }
        }

        // If the input unit is not found, print an error message
        if (conversion_factor == 0) {
            printf("Invalid input unit. Please enter a valid unit.\n");
            continue;
        }

        // Get the output unit from the user
        printf("Enter the output unit: ");
        fgets(output_unit, sizeof(output_unit), stdin);
        output_unit[strcspn(output_unit, "\n")] = 0;

        // Find the conversion factor for the output unit
        for (j = 0; j < MAX_CONVERSIONS; j++) {
            if (strcmp(output_unit, conversions[j].from_unit) == 0) {
                conversion_factor = conversions[j].factor;
                break;
            }
        }

        // If the output unit is not found, print an error message
        if (conversion_factor == 0) {
            printf("Invalid output unit. Please enter a valid unit.\n");
            continue;
        }

        // Convert the value to the output unit
        value *= conversion_factor;

        // Print the result
        printf("The value of %s is %f %s.\n", input_unit, value, output_unit);
    }

    return 0;
}