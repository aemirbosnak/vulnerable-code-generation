//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_OPERATIONS 5

typedef struct unit {
    const char *name;
    double factor;
} Unit;

typedef struct operation {
    const char *unit1;
    const char *unit2;
    double factor;
} Operation;

Unit units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34},
    {"ft", 3.28084},
    {"in", 0.0254}
};

Operation operations[] = {
    {"m", "cm", 100},
    {"cm", "mm", 10},
    {"mm", "m", 0.01},
    {"m", "km", 0.001},
    {"km", "mi", 0.621371},
    {"mi", "ft", 1609.34 / 3.28084},
    {"ft", "in", 12 / 3.28084}
};

int main() {
    int i, j;
    double value, factor;
    char unit1[20], unit2[20];

    // Print the available units and operations
    printf("Available units:\n");
    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        printf("%s\n", units[i].name);
    }
    printf("\nAvailable operations:\n");
    for (i = 0; i < UNIT_CONVERTER_MAX_OPERATIONS; i++) {
        printf("%s %s -> %s\n", operations[i].unit1, operations[i].unit2, operations[i].factor);
    }

    // Get the input values and units
    printf("Enter a value: ");
    scanf("%lf", &value);
    printf("Enter the first unit (m/cm/mm/km/mi/ft/in): ");
    gets(unit1);
    printf("Enter the second unit (m/cm/mm/km/mi/ft/in): ");
    gets(unit2);

    // Perform the conversion
    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        for (j = 0; j < UNIT_CONVERTER_MAX_OPERATIONS; j++) {
            if (strcmp(unit1, operations[j].unit1) == 0 && strcmp(unit2, operations[j].unit2) == 0) {
                factor = operations[j].factor;
                break;
            }
        }
        if (factor != 0) break;
    }

    // Print the result
    printf("Value in %s is %f\n", unit2, value * factor);

    return 0;
}