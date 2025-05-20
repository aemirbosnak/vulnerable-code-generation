//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 5
#define MAX_CONVERTIONS 10

typedef struct {
    char *name;
    double value;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"second", 1},
    {"minute", 60},
    {"hour", 3600},
    {"day", 86400},
    {"kilogram", 1000}
};

int main() {
    int i, j, num_units, num_conversions;
    char input_unit[32], output_unit[32];
    double input_value, output_value;

    // Get the number of units and conversions
    printf("Enter the number of units: ");
    scanf("%d", &num_units);
    printf("Enter the number of conversions: ");
    scanf("%d", &num_conversions);

    // Initialize the input and output values
    input_value = 0;
    output_value = 0;

    // Get the input values
    for (i = 0; i < num_units; i++) {
        printf("Enter the value for unit %d: ", i + 1);
        scanf("%lf", &input_value);
        input_value *= units[i].value;
    }

    // Perform the conversions
    for (j = 0; j < num_conversions; j++) {
        // Get the output unit and value
        printf("Enter the output unit (%s, %lf): ", units[j].name, input_value);
        scanf("%31s", output_unit, sizeof(output_unit));
        output_value = units[j].value * input_value;

        // Print the conversion result
        printf("Conversion: %s = %lf (%s)\n", output_unit, output_value, units[j].name);
    }

    return 0;
}