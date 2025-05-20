//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

typedef struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
} conversion_t;

unit_t units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 5280.0},
    {"centimeter", 0.01},
    {"meter", 100.0},
    {"kilometer", 100000.0}
};

conversion_t conversions[MAX_CONVERTIONS] = {
    {"inch", "foot", 12.0/2.54},
    {"foot", "yard", 12.0/36.0},
    {"yard", "mile", 36.0/5280.0},
    {"centimeter", "meter", 0.01/100.0},
    {"meter", "kilometer", 100.0/100000.0}
};

int main() {
    int i, j, k;
    char input_unit[20];
    char output_unit[20];
    double input_value;
    double output_value;

    // Menu for selecting units and performing conversions
    printf("Welcome to the Unit Converter!\n");
    printf("Select the unit you want to convert from: ");
    scanf("%19s", input_unit);
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    // Menu for selecting the conversion
    printf("Now select the unit you want to convert to: ");
    scanf("%19s", output_unit);
    for (j = 0; j < MAX_CONVERTIONS; j++) {
        if (strcmp(output_unit, conversions[j].from_unit) == 0) {
            break;
        }
    }
    if (j == MAX_CONVERTIONS) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    // Get the input value from the user
    printf("Enter the value you want to convert: ");
    scanf("%lf", &input_value);

    // Perform the conversion
    for (k = 0; k < MAX_UNITS; k++) {
        if (strcmp(input_unit, units[k].name) == 0) {
            break;
        }
    }
    for (; k < MAX_CONVERTIONS; k++) {
        if (strcmp(output_unit, conversions[k].to_unit) == 0) {
            break;
        }
    }
    output_value = input_value * conversions[k].factor;

    // Print the result
    printf("The value of %s is %lf %s\n", input_unit, output_value, output_unit);

    return 0;
}