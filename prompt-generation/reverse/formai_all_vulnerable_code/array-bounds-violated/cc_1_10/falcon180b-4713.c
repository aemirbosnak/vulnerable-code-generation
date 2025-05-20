//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

struct unit {
    char *name;
    double factor;
};

int main() {
    struct unit units[MAX_UNITS];
    int num_units = 0;

    units[num_units++] = (struct unit) {
       .name = "inches",
       .factor = 2.54,
    };

    units[num_units++] = (struct unit) {
       .name = "feet",
       .factor = 30.48,
    };

    units[num_units++] = (struct unit) {
       .name = "yards",
       .factor = 91.44,
    };

    units[num_units++] = (struct unit) {
       .name = "miles",
       .factor = 160934.4,
    };

    units[num_units++] = (struct unit) {
       .name = "pints",
       .factor = 568.26,
    };

    units[num_units++] = (struct unit) {
       .name = "quarts",
       .factor = 1136.52,
    };

    units[num_units++] = (struct unit) {
       .name = "gallons",
       .factor = 4546.09,
    };

    units[num_units++] = (struct unit) {
       .name = "ounces",
       .factor = 35.274,
    };

    units[num_units++] = (struct unit) {
       .name = "pounds",
       .factor = 2.20462,
    };

    units[num_units++] = (struct unit) {
       .name = "stones",
       .factor = 6.35029,
    };

    int choice;
    double value, result;

    printf("Welcome to the Medieval Unit Converter!\n");
    printf("Please choose a unit to convert from:\n");

    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Please enter a value to convert:\n");
    scanf("%lf", &value);

    printf("Please choose a unit to convert to:\n");

    for (int i = 0; i < num_units; i++) {
        if (i == choice)
            continue;

        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    result = value * units[choice].factor;

    printf("The converted value is: %.2lf %s\n", result, units[choice].name);

    return 0;
}