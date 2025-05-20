//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 5

typedef struct unit {
    char name[20];
    double factor;
} Unit;

typedef struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
} Conversion;

Unit units[MAX_UNITS] = {
    {"meter", 1.0},
    {"centimeter", 0.01},
    {"kilometer", 1000.0},
    {"inch", 0.0254},
    {"foot", 0.3048}
};

Conversion conversions[MAX_CONVERSIONS] = {
    {"meter", "centimeter", 100.0},
    {"centimeter", "kilometer", 100000.0},
    {"kilometer", "inch", 39.37007874},
    {"inch", "foot", 12.0},
    {"foot", "meter", 0.3048}
};

int main() {
    int i, j, num_conversions = 0;
    char input_unit[20];
    char output_unit[20];
    double input_value, output_value;

    printf("Enter a value and two units to convert: ");
    scanf("%lf %s %s", &input_value, input_unit, output_unit);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit %s\n", input_unit);
        return 1;
    }

    for (j = 0; j < MAX_CONVERSIONS; j++) {
        if (strcmp(output_unit, conversions[j].from_unit) == 0) {
            break;
        }
    }

    if (j == MAX_CONVERSIONS) {
        printf("Invalid output unit %s\n", output_unit);
        return 1;
    }

    output_value = input_value * conversions[j].factor;

    printf("Value in %s is %lf\n", output_unit, output_value);

    return 0;
}