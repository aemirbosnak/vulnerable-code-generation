//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct unit {
    char name[50];
    double value;
} unit_t;

typedef struct conversion {
    char from[50];
    char to[50];
    double factor;
} conversion_t;

unit_t units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"kilogram", 1000}
};

conversion_t conversions[MAX_CONVERSIONS] = {
    {"inch", "foot", 12},
    {"foot", "yard", 3},
    {"yard", "mile", 0.0256},
    {"kilogram", "gram", 1000},
    {"gram", "kilogram", 0.001}
};

int main() {
    int i, j;
    char input[50];
    double value;
    unit_t *unit;
    conversion_t *conversion;

    printf("Enter a unit to convert: ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = 0; // ignore newline

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            unit = &units[i];
            break;
        }
    }

    if (unit == NULL) {
        printf("Invalid unit\n");
        return 1;
    }

    printf("Enter a value to convert: ");
    scanf("%lf", &value);

    for (j = 0; j < MAX_CONVERSIONS; j++) {
        if (strcmp(conversions[j].from, unit->name) == 0) {
            conversion = &conversions[j];
            break;
        }
    }

    if (conversion == NULL) {
        printf("No conversion found\n");
        return 1;
    }

    value *= conversion->factor;
    printf("The value of %s is %lf %s\n", unit->name, value, conversion->to);

    return 0;
}