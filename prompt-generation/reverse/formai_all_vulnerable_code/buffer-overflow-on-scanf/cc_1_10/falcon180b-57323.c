//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
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
    double value;
    int i, j;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    i = -1;
    for (j = 0; j < NUM_UNITS; j++) {
        if (strcmp(from_unit, units[j].name) == 0) {
            i = j;
            break;
        }
    }

    if (i == -1) {
        printf("Invalid unit: %s\n", from_unit);
        return 1;
    }

    j = -1;
    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            j = i;
            break;
        }
    }

    if (j == -1) {
        printf("Invalid unit: %s\n", to_unit);
        return 1;
    }

    value *= units[i].factor;
    value /= units[j].factor;

    printf("%.2lf %s = %.2lf %s\n", value, to_unit, value, from_unit);

    return 0;
}