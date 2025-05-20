//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 5

// Define the units and their symbols
typedef struct {
    char *name;
    char *symbol;
} unit_t;

unit_t units[] = {
    {"meter", "m"},
    {"kilometer", "km"},
    {"foot", "ft"},
    {"yard", "yd"},
    {"inch", "in"}
};

// Define the conversions and their factors
typedef struct {
    char *from;
    char *to;
    double factor;
} conversion_t;

conversion_t conversions[] = {
    {"m", "ft", 3.28084},
    {"ft", "yd", 1},
    {"yd", "m", 0.9144},
    {"m", "km", 0.001},
    {"ft", "in", 12}
};

int main() {
    int i, j, k;
    double value;
    char input[50];
    char output[50];

    // Print the unit and conversion menu
    printf("Unit Converter\n");
    printf("-----------------\n");
    for (i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s (%c)\n", i + 1, units[i].name, units[i].symbol);
    }
    printf("\n");

    // Get the input unit and value
    printf("Enter the value in unit: ");
    fgets(input, 50, stdin);
    value = atof(input);

    // Find the corresponding conversion
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        if (strcmp(units[i].symbol, input) == 0) {
            break;
        }
    }
    j = i;

    // Apply the conversion
    for (k = 0; k < j; k++) {
        value *= conversions[k].factor;
    }

    // Print the output
    printf("Value in %s: %f\n", units[j].name, value);

    return 0;
}