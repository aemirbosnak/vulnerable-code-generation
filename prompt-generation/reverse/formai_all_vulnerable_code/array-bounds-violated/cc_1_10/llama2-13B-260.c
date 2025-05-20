//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct {
    char *name;
    double value;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"m", 1},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"ft", 3.28084},
    {"yd", 36},
    {"in", 0.0254},
    {"pt", 0.0007854}
};

int main() {
    int i, j, num_units, num_conversions;
    char input[100];
    double output[MAX_CONVERTIONS];

    // Initialize the number of units and conversions
    num_units = 0;
    num_conversions = 0;

    // Loop until the user enters a non-numeric input
    while (1) {
        printf("Enter a unit or conversion: ");
        fgets(input, 100, stdin);

        // Check if the input is a unit
        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(input, units[i].name) == 0) {
                // Add the unit to the list
                num_units++;
                break;
            }
        }

        // Check if the input is a conversion
        if (num_units == MAX_UNITS) {
            break;
        }

        // Convert the input to a double value
        double value = atof(input);

        // Check if the input is a valid conversion
        for (j = 0; j < num_conversions; j++) {
            if (value == output[j]) {
                break;
            }
        }

        // Add the conversion to the list
        if (j == num_conversions) {
            output[num_conversions++] = value;
        }
    }

    // Print the converted values
    for (j = 0; j < num_conversions; j++) {
        printf("%s = %f\n", units[j].name, output[j]);
    }

    return 0;
}