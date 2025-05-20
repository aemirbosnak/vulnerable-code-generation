//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"cm", 0.01},
    {"m", 1},
    {"km", 1000},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"in", 0.02777777777777778},
    {"pt", 0.01999999999999999},
    {"mile", 1609.344},
    {"yd", 0.9144}
};

int main() {
    int i, j, num_conversions = 0;
    double value, conversion_factor;
    char input_unit[20], output_unit[20];

    // Initialize the input and output units
    strcpy(input_unit, "cm");
    strcpy(output_unit, "");

    // Get the input value from the user
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Loop through all the units and find the best conversion
    for (i = 0; i < MAX_UNITS; i++) {
        conversion_factor = units[i].factor;
        if (fabs(value * conversion_factor - 1) < fabs(value * units[i + 1].factor - 1)) {
            break;
        }
    }

    // Output the converted value and the unit
    printf("The value is %lf %s\n", value, units[i].name);

    // Allow the user to convert to another unit
    do {
        printf("Would you like to convert to another unit? (y/n): ");
        scanf(" %c", &j);

        if (j == 'y') {
            // Get the new output unit from the user
            printf("Enter the new output unit (e.g. 'cm', 'm', 'km'): ");
            scanf("%19s", output_unit);

            // Find the conversion factor for the new unit
            for (j = 0; j < MAX_UNITS; j++) {
                if (strcmp(output_unit, units[j].name) == 0) {
                    conversion_factor = units[j].factor;
                    break;
                }
            }

            // Output the converted value and the new unit
            printf("The value is %lf %s\n", value * conversion_factor, output_unit);
        } else {
            break;
        }

        num_conversions++;
    } while (j == 'y');

    // Print the number of conversions performed
    printf("Number of conversions performed: %d\n", num_conversions);

    return 0;
}