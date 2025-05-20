//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

struct unit {
    const char *name;
    double factor;
};

struct conversion {
    const char *from_unit;
    const char *to_unit;
    double factor;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"inch", 2.54},
        {"foot", 12},
        {"yard", 36},
        {"mile", 5280},
        {"centimeter", 0.01},
        {"meter", 100},
        {"kilometer", 100000},
    };

    struct conversion conversions[MAX_CONVERSIONS] = {
        {"inch", "foot", 12},
        {"foot", "yard", 3},
        {"yard", "mile", 0.001},
        {"centimeter", "meter", 100},
        {"meter", "kilometer", 1000},
    };

    int unit_index, conversion_index;
    double value;

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("Enter a value: ");
        scanf("%lf", &value);

        unit_index = 0;
        conversion_index = 0;

        while (unit_index < MAX_UNITS && strcmp(units[unit_index].name, "inch") != 0) {
            unit_index++;
        }

        while (conversion_index < MAX_CONVERSIONS && strcmp(conversions[conversion_index].from_unit, units[unit_index].name) != 0) {
            conversion_index++;
        }

        if (unit_index < MAX_UNITS && conversion_index < MAX_CONVERSIONS) {
            printf("Value in %s: %f\n", units[unit_index].name, value * conversions[conversion_index].factor);
            printf("Value in %s: %f\n", conversions[conversion_index].to_unit, value * conversions[conversion_index].factor);
        } else {
            printf("Invalid input. Please try again.\n");
        }
    } while (1);

    return 0;
}