//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UNITS 7
#define MAX_LENGTH 10

typedef struct {
    char name[MAX_LENGTH];
    double factor;
} Unit;

Unit units[UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"km", 1000}
};

int main() {
    char input[MAX_LENGTH];
    char unit_name[MAX_LENGTH];
    int i;
    double value, result;

    printf("Enter the value to convert: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Enter the unit of the value: ");
    fgets(unit_name, MAX_LENGTH, stdin);
    unit_name[strcspn(unit_name, "\n")] = '\0';

    for (i = 0; i < UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            break;
        }
    }

    if (i == UNITS) {
        printf("Invalid unit.\n");
        return 1;
    }

    value = strtod(input, NULL);
    result = value * units[i].factor;

    printf("%.2f %s = %.2f %s\n", value, unit_name, result, units[i].name);

    return 0;
}