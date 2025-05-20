//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

struct unit {
    char name[20];
    double factor;
};

struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"inch", 2.54},
        {"foot", 12},
        {"yard", 36},
        {"mile", 1760},
        {"cm", 100},
        {"m", 1000},
        {"km", 1000000}
    };

    struct conversion conversions[MAX_CONVERSIONS] = {
        {"inch", "foot", 12},
        {"foot", "yard", 3},
        {"yard", "mile", 0.001},
        {"cm", "m", 0.01},
        {"m", "km", 0.001}
    };

    int choice;
    double value;
    char unit_from, unit_to;

    do {
        printf("Welcome to the Unit Converter!\n");
        printf("Choose a unit to convert from: ");
        scanf("%s", &unit_from);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(unit_from, units[i].name) == 0) {
                value = 1;
                break;
            }
        }

        if (value == 0) {
            printf("Invalid unit %s. Please try again.\n", unit_from);
            continue;
        }

        printf("Choose a unit to convert to: ");
        scanf("%s", &unit_to);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(unit_to, units[i].name) == 0) {
                value = value * units[i].factor;
                break;
            }
        }

        for (int i = 0; i < MAX_CONVERSIONS; i++) {
            if (strcmp(unit_from, conversions[i].from_unit) == 0 &&
                    strcmp(unit_to, conversions[i].to_unit) == 0) {
                value = value * conversions[i].factor;
                break;
            }
        }

        printf("Result: %f %s\n", value, unit_to);
    } while (1);

    return 0;
}