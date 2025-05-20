//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_VALUE 10000

struct unit {
    char name[20];
    double factor;
};

struct unit units[MAX_UNITS] = {
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1.609344},
    {"kilogram", 0.001},
    {"gram", 0.001},
    {"pound", 0.00220462},
    {"ounce", 0.0283495},
    {"fluid_ounce", 0.02365882},
    {"cup", 0.236588237}
};

double convert(double value, char from_unit, char to_unit) {
    int i = 0;
    for (i = 0; i < MAX_UNITS; i++) {
        if (from_unit == units[i].name && to_unit == units[i + 1].name) {
            break;
        }
    }
    return value * units[i].factor / units[i + 1].factor;
}

int main() {
    double value, from_unit, to_unit;

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from (inch, foot, yard, mile, etc.): ");
    scanf("%s", &from_unit);

    printf("Enter the unit you want to convert to (inch, foot, yard, mile, etc.): ");
    scanf("%s", &to_unit);

    printf("The value is: %f %s\n", convert(value, from_unit, to_unit), from_unit);

    return 0;
}