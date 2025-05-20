//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"feet", 0.3048},
    {"inches", 0.0254},
    {"kilograms", 1.0},
    {"pounds", 2.20462},
    {"gallons", 3.78541},
    {"liters", 1.0}
};

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }

    double value = atof(argv[1]);
    char *from_unit = argv[2];
    char *to_unit = argv[3];

    int from_index = -1;
    int to_index = -1;

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_index = i;
        } else if (strcmp(units[i].name, to_unit) == 0) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        printf("Invalid unit(s).\n");
        return 1;
    }

    double result = value * units[from_index].factor / units[to_index].factor;

    printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);

    return 0;
}