//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

struct unit {
    const char *name;
    double factor;
};

struct conversion {
    const char *from_unit;
    const char *to_unit;
    double factor;
};

static struct unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 1760},
    {"kilogram", 1000},
    {"gram", 0.001},
    {"ounce", 0.02834},
    {"pound", 0.453592},
    {"ton", 1000000},
};

static struct conversion conversions[MAX_CONVERTIONS] = {
    {"inch", "foot", 12},
    {"foot", "yard", 3},
    {"yard", "mile", 1760},
    {"kilogram", "gram", 0.001},
    {"gram", "ounce", 0.02834},
    {"ounce", "pound", 0.02834},
    {"pound", "ton", 0.453592},
};

int main() {
    double value, converted_value;
    char from_unit[32], to_unit[32];
    int i, j;

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (e.g. 'inch'): ");
    fgets(from_unit, 32, stdin);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit\n");
        return 1;
    }

    for (j = 0; j < MAX_CONVERTIONS; j++) {
        if (strcmp(conversions[j].from_unit, from_unit) == 0) {
            break;
        }
    }

    if (j == MAX_CONVERTIONS) {
        printf("Invalid conversion\n");
        return 1;
    }

    converted_value = value * conversions[j].factor;
    printf("The value is %g %s\n", converted_value, conversions[j].to_unit);

    return 0;
}