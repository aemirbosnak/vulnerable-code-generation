//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_TYPES 6

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[UNIT_TYPES] = {
    {"m", 1},
    {"cm", 0.01},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4}
};

int main() {
    char input[100];
    int i;
    double value, result;
    Unit from, to;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", input);

    printf("Enter the unit to convert to: ");
    scanf("%s", input);

    for (i = 0; i < UNIT_TYPES; i++) {
        if (strcmp(input, units[i].name) == 0) {
            from = units[i];
            break;
        }
    }

    for (i = 0; i < UNIT_TYPES; i++) {
        if (strcmp(input, units[i].name) == 0) {
            to = units[i];
            break;
        }
    }

    result = value * from.factor / to.factor;

    printf("%.2lf %s = %.2lf %s\n", value, input, result, to.name);

    return 0;
}