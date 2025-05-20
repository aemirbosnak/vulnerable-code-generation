//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 5

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"feet", 0.3048},
    {"inches", 0.0254},
    {"kilograms", 1.0},
    {"pounds", 2.20462}
};

int main() {
    char input[100];
    char unit_from[10];
    char unit_to[10];
    double value;
    int i;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", unit_from);

    printf("Enter the unit to convert to: ");
    scanf("%s", unit_to);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_from, units[i].name) == 0) {
            break;
        }
    }

    if (i == NUM_UNITS) {
        printf("Invalid unit '%s'\n", unit_from);
        return 1;
    }

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_to, units[i].name) == 0) {
            break;
        }
    }

    if (i == NUM_UNITS) {
        printf("Invalid unit '%s'\n", unit_to);
        return 1;
    }

    value *= units[i].factor;

    printf("%.2lf %s = %.2lf %s\n", value, unit_from, value, unit_to);

    return 0;
}