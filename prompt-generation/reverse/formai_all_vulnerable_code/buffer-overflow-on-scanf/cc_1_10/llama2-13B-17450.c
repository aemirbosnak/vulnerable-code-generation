//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_CONVERTIONS 5

typedef struct unit_conversion_t {
    const char *name;
    double factor;
} unit_conversion_t;

static unit_conversion_t unit_conversions[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"km", 1000.0},
    {"mm", 0.001},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.9144},
    {"mi", 1609.344},
    {"nm", 1852.496},
    {"pt", 0.0003048},
};

int main() {
    double value, conversion_factor = 1.0;
    char unit[10];

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter a unit (m/cm/km/mm/ft/in/yd/mi/nm): ");
    fgets(unit, 10, stdin);

    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(unit, unit_conversions[i].name) == 0) {
            conversion_factor = unit_conversions[i].factor;
            break;
        }
    }

    if (conversion_factor == 1.0) {
        printf("Invalid unit. Please enter a valid unit.\n");
        return 1;
    }

    printf("Value in %s: %g\n", unit, value * conversion_factor);

    return 0;
}