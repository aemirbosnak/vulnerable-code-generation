//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef enum UnitCategory {
    LENGTH,
    MASS,
    TIME,
    TEMPERATURE,
    NONE
} UnitCategory;

typedef struct Unit {
    char *name;
    double factor;
    UnitCategory category;
} Unit;

Unit units[] = {
    {"inch", 2.54, LENGTH},
    {"foot", 30.48, LENGTH},
    {"yard", 91.44, LENGTH},
    {"mile", 1609.34, LENGTH},
    {"kilometer", 1000, LENGTH},
    {"meter", 1, LENGTH},

    {"ounce", 28.35, MASS},
    {"pound", 453.592, MASS},
    {"kilogram", 1000, MASS},
    {"gram", 1, MASS},

    {"second", 1, TIME},
    {"minute", 60, TIME},
    {"hour", 3600, TIME},
    {"day", 86400, TIME},

    {"fahrenheit", 1, TEMPERATURE},
    {"celsius", 0.5555555555555556, TEMPERATURE},
    {"kelvin", 273.15, TEMPERATURE}
};

int num_units = sizeof(units) / sizeof(Unit);

double convert(double value, char *from_unit, char *to_unit) {
    Unit *from = NULL;
    Unit *to = NULL;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from = &units[i];
        }
        if (strcmp(units[i].name, to_unit) == 0) {
            to = &units[i];
        }
    }
    assert(from != NULL);
    assert(to != NULL);
    assert(from->category == to->category);
    return value * from->factor / to->factor;
}

int main() {
    double value;
    char from_unit[100];
    char to_unit[100];

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    double converted_value = convert(value, from_unit, to_unit);
    printf("%lf %s is equal to %lf %s\n", value, from_unit, converted_value, to_unit);
    return 0;
}