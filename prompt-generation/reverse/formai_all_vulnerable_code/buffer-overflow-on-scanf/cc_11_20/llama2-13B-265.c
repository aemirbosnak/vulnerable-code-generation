//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    {"mile", 5280},
    {"kilogram", 0.001},
    {"gram", 0.000001},
    {"meter", 1},
    {"centimeter", 0.01},
    {" millimeter", 0.001},
};

int main() {
    int i, j, k;
    char input[100];
    double output[MAX_CONVERTIONS];

    // Initialize the conversion table
    for (i = 0; i < MAX_UNITS; i++) {
        for (j = 0; j < MAX_UNITS; j++) {
            if (i != j) {
                units[i].value = (double)units[j].value / units[i].value;
            }
        }
    }

    // Prompt the user for input
    printf("Welcome to the Unit Converter!\n");
    printf("Please enter a unit to convert: ");
    fgets(input, 100, stdin);

    // Check if the input is a valid unit
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    // Prompt the user for the value to convert
    printf("Please enter the value to convert: ");
    scanf("%lf", &output[0]);

    // Convert the value to all possible units
    for (j = 1; j < MAX_CONVERTIONS; j++) {
        for (k = 0; k < MAX_UNITS; k++) {
            if (k != i) {
                output[j] = output[j] * units[k].value / units[i].value;
            }
        }
    }

    // Print the conversion results
    for (j = 0; j < MAX_CONVERTIONS; j++) {
        printf("%s: %f\n", units[i].name, output[j]);
    }

    return 0;
}