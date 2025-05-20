//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 10
#define MAX_CONVERSION_LENGTH 10
#define MAX_INPUT_LENGTH 50

typedef struct unit {
    char symbol[MAX_UNITS];
    double value;
} Unit;

typedef struct conversion {
    char from_unit[MAX_UNITS];
    char to_unit[MAX_UNITS];
    double factor;
} Conversion;

int main() {
    char input[MAX_INPUT_LENGTH];
    int choice, num_units, num_conversions;
    Unit units[MAX_UNITS];
    Conversion conversions[MAX_CONVERSIONS];
    int i, j, k;
    double value, converted_value;
    char from_unit[MAX_UNITS], to_unit[MAX_UNITS];

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the unit you want to convert from: ");
    scanf("%s", input);
    strcpy(from_unit, input);

    printf("Please enter the unit you want to convert to: ");
    scanf("%s", input);
    strcpy(to_unit, input);

    num_units = 1;
    printf("Please enter the value to convert: ");
    scanf("%lf", &value);

    for (i = 0; i < num_units; i++) {
        printf("Please enter the symbol for unit %d: ", i+1);
        scanf("%s", units[i].symbol);
        printf("Please enter the value of unit %s: ", units[i].symbol);
        scanf("%lf", &units[i].value);
    }

    printf("Please enter the number of conversions you want to perform: ");
    scanf("%d", &num_conversions);

    for (i = 0; i < num_conversions; i++) {
        printf("Please enter the from unit for conversion %d: ", i+1);
        scanf("%s", from_unit);
        printf("Please enter the to unit for conversion %d: ", i+1);
        scanf("%s", to_unit);
        printf("Please enter the conversion factor for %s to %s: ", from_unit, to_unit);
        scanf("%lf", &conversions[i].factor);
    }

    printf("Please enter the number of conversions you want to perform: ");
    scanf("%d", &num_conversions);

    for (i = 0; i < num_conversions; i++) {
        for (j = 0; j < num_units; j++) {
            if (strcmp(from_unit, units[j].symbol) == 0) {
                for (k = 0; k < num_units; k++) {
                    if (strcmp(to_unit, units[k].symbol) == 0) {
                        converted_value = value * conversions[i].factor;
                        printf("%.2lf %s = %.2lf %s\n", value, units[j].symbol, converted_value, units[k].symbol);
                    }
                }
            }
        }
    }

    return 0;
}