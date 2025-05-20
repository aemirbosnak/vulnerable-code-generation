//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 10

typedef struct {
    char *name;
    double value;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 5280.0},
    {"kilometer", 1000.0}
};

int main() {
    int i, j, num_conversions = 0;
    char input_unit[20];
    char output_unit[20];
    double input_value, output_value;

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("Enter a value in %s: ", units[0].name);
        scanf("%lf", &input_value);

        for (i = 0; i < MAX_UNITS; i++) {
            if (strcmp(units[i].name, input_unit) == 0) {
                break;
            }
        }

        if (i == MAX_UNITS) {
            printf("Invalid unit. Try again.\n");
            continue;
        }

        for (j = 0; j < MAX_CONVERSIONS; j++) {
            if (strcmp(units[i].name, units[j].name) == 0) {
                break;
            }
        }

        if (j == MAX_CONVERSIONS) {
            printf("No conversion available for %s to %s. Try again.\n", units[i].name, units[j].name);
            continue;
        }

        output_value = input_value * units[i].value / units[j].value;
        printf("Input value of %s is %lf, converted to %s is %lf\n", units[i].name, input_value, units[j].name, output_value);

        num_conversions++;
    } while (scanf("%s%s", input_unit, output_unit) == 2);

    printf("You have performed %d conversions.\n", num_conversions);

    return 0;
}