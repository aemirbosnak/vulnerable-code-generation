//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"m", 1.0},
    {"km", 1000.0},
    {"cm", 0.01},
    {"in", 2.54},
    {"ft", 30.48},
    {"yd", 91.44},
    {"mi", 160934.4}
};

int main() {
    char input[100];
    char unit_from[10], unit_to[10];
    double value, result;
    int i, from_index, to_index;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (e.g. m, km, cm, in, ft, yd, mi): ");
    scanf("%s", unit_from);

    printf("Enter the unit to convert to (e.g. m, km, cm, in, ft, yd, mi): ");
    scanf("%s", unit_to);

    from_index = -1;
    to_index = -1;

    for (i = 0; i < NUM_UNITS; i++) {
        if (!strcmp(unit_from, units[i].name)) {
            from_index = i;
        }
        if (!strcmp(unit_to, units[i].name)) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        printf("Invalid unit\n");
        exit(1);
    }

    result = value * units[from_index].factor / units[to_index].factor;

    printf("%.2lf %s = %.2lf %s\n", value, unit_from, result, unit_to);

    return 0;
}