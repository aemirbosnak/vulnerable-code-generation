//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 8

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"centimeters", 0.01},
    {"inches", 0.0254},
    {"feet", 0.3048},
    {"yards", 0.9144},
    {"miles", 160934.4},
    {"kilometers", 1000.0},
    {"pounds", 0.453592}
};

int main() {
    char input[80];
    char unit_name[20];
    double value, result;
    int i;

    printf("Enter a value to convert:\n");
    scanf("%s", input);

    printf("Enter the unit of the value (e.g. meters, centimeters):\n");
    scanf("%s", unit_name);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            break;
        }
    }

    if (i == NUM_UNITS) {
        printf("Invalid unit.\n");
        return 1;
    }

    value = atof(input);
    result = value * units[i].factor;

    printf("%.2f %s = %.2f %s\n", value, unit_name, result, units[i].name);

    return 0;
}