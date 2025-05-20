//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_value> <input_unit> <output_unit>\n", argv[0]);
        return 1;
    }

    double input_value = atof(argv[1]);
    char *input_unit = argv[2];
    char *output_unit = argv[3];

    int num_units = 0;
    Unit units[MAX_UNITS];

    // Initialize default units
    units[num_units++] = (Unit) {"m", 1.0};
    units[num_units++] = (Unit) {"kg", 1.0};
    units[num_units++] = (Unit) {"s", 1.0};
    units[num_units++] = (Unit) {"A", 1.0};
    units[num_units++] = (Unit) {"K", 1.0};
    units[num_units++] = (Unit) {"mol", 1.0};
    units[num_units++] = (Unit) {"cd", 1.0};
    units[num_units++] = (Unit) {"Hz", 1.0};
    units[num_units++] = (Unit) {"N", 1.0};
    units[num_units++] = (Unit) {"J", 1.0};

    // Search for input and output units in the list
    int input_unit_index = -1;
    int output_unit_index = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, input_unit) == 0) {
            input_unit_index = i;
        }
        if (strcmp(units[i].name, output_unit) == 0) {
            output_unit_index = i;
        }
    }

    if (input_unit_index == -1 || output_unit_index == -1) {
        printf("Invalid unit(s)\n");
        return 1;
    }

    // Calculate conversion factor
    double conversion_factor = units[output_unit_index].factor / units[input_unit_index].factor;

    // Convert input value
    double output_value = input_value * conversion_factor;

    // Print result
    printf("%.2f %s = %.2f %s\n", input_value, input_unit, output_value, output_unit);

    return 0;
}