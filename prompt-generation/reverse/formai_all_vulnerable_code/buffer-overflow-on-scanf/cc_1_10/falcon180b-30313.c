//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int i, j, num_units;
    char unit_from[MAX_UNITS], unit_to[MAX_UNITS];
    double value, result;
    Unit units[MAX_UNITS];

    printf("Welcome to the Alan Turing Unit Converter!\n");
    printf("Enter the number of units you want to convert from (1-%d): ", MAX_UNITS);
    scanf("%d", &num_units);

    printf("Enter the name of the unit you are converting from (max %d characters): ", MAX_UNITS);
    scanf(" %[^\n]", unit_from);

    printf("Enter the name of the unit you are converting to (max %d characters): ", MAX_UNITS);
    scanf(" %[^\n]", unit_to);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    for (i = 0; i < num_units; i++) {
        printf("Enter the name of unit #%d (max %d characters): ", i+1, MAX_UNITS);
        scanf(" %[^\n]", units[i].name);
        printf("Enter the conversion factor for %s: ", units[i].name);
        scanf("%lf", &units[i].factor);
    }

    for (i = 0; i < num_units; i++) {
        if (strcmp(unit_from, units[i].name) == 0) {
            for (j = 0; j < num_units; j++) {
                if (strcmp(unit_to, units[j].name) == 0) {
                    result = value * units[i].factor / units[j].factor;
                    printf("%.2lf %s = %.2lf %s\n", value, unit_from, result, unit_to);
                    return 0;
                }
            }
        }
    }

    printf("Invalid units entered.\n");
    return 1;
}