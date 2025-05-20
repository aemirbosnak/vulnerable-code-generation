//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_UNITS 7 // maximum number of units to convert
#define UNIT_LENGTH 20 // maximum length of each unit

typedef struct {
    char name[UNIT_LENGTH]; // name of unit
    double factor; // conversion factor
} Unit;

void readUnits(Unit units[], int *numUnits) {
    char buffer[UNIT_LENGTH];
    printf("Enter units (type 'done' when finished):\n");
    while (1) {
        fgets(buffer, UNIT_LENGTH, stdin);
        if (strcmp(buffer, "done") == 0) {
            break;
        }
        strcpy(units[*numUnits].name, buffer);
        printf("Enter conversion factor for %s:\n", units[*numUnits].name);
        scanf("%lf", &units[*numUnits].factor);
        (*numUnits)++;
    }
}

int main() {
    Unit units[MAX_UNITS];
    int numUnits = 0;
    char fromUnit[UNIT_LENGTH];
    char toUnit[UNIT_LENGTH];
    double value;

    printf("Welcome to the Unit Converter!\n\n");
    readUnits(units, &numUnits);

    while (1) {
        printf("\nEnter the unit you want to convert from:\n");
        scanf("%s", fromUnit);
        printf("Enter the unit you want to convert to:\n");
        scanf("%s", toUnit);

        int foundFrom = 0;
        int foundTo = 0;
        for (int i = 0; i < numUnits; i++) {
            if (strcmp(units[i].name, fromUnit) == 0) {
                foundFrom = 1;
            }
            if (strcmp(units[i].name, toUnit) == 0) {
                foundTo = 1;
            }
        }

        if (!foundFrom ||!foundTo) {
            printf("Invalid units.\n");
        } else {
            printf("Enter the value you want to convert:\n");
            scanf("%lf", &value);

            double result = value * units[foundFrom].factor / units[foundTo].factor;

            printf("\n%lf %s = %lf %s\n", value, fromUnit, result, toUnit);
        }
    }

    return 0;
}