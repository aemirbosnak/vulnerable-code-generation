//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_CONVERSIONS 5

// Define a struct to hold a unit and its conversion factors
typedef struct unit {
    char name[20];  // Unit name (e.g. "meter", "foot", etc.)
    double conversion[UNIT_CONVERTER_MAX_CONVERSIONS];  // Conversion factors to/from other units
} Unit;

// Define an array to store all the units
Unit units[UNIT_CONVERTER_MAX_UNITS] = {
    {"meter", {1, 100, 1000, 10000, 100000}},  // Meter
    {"foot", {1, 12, 100, 1000, 100000}},  // Foot
    {"inch", {1, 12, 100, 1000, 100000}},  // Inch
    {"yard", {1, 3, 30, 300, 3000}},  // Yard
    {"mile", {1, 1760, 5280, 1609344, 10000000}}  // Mile
};

// Define a function to convert a value from one unit to another
void convert(double value, char from_unit[20], char to_unit[20]) {
    int i, j;
    for (i = 0; i < UNIT_CONVERTER_MAX_CONVERSIONS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            for (j = 0; j < UNIT_CONVERTER_MAX_UNITS; j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    value *= units[i].conversion[j];
                    break;
                }
            }
            break;
        }
    }
}

int main() {
    double value;
    char from_unit[20], to_unit[20];

    // Example usage: convert a value from meter to foot
    printf("Enter a value in meter: ");
    scanf("%lf", &value);
    strcpy(from_unit, "meter");
    strcpy(to_unit, "foot");
    convert(value, from_unit, to_unit);
    printf("The value is %lf feet\n", value);

    // Example usage: convert a value from inch to yard
    printf("Enter a value in inch: ");
    scanf("%lf", &value);
    strcpy(from_unit, "inch");
    strcpy(to_unit, "yard");
    convert(value, from_unit, to_unit);
    printf("The value is %lf yards\n", value);

    return 0;
}