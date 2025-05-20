//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double factor;
} Unit;

typedef struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
} Conversion;

Unit units[MAX_UNITS] = {
    {"cm", 10.0},
    {"m", 100.0},
    {"km", 100000.0},
    {"mm", 0.1},
    {"in", 2.54},
    {"ft", 12.0},
    {"yd", 36.0},
    {"mi", 5280.0},
};

Conversion conversions[MAX_CONVERTIONS] = {
    {"cm", "m", 10.0},
    {"m", "km", 0.01},
    {"km", "mm", 0.001},
    {"mm", "in", 0.0254},
    {"in", "ft", 2.54},
    {"ft", "yd", 12.0},
    {"yd", "mi", 36.0},
};

int main() {
    int i, j;
    char input_unit[20];
    char output_unit[20];
    double input_value, output_value;

    printf("Welcome to the Unit Converter!\n");

    // Loop through all units and conversions
    for (i = 0; i < MAX_UNITS; i++) {
        for (j = 0; j < MAX_CONVERTIONS; j++) {
            // Prompt user for input value
            printf("Enter a value in %s: ", units[i].name);
            scanf("%lf", &input_value);

            // Convert value to output unit
            for (int k = 0; k < MAX_CONVERTIONS; k++) {
                if (strcmp(input_unit, conversions[j].from_unit) == 0) {
                    output_value = input_value * conversions[j].factor;
                    break;
                }
            }

            // Print converted value and output unit
            printf("That's equivalent to %s%s%s\n", output_unit, output_value, units[i].name);
        }
    }

    return 0;
}