//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_NAME_LENGTH 50
#define MAX_CONVERSION_FACTOR_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double conversionFactor;
} Unit;

int main() {
    char input[MAX_NAME_LENGTH];
    double value;
    char fromUnit[MAX_NAME_LENGTH];
    char toUnit[MAX_NAME_LENGTH];
    Unit units[MAX_UNITS];
    int numUnits = 0;

    printf("Enter the name of the first unit: ");
    scanf("%s", input);
    strcpy(units[numUnits].name, input);
    numUnits++;

    while (1) {
        printf("Enter the conversion factor for '%s' (or type 'done' to finish): ", input);
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        } else {
            units[numUnits - 1].conversionFactor = atof(input);
            numUnits++;
        }
    }

    while (1) {
        printf("Enter the value you want to convert: ");
        scanf("%lf", &value);

        printf("Enter the unit you want to convert from: ");
        scanf("%s", fromUnit);

        printf("Enter the unit you want to convert to: ");
        scanf("%s", toUnit);

        for (int i = 0; i < numUnits; i++) {
            if (strcmp(fromUnit, units[i].name) == 0 && strcmp(toUnit, units[i].name)!= 0) {
                value *= units[i].conversionFactor;
            } else if (strcmp(fromUnit, units[i].name)!= 0 && strcmp(toUnit, units[i].name) == 0) {
                value /= units[i].conversionFactor;
            }
        }

        printf("The converted value is: %.2lf\n", value);
    }

    return 0;
}