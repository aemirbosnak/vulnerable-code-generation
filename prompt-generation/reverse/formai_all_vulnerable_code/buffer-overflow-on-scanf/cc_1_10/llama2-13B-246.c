//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

struct unit {
    char *name;
    double factor;
};

static struct unit units[] = {
    {"inch", 1},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"centimeter", 0.01},
    {"meter", 0.001},
    {"kilometer", 0.000001},
    {"pound", 0.000453592},
    {"ounce", 0.000283495},
    {"ton", 2000},
    {"gram", 0.001},
    {"kilogram", 0.001},
    {"mile/hour", 0.000694444},
    {"meter/second", 0.000277778},
    {"kilometer/hour", 0.0000694444},
    {"degree_celsius", 0.01},
    {"degree_fahrenheit", 0.017555556},
};

void convert(double value, char *from_unit, char *to_unit) {
    int i;
    for (i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            value *= units[i].factor;
            break;
        }
    }
    if (i == sizeof(units) / sizeof(units[0]) && value != 0) {
        fprintf(stderr, "Invalid unit: %s\n", from_unit);
        return;
    }
    if (to_unit) {
        value /= units[i].factor;
        strcpy(to_unit, units[i].name);
    }
}

int main() {
    double value;
    char from_unit[20];
    char to_unit[20];

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (e.g. 'inch'): ");
    fgets(from_unit, sizeof(from_unit), stdin);

    printf("Enter the unit to convert to (e.g. 'meter'): ");
    fgets(to_unit, sizeof(to_unit), stdin);

    convert(value, from_unit, to_unit);

    printf("Result: %f %s\n", value, to_unit);

    return 0;
}