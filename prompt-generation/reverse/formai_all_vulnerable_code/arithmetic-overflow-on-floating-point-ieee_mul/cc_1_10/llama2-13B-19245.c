//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

struct unit {
    const char *name;
    double value;
};

struct conversion {
    const char *from_unit;
    const char *to_unit;
    double factor;
};

static struct unit units[MAX_UNITS] = {
    {"cm", 10.0},
    {"m", 100.0},
    {"km", 100000.0},
    {"mm", 1.0},
    {"yd", 0.9144},
    {"ft", 1.0},
    {"in", 0.0254},
    {"pt", 0.000010},
    {"gal", 0.001634},
    {"fl oz", 0.00001634}
};

static struct conversion conversions[MAX_CONVERSIONS] = {
    {"cm", "m", 100.0},
    {"m", "km", 0.1},
    {"ft", "in", 12.0},
    {"in", "pt", 0.00083333},
    {"gal", "fl oz", 0.0001634}
};

void init_units(void) {
    int i;
    for (i = 0; i < MAX_UNITS; i++) {
        units[i].value = pow(10, i * 2);
    }
}

void init_conversions(void) {
    int i, j;
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        for (j = 0; j < MAX_UNITS; j++) {
            conversions[i].from_unit = units[j].name;
            conversions[i].to_unit = units[j].name;
            conversions[i].factor = pow(10, (i * 2) + (j * 2));
        }
    }
}

double convert(const char *from_unit, const char *to_unit) {
    int i, j;
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        if (strcmp(from_unit, conversions[i].from_unit) == 0) {
            for (j = 0; j < MAX_UNITS; j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    return conversions[i].factor * units[j].value;
                }
            }
        }
    }
    return -1;
}

int main(void) {
    srand(time(NULL));
    init_units();
    init_conversions();

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("Enter a unit to convert: ");
        char unit[50];
        fgets(unit, 50, stdin);

        printf("Enter a value for the unit: ");
        double value;
        scanf("%lf", &value);

        printf("Converting %s to: ", unit);
        double converted_value = convert(unit, "m");
        if (converted_value != -1) {
            printf("%.2f meters\n", converted_value);
        } else {
            printf("Invalid conversion\n");
        }
    }

    return 0;
}