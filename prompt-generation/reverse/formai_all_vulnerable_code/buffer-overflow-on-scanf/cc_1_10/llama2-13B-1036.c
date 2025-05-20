//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

struct unit {
    const char *name;
    double factor;
};

static struct unit units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"km", 1000},
    {"mm", 0.001},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.9144},
    {"mi", 1609.344},
    {"pt", 0.0006944},
    {"lb", 0.453592}
};

int main() {
    double value, factor = 1.0;
    char unit_in[20], unit_out[20];
    int i, j;

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit of measurement (m, cm, km, mm, ft, in, yd, mi, pt, lb): ");
    fgets(unit_in, sizeof(unit_in), stdin);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(unit_in, units[i].name) == 0) {
            factor = units[i].factor;
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit of measurement. Please try again.\n");
        return 1;
    }

    for (j = 0; j < MAX_CONVERSIONS; j++) {
        if (j == 0) {
            printf("Value in %s: %f\n", unit_in, value * factor);
        } else {
            printf("Value in %s: %f\n", units[j].name, value * factor);
        }

        value = value * factor;
        factor = 1.0;

        if (j < MAX_CONVERSIONS - 1) {
            factor = units[j + 1].factor;
        }
    }

    return 0;
}