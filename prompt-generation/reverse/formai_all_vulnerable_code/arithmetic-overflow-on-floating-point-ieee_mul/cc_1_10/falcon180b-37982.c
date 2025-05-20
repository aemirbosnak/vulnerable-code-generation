//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define NUM_UNITS 11

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"m", 1.0},
    {"km", 1000.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"gal", 3.78541},
    {"l", 0.264172},
    {"kg", 1.0}
};

int main() {
    char input[100];
    char from_unit[20];
    char to_unit[20];
    double value, result;
    int i, j;

    printf("Enter a value to convert:\n");
    fgets(input, sizeof(input), stdin);
    value = atof(input);

    printf("Enter the unit of the value:\n");
    fgets(from_unit, sizeof(from_unit), stdin);

    printf("Enter the unit to convert to:\n");
    fgets(to_unit, sizeof(to_unit), stdin);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            for (j = 0; j < NUM_UNITS; j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    result = value * units[j].factor / units[i].factor;
                    printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}