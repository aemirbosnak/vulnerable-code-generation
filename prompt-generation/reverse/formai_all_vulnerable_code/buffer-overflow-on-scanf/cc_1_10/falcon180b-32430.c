//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    char *abbreviation;
    double conversion_factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", "m", 1.0},
    {"feet", "ft", 0.3048},
    {"inches", "in", 0.0254},
    {"kilograms", "kg", 1.0},
    {"pounds", "lb", 0.453592},
    {"liters", "L", 1.0},
    {"gallons", "gal", 0.264172}
};

int main() {
    char input_unit[20];
    char output_unit[20];
    double value;

    printf("Enter the unit you want to convert from: ");
    scanf("%s", input_unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", output_unit);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    int input_unit_index = -1;
    int output_unit_index = -1;

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(units[i].name, input_unit) == 0 || strcmp(units[i].abbreviation, input_unit) == 0) {
            input_unit_index = i;
            break;
        }
    }

    if (input_unit_index == -1) {
        printf("Invalid input unit.\n");
        return 1;
    }

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(units[i].name, output_unit) == 0 || strcmp(units[i].abbreviation, output_unit) == 0) {
            output_unit_index = i;
            break;
        }
    }

    if (output_unit_index == -1) {
        printf("Invalid output unit.\n");
        return 1;
    }

    double result = value * units[input_unit_index].conversion_factor / units[output_unit_index].conversion_factor;

    printf("%.2lf %s is equal to %.2lf %s.\n", value, input_unit, result, output_unit);

    return 0;
}