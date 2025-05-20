//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct {
    char *name;
    double value;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 1760},
    {"kilogram", 1000},
    {"gram", 0.001},
    {"ounce", 0.02834},
    {"pound", 453.592},
    {"ton", 2000},
    {"inch", 2.54}
};

int main() {
    int i, j;
    char input[100];
    double output[MAX_CONVERTIONS];

    // Initialize input and output arrays
    for (i = 0; i < MAX_UNITS; i++) {
        output[i] = 0;
    }

    // Ask user for input unit and value
    printf("Enter the input value and unit (e.g. '5 inches'): ");
    fgets(input, 100, stdin);

    // Parse input and convert to desired units
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input) == 0) {
            output[i] = units[i].value * atof(input + strlen(input) - strlen(units[i].name));
            break;
        }
    }

    // Print converted values
    for (j = 0; j < MAX_CONVERTIONS; j++) {
        if (output[j] != 0) {
            printf("%s: %f\n", units[j].name, output[j]);
        }
    }

    return 0;
}