//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"cm", 100},
    {"m", 1000},
    {"km", 1000000},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"kg", 0.001}
};

int main() {
    int i, j;
    double value, converted_value;
    char input_unit[20];
    char output_unit[20];

    printf("Welcome to the Unit Converter!\n");

    // Convert a value from one unit to another
    printf("Enter a value: ");
    scanf("%lf", &value);
    printf("Enter the unit you want to convert from (e.g. 'inch'): ");
    scanf("%19s", input_unit);
    printf("Enter the unit you want to convert to (e.g. 'foot'): ");
    scanf("%19s", output_unit);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit %s\n", input_unit);
        return 1;
    }

    converted_value = value * units[i].factor;

    for (j = 0; j < MAX_CONVERSIONS; j++) {
        if (strcmp(output_unit, units[j].name) == 0) {
            break;
        }
    }

    if (j == MAX_CONVERSIONS) {
        printf("Invalid unit %s\n", output_unit);
        return 1;
    }

    converted_value = converted_value / units[j].factor;

    printf("The value of %s is %f %s\n", input_unit, converted_value, output_unit);

    return 0;
}

// Function to convert a value from one unit to another
double convert_unit(double value, char *from_unit, char *to_unit) {
    int i, j;
    double factor;

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit %s\n", from_unit);
        return 0;
    }

    factor = units[i].factor;

    for (j = 0; j < MAX_CONVERSIONS; j++) {
        if (strcmp(to_unit, units[j].name) == 0) {
            break;
        }
    }

    if (j == MAX_CONVERSIONS) {
        printf("Invalid unit %s\n", to_unit);
        return 0;
    }

    return value * factor / units[j].factor;
}