//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_UNITS 5

typedef struct Unit {
    char name[20];
    double conversion_factor;
} Unit;

Unit units[MAX_CONVERT_UNITS] = {
    {"Mile", 1.613},
    {"Yard", 1.093},
    {"Meter", 1},
    {"Centimeter", 0.01},
    {"Millimeter", 0.001}
};

int main() {
    int i, source_unit, target_unit;
    double value;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the source unit: ");
    scanf("%d", &source_unit);

    printf("Enter the target unit: ");
    scanf("%d", &target_unit);

    if (source_unit < 0 || source_unit >= MAX_CONVERT_UNITS || target_unit < 0 || target_unit >= MAX_CONVERT_UNITS) {
        printf("Invalid unit selection.\n");
        return 1;
    }

    for (i = 0; i < MAX_CONVERT_UNITS; i++) {
        if (units[i].name[0] == units[source_unit].name[0] && units[i].name[1] == units[source_unit].name[1]) {
            source_unit = i;
        }

        if (units[i].name[0] == units[target_unit].name[0] && units[i].name[1] == units[target_unit].name[1]) {
            target_unit = i;
        }
    }

    double converted_value = value * units[source_unit].conversion_factor / units[target_unit].conversion_factor;

    printf("The converted value is: %.2lf %s.\n", converted_value, units[target_unit].name);

    return 0;
}