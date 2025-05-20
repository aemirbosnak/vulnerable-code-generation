//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_COUNT 12
#define UNIT_NAMES \
    "inch", "foot", "yard", "mile", \
    "centimeter", "meter", "kilometer", \
    "gram", "pound", "ton"

typedef struct unit_t {
    const char *name;
    double conversion_factor;
} unit_t;

static unit_t units[UNIT_COUNT] = {
    {"inch", 2.54},
    {"foot", 12 * 2.54},
    {"yard", 3 * 2.54},
    {"mile", 5280 * 2.54},
    {"centimeter", 0.01},
    {"meter", 100},
    {"kilometer", 100000},
    {"gram", 0.001},
    {"pound", 453.592},
    {"ton", 2000 * 453.592}
};

int main() {
    int unit_index, from_unit_index, to_unit_index;
    double value, conversion_factor;

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("Enter a value: ");
        scanf("%lf", &value);

        printf("Enter the unit you want to convert from (%s): ", UNIT_NAMES[0]);
        scanf("%d", &from_unit_index);

        printf("Enter the unit you want to convert to (%s): ", UNIT_NAMES[1]);
        scanf("%d", &to_unit_index);

        conversion_factor = units[from_unit_index].conversion_factor / units[to_unit_index].conversion_factor;

        printf("The value of %s is %lf %s\n", units[from_unit_index].name, value * conversion_factor, units[to_unit_index].name);
    } while (1);

    return 0;
}