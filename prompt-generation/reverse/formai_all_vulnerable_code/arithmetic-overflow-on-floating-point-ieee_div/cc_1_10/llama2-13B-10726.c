//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 5
#define MAX_CONVERTIONS 10

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

static unit_t units[] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"kilogram", 0.0220462},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"gram", 0.001},
    {"millimeter", 0.001},
    {"centimeter", 0.01},
    {"meter", 100}
};

int main() {
    srand(time(NULL));

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("Enter the value you want to convert: ");
        double value;
        scanf("%lf", &value);

        int unit_index = rand() % MAX_UNITS;
        unit_t *unit = units + unit_index;

        printf("You have chosen unit: %s\n", unit->name);

        for (int i = 0; i < MAX_CONVERTIONS; i++) {
            int target_unit_index = rand() % MAX_UNITS;
            unit_t *target_unit = units + target_unit_index;

            double conversion = value * unit->factor / target_unit->factor;
            printf("Conversion: %s %s = %s %s\n", unit->name, unit->name, target_unit->name, target_unit->name);

            if (i == 0) {
                printf("Original value: %lf %s\n", value, unit->name);
            }

            printf("Value in %s: %lf %s\n", target_unit->name, conversion, target_unit->name);
        }
    } while (1);

    return 0;
}