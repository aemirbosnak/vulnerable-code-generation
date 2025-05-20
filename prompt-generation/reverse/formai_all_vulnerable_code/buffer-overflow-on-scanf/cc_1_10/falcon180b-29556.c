//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUM_UNITS 8

struct unit {
    char *name;
    double factor;
};

struct unit units[NUM_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"g", 1.0},
    {"kg", 1000.0},
    {"l", 1.0},
    {"ml", 0.001}
};

int main() {
    char input[100];
    char from_unit[10];
    char to_unit[10];
    double value, result;
    int i, from_index, to_index;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_index = i;
            break;
        }
    }

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            to_index = i;
            break;
        }
    }

    result = value * units[from_index].factor / units[to_index].factor;

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}