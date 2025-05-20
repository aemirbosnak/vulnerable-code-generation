//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 5280.0},
    {"meter", 1.0},
    {"centimeter", 0.01},
    {"kilometer", 1000.0},
    {"gram", 0.001},
    {"kilogram", 1000.0},
    {"pound", 453.592}
};

int main() {
    int i, j;
    double conversion;
    char input_unit[20];
    char output_unit[20];

    printf("Welcome to the Unit Converter!\n");

    // Get the first input unit from the user
    printf("Enter the first unit: ");
    fgets(input_unit, 20, stdin);

    // Get the second input unit from the user
    printf("Enter the second unit: ");
    fgets(output_unit, 20, stdin);

    // Check if the input units are valid
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input_unit) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid input unit. Please try again.\n");
        return 1;
    }

    // Check if the output unit is valid
    for (j = 0; j < MAX_UNITS; j++) {
        if (strcmp(units[j].name, output_unit) == 0) {
            break;
        }
    }

    if (j == MAX_UNITS) {
        printf("Invalid output unit. Please try again.\n");
        return 1;
    }

    // Perform the conversion
    conversion = units[i].factor * (double)atof(input_unit);
    conversion /= units[j].factor;

    // Print the result
    printf("%.2f %s = %%.2f %s\n", conversion, output_unit, conversion, input_unit);

    return 0;
}