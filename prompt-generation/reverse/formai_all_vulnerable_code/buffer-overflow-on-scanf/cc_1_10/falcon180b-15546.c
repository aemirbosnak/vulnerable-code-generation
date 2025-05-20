//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 10

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
    {"mi", 160934.4},
    {"gal", 3.78541},
    {"l", 0.264172},
    {"kg", 1.0}
};

int main() {
    char input[100];
    char *unit1, *unit2;
    double value, result;
    int i, j;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter a value followed by its unit (e.g. 10 m): ");
    scanf("%s", input);

    unit1 = strtok(input, " ");
    value = atof(unit1);

    unit2 = strtok(NULL, " ");
    if (unit2 == NULL) {
        printf("Error: Unit not specified.\n");
        return 1;
    }

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit2, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%.2f %s = %.2f %s\n", value, unit1, result, units[i].name);
            return 0;
        }
    }

    printf("Error: Invalid unit.\n");
    return 1;
}