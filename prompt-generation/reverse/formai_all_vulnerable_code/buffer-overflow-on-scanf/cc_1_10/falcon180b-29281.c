//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int num_units;
    Unit units[MAX_UNITS];
    char input[100];
    char from_unit[10], to_unit[10];
    double value, result;

    // Initialize units
    units[0] = (Unit) {"m", 1.0};
    units[1] = (Unit) {"km", 1000.0};
    units[2] = (Unit) {"ft", 0.3048};
    units[3] = (Unit) {"in", 0.0254};
    units[4] = (Unit) {"yd", 0.9144};
    units[5] = (Unit) {"mi", 160934.4};
    units[6] = (Unit) {"lb", 0.453592};
    units[7] = (Unit) {"kg", 2.20462};
    units[8] = (Unit) {"gal", 3.78541};
    units[9] = (Unit) {"l", 0.264172};

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the number of units you would like to convert from (1-%d): ", MAX_UNITS - 1);
    scanf("%d", &num_units);

    printf("Enter the units you would like to convert from (e.g. m, km, ft, in, yd, mi, lb, kg, gal, l): ");
    scanf("%s", from_unit);

    printf("Enter the units you would like to convert to (e.g. m, km, ft, in, yd, mi, lb, kg, gal, l): ");
    scanf("%s", to_unit);

    printf("Enter the value you would like to convert: ");
    scanf("%lf", &value);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    result = value * units[j].factor;
                    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}