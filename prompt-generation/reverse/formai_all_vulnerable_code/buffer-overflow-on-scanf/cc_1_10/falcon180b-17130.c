//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"m", 1.0},
    {"km", 1000.0},
    {"cm", 0.01},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4}
};

int main() {
    char input[100];
    char from_unit[10];
    char to_unit[10];
    double value, result;
    int i, from_unit_index, to_unit_index;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    from_unit_index = -1;
    to_unit_index = -1;

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_unit_index = i;
        }
        if (strcmp(to_unit, units[i].name) == 0) {
            to_unit_index = i;
        }
    }

    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("Invalid unit.\n");
        return 1;
    }

    result = value * units[from_unit_index].factor / units[to_unit_index].factor;

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}