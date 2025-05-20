//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    char input[100];
    char from_unit[10], to_unit[10];
    double value, result;
    int i, from_index, to_index;
    Unit units[MAX_UNITS];

    // Initialize units
    units[0].name = "meter";
    units[0].factor = 1.0;

    units[1].name = "kilometer";
    units[1].factor = 1000.0;

    units[2].name = "gram";
    units[2].factor = 1.0;

    units[3].name = "kilogram";
    units[3].factor = 1000.0;

    units[4].name = "liter";
    units[4].factor = 1.0;

    units[5].name = "milliliter";
    units[5].factor = 0.001;

    units[6].name = "second";
    units[6].factor = 1.0;

    units[7].name = "minute";
    units[7].factor = 60.0;

    units[8].name = "hour";
    units[8].factor = 3600.0;

    units[9].name = "degree Celsius";
    units[9].factor = 1.0;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    // Find the indices of the input and output units
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_index = i;
        }
        if (strcmp(units[i].name, to_unit) == 0) {
            to_index = i;
        }
    }

    // Convert the value
    if (from_index == -1 || to_index == -1) {
        printf("Invalid units.\n");
        return 1;
    }
    result = value * units[from_index].factor / units[to_index].factor;

    // Print the result
    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}