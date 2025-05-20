//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MIN_VALUE -999.9
#define MAX_VALUE 999.9

typedef struct {
    char name[10];
    double factor;
} Unit;

void addUnit(Unit* units, int numUnits, char* name, double factor) {
    if (numUnits >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        exit(1);
    }
    strcpy(units[numUnits].name, name);
    units[numUnits].factor = factor;
    numUnits++;
}

int main() {
    Unit units[MAX_UNITS];
    int numUnits = 0;
    char input[50];
    double value = MIN_VALUE;

    addUnit(units, numUnits, "m", 1.0);
    addUnit(units, numUnits, "cm", 0.01);
    addUnit(units, numUnits, "mm", 0.001);

    printf("Enter a value to convert:\n");
    scanf("%s", input);

    if (strcmp(input, "m") == 0) {
        value = MIN_VALUE;
    } else if (strcmp(input, "cm") == 0) {
        value = MIN_VALUE;
    } else if (strcmp(input, "mm") == 0) {
        value = MIN_VALUE;
    } else {
        printf("Error: Invalid unit.\n");
        exit(1);
    }

    printf("Enter a value to convert:\n");
    scanf("%lf", &value);

    if (value < MIN_VALUE || value > MAX_VALUE) {
        printf("Error: Invalid value.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < numUnits; i++) {
        double result = value * units[i].factor;
        printf("%s: %.2lf\n", units[i].name, result);
    }

    return 0;
}