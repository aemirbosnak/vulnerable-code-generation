//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"l", 1.0},
    {"ml", 0.001}
};

int num_units = sizeof(units) / sizeof(Unit);

void print_units() {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%s\n", units[i].name);
    }
}

int main() {
    char input[100];
    double value, result = 0.0;
    int from_unit, to_unit;

    print_units();

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf("%s", input);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            from_unit = i;
            break;
        }
    }

    printf("Enter the unit to convert to: ");
    scanf("%s", input);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(input, units[i].name) == 0) {
            to_unit = i;
            break;
        }
    }

    result = value * units[to_unit].factor / units[from_unit].factor;

    printf("The converted value is: %.2lf %s\n", result, units[to_unit].name);

    return 0;
}