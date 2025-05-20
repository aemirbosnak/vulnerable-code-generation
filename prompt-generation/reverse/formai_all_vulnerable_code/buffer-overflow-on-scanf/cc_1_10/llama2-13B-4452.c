//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

// Structure to store unit and its conversion factors
typedef struct {
    char *name;
    double factor;
} unit_t;

// Array to store all units and their conversion factors
unit_t units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.9144},
    {"mi", 1609.34},
    {"km", 0.001},
    {"lb", 0.453592},
    {"oz", 0.0283495}
};

// Function to perform unit conversion
double convert_unit(unit_t from, unit_t to, double value) {
    int i = 0;
    for (i = 0; i < MAX_UNITS; i++) {
        if (units[i].name == from.name) break;
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit %s\n", from.name);
        return 0;
    }
    for (; i < MAX_UNITS; i++) {
        if (units[i].name == to.name) break;
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit %s\n", to.name);
        return 0;
    }
    return value * units[i].factor / units[i - 1].factor;
}

int main() {
    double value, converted_value;
    char from_unit[50], to_unit[50];

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (m, cm, mm, ft, in, yd, mi, km): ");
    gets(from_unit);

    printf("Enter the unit to convert to (m, cm, mm, ft, in, yd, mi, km): ");
    gets(to_unit);

    converted_value = convert_unit(units[0], units[1], value);
    printf("Value in %s is %lf\n", to_unit, converted_value);

    return 0;
}