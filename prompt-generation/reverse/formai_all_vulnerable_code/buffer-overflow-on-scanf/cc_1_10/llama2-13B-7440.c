//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double value;
} Unit;

typedef struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
} Conversion;

Unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 1760},
    {"centimeter", 0.01},
    {"meter", 100},
    {"kilometer", 100000},
    {"gram", 0.001},
    {"kilogram", 1000},
    {"ounce", 0.0283495},
    {"pound", 453.592}
};

Conversion conversions[MAX_CONVERTIONS] = {
    {"inch", "foot", 12},
    {"foot", "yard", 3},
    {"yard", "mile", 1760},
    {"centimeter", "meter", 100},
    {"meter", "kilometer", 100000},
    {"gram", "kilogram", 1000},
    {"ounce", "pound", 16},
    {"pound", "kilogram", 0.453592}
};

int main() {
    int i, j, choice;
    double value, converted_value;
    char input_unit[20], output_unit[20];

    srand(time(NULL));

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("Select a unit to convert: ");
        scanf("%19s", input_unit);

        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(input_unit, units[i].name) == 0) {
                value = units[i].value;
                break;
            }
        }

        if (i == MAX_UNITS) {
            printf("Invalid unit selection. Please try again.\n");
            continue;
        }

        printf("Enter a value to convert: ");
        scanf("%lf", &value);

        for (j = 0; j < MAX_CONVERTIONS; j++) {
            if (strcmp(input_unit, conversions[j].from_unit) == 0) {
                converted_value = value * conversions[j].factor;
                break;
            }
        }

        if (j == MAX_CONVERTIONS) {
            printf("Invalid conversion selection. Please try again.\n");
            continue;
        }

        printf("The value of %s is %lf %s.\n", input_unit, converted_value, conversions[j].to_unit);

        choice = rand() % 2;
        if (choice == 0) {
            printf("Would you like to convert another value? (y/n): ");
        } else {
            printf("Thank you for using the Unit Converter! Goodbye!\n");
            break;
        }
    } while (choice == 0);

    return 0;
}