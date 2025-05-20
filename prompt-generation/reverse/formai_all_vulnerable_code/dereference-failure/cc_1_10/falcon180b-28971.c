//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define NUM_UNITS 7

typedef struct unit {
    char *name;
    double factor;
} unit_t;

unit_t units[NUM_UNITS] = {
    {"meters", 1.0},
    {"feet", 3.28084},
    {"inches", 39.3701},
    {"kilograms", 1.0},
    {"pounds", 2.20462},
    {"gallons", 3.78541},
    {"liters", 1.0}
};

void print_units(void) {
    int i;

    printf("Available units:\n");
    for (i = 0; i < NUM_UNITS; i++) {
        printf("%s (%s)\n", units[i].name, units[i].name);
    }
}

void convert(double value, int from_unit, int to_unit) {
    double result = value * units[from_unit].factor / units[to_unit].factor;

    printf("%.2f %s = %.2f %s\n", value, units[from_unit].name, result, units[to_unit].name);
}

int main(int argc, char *argv[]) {
    int from_unit, to_unit;
    double value;

    if (argc < 5) {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        print_units();
        return 1;
    }

    value = atof(argv[1]);
    from_unit = atoi(argv[2]);
    to_unit = atoi(argv[3]);

    if (from_unit < 0 || from_unit >= NUM_UNITS || to_unit < 0 || to_unit >= NUM_UNITS) {
        printf("Invalid unit.\n");
        print_units();
        return 1;
    }

    convert(value, from_unit, to_unit);

    return 0;
}