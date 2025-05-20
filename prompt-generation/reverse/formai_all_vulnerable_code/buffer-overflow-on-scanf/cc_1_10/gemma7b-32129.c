//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592653

typedef struct _conversion_unit {
    char name[20];
    double multiplier;
    double offset;
} conversion_unit;

conversion_unit units[] = {
    {"Mile", 1609.34, 0},
    {"Yard", 914.4, 0},
    {"Foot", 12, 0},
    {"Meter", 1, 0},
    {"Centimeter", 100, 0},
    {"Millimeter", 1000, 0}
};

int main() {
    double value;
    char from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit: ");
    scanf(" %c", &from_unit);

    printf("Enter the to unit: ");
    scanf(" %c", &to_unit);

    conversion_unit *unit = NULL;
    for (int i = 0; i < sizeof(units) / sizeof(conversion_unit); i++) {
        if (units[i].name[0] == from_unit && units[i].name[0] == to_unit) {
            unit = &units[i];
            break;
        }
    }

    if (unit) {
        double converted_value = value * unit->multiplier + unit->offset;
        printf("The converted value is: %.2lf %s", converted_value, unit->name);
    } else {
        printf("Error: Invalid units");
    }

    return 0;
}