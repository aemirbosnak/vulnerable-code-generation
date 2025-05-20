//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct {
    char name[20];
    double value;
} Unit;

Unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 1760},
    {"kilogram", 1000},
    {"gram", 0.001},
    {"ounce", 0.02834},
    {"pound", 453.592},
    {"ton", 2000},
    {"meter", 1},
    {"centimeter", 0.01}
};

int main() {
    int i, j, k;
    char input[20];
    double output[MAX_CONVERTIONS];

    // Get the input unit and value from the user
    printf("Enter a unit and a value: ");
    fgets(input, 20, stdin);
    sscanf(input, "%s %lf", units[0].name, &output[0]);

    // Perform the conversions
    for (i = 1; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, units[0].name) == 0) {
            continue;
        }
        for (j = 0; j < MAX_CONVERTIONS; j++) {
            if (j == 0) {
                output[j] = output[0] * units[i].value / units[0].value;
            } else {
                output[j] = output[j - 1] * units[i].value / units[j - 1].value;
            }
        }
    }

    // Print the results
    for (k = 0; k < MAX_CONVERTIONS; k++) {
        printf("%s: %f\n", units[k].name, output[k]);
    }

    return 0;
}