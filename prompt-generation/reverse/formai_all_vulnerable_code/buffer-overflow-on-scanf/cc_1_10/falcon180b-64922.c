//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    char input[100];
    char from_unit[10], to_unit[10];
    double value, result;
    int i, from_unit_index, to_unit_index;

    // Initialize units
    Unit units[MAX_UNITS] = {
        {"meter", 1.0},
        {"kilometer", 1000.0},
        {"gram", 1.0},
        {"kilogram", 1000.0},
        {"liter", 1.0},
        {"milliliter", 0.001},
        {"second", 1.0},
        {"minute", 60.0},
        {"hour", 3600.0},
        {"degree Celsius", 1.0}
    };

    // Get input
    printf("Enter value to convert: ");
    scanf("%lf", &value);
    printf("Enter from unit: ");
    scanf("%s", from_unit);
    printf("Enter to unit: ");
    scanf("%s", to_unit);

    // Find indices of from and to units
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_unit_index = i;
            break;
        }
    }
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            to_unit_index = i;
            break;
        }
    }

    // Convert value
    result = value * units[from_unit_index].factor / units[to_unit_index].factor;

    // Print result
    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}