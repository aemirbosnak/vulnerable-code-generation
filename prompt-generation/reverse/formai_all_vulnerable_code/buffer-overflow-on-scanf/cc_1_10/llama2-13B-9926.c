//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    const char *name;
    double factor;
} unit_t;

typedef struct conversion {
    const char *from_unit;
    const char *to_unit;
    double factor;
} conversion_t;

static unit_t units[MAX_UNITS] = {
    {"cm", 0.01},
    {"m", 0.001},
    {"km", 0.000001},
    {"mm", 0.0000001},
    {"in", 0.08333333333333333},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 1.609344},
};

static conversion_t conversions[MAX_CONVERTIONS] = {
    {"cm", "m", 0.01},
    {"m", "km", 0.001},
    {"km", "mm", 0.000001},
    {"mm", "in", 0.0000001},
    {"in", "ft", 0.08333333333333333},
    {"ft", "yd", 0.3048},
    {"yd", "mi", 0.9144},
};

int main() {
    int i, j;
    double value;
    char from_unit[32], to_unit[32];

    printf("Enter a value: ");
    scanf("%lf", &value);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, "") == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit\n");
        return 1;
    }

    for (j = 0; j < MAX_CONVERTIONS; j++) {
        if (strcmp(conversions[j].from_unit, units[i].name) == 0) {
            break;
        }
    }

    if (j == MAX_CONVERTIONS) {
        printf("No conversion available\n");
        return 1;
    }

    printf("Value in %s: %f\n", conversions[j].to_unit, value * conversions[j].factor);

    return 0;
}