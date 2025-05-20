//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double factor;
} Unit;

typedef struct conversion {
    char from[20];
    char to[20];
    double factor;
} Conversion;

int main() {
    Unit units[MAX_UNITS] = {
        {"m", 1.0},
        {"cm", 0.01},
        {"mm", 0.001},
        {"km", 1000.0},
        {"mi", 1609.344}
    };

    Conversion conversions[MAX_CONVERTIONS] = {
        {"m", "cm", 0.01},
        {"m", "mm", 0.001},
        {"cm", "mm", 0.0001},
        {"km", "m", 1000.0},
        {"mi", "m", 1609.344}
    };

    int unit_index, conversion_index;
    double value, factor;

    printf("Enter a value: ");
    scanf("%lf", &value);

    for (unit_index = 0; unit_index < MAX_UNITS; unit_index++) {
        if (value == units[unit_index].factor) {
            break;
        }
    }

    if (unit_index == MAX_UNITS) {
        printf("Invalid unit\n");
        return 1;
    }

    for (conversion_index = 0; conversion_index < MAX_CONVERTIONS; conversion_index++) {
        if (value == conversions[conversion_index].factor) {
            break;
        }
    }

    if (conversion_index == MAX_CONVERTIONS) {
        printf("No conversion available\n");
        return 1;
    }

    factor = conversions[conversion_index].factor;
    printf("Value in %s is %g\n", conversions[conversion_index].from, value * factor);

    return 0;
}