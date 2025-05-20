//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: asynchronous
//unit_converter.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    float factor;
} Unit;

int main() {
    int num_units;
    char input[100];
    char *token;
    Unit *units = malloc(MAX_UNITS * sizeof(Unit));
    num_units = 0;

    printf("Enter the number of units to convert from:\n");
    scanf("%d", &num_units);

    printf("Enter the units (one per line):\n");
    for (int i = 0; i < num_units; i++) {
        scanf("%s", input);
        units[i].name = strdup(input);
        printf("Enter the conversion factor for %s:\n", input);
        scanf("%f", &units[i].factor);
    }

    char from_unit[100];
    printf("Enter the unit to convert from:\n");
    scanf("%s", from_unit);

    char to_unit[100];
    printf("Enter the unit to convert to:\n");
    scanf("%s", to_unit);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(units[j].name, to_unit) == 0) {
                    float result = (float)atof(input) * units[i].factor / units[j].factor;
                    printf("%f %s = %f %s\n", atof(input), from_unit, result, to_unit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}