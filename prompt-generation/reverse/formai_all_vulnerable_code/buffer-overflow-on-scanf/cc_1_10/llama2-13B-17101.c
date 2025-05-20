//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double value;
} unit_t;

typedef struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
} conversion_t;

unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"liter", 1.0},
    {"gallon", 3.785},
    {"ounce", 0.0296},
    {"pint", 0.4736}
};

conversion_t conversions[MAX_CONVERTIONS] = {
    {"meter", "foot", 3.2808},
    {"kilometer", "mile", 0.621371},
    {"foot", "inch", 12.0},
    {"inch", "pint", 20.5},
    {"yard", "mile", 0.01609344},
    {"liter", "gallon", 0.2642},
    {"gallon", "ounce", 128.0},
    {"ounce", "pint", 8.0},
    {"pint", "yard", 2.5}
};

void print_units(unit_t *units, int num_units) {
    int i;
    for (i = 0; i < num_units; i++) {
        printf("%s: %f\n", units[i].name, units[i].value);
    }
}

void print_conversions(conversion_t *conversions, int num_conversions) {
    int i;
    for (i = 0; i < num_conversions; i++) {
        printf("%s to %s: %f\n", conversions[i].from_unit, conversions[i].to_unit, conversions[i].factor);
    }
}

void convert_unit(unit_t *unit, conversion_t *conversion) {
    unit->value *= conversion->factor;
    strcpy(unit->name, conversion->to_unit);
}

int main() {
    int i, j;
    unit_t unit;
    conversion_t conversion;

    // Print the list of units
    print_units(units, sizeof(units) / sizeof(units[0]));

    // Get the user's input
    printf("Enter the unit you want to convert: ");
    scanf("%s", unit.name);

    // Find the corresponding unit in the list
    for (i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(unit.name, units[i].name) == 0) {
            break;
        }
    }

    // If the unit is not found, print an error message and exit
    if (i == sizeof(units) / sizeof(units[0])) {
        printf("Invalid unit selected. Exiting...\n");
        return 1;
    }

    // Get the user's conversion request
    printf("Enter the unit you want to convert to: ");
    scanf("%s", conversion.from_unit);

    // Find the corresponding conversion in the list
    for (j = 0; j < sizeof(conversions) / sizeof(conversions[0]); j++) {
        if (strcmp(conversion.from_unit, conversions[j].from_unit) == 0) {
            break;
        }
    }

    // If the conversion is not found, print an error message and exit
    if (j == sizeof(conversions) / sizeof(conversions[0])) {
        printf("Invalid conversion selected. Exiting...\n");
        return 1;
    }

    // Perform the conversion
    convert_unit(&unit, &conversions[j]);

    // Print the result
    printf("The value of %s is %f %s\n", unit.name, unit.value, conversion.to_unit);

    return 0;
}