//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
        {"mile", 5280},
        {"gram", 0.001},
        {"kilogram", 1000},
        {"ounce", 0.0283495},
        {"pound", 453.592},
        {"ton", 2000},
    };

    struct conversion conversions[MAX_CONVERSIONS] = {
        {"inch", "foot", 12},
        {"foot", "yard", 3},
        {"yard", "mile", 1760},
        {"gram", "kilogram", 0.001},
        {"ounce", "pound", 16},
        {"pound", "ton", 2000},
    };

    int i, j, k;
    double value;
    char from_unit_name[20];
    char to_unit_name[20];

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("Enter a value: ");
        scanf("%lf", &value);

        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(units[i].name, "ton") == 0) {
                continue;
            }

            for (j = 0; j < MAX_CONVERSIONS; j++) {
                if (strcmp(conversions[j].from_unit, units[i].name) == 0) {
                    break;
                }
            }

            if (j == MAX_CONVERSIONS) {
                continue;
            }

            k = j;
            break;
        }

        if (k == MAX_CONVERSIONS) {
            printf("Invalid unit or conversion request.\n");
            continue;
        }

        sprintf(from_unit_name, "%s", conversions[k].from_unit);
        sprintf(to_unit_name, "%s", conversions[k].to_unit);

        value *= conversions[k].factor;

        printf("Value in %s: %f\n", to_unit_name, value);

    } while (1);

    return 0;
}