//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_VERSION "1.2.3"
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
    {"mile", 1760},
    {"cm", 100},
    {"m", 1000},
    {"km", 1000000},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"kg", 0.001},
    {"g", 0.001}
};

void init_units(void);
void convert_unit(double value, char *from_unit, char *to_unit);
void print_units(void);

int main(void) {
    init_units();

    double value = 5.5;
    char from_unit[] = "inch";
    char to_unit[] = "cm";

    convert_unit(value, from_unit, to_unit);

    print_units();

    return 0;
}

void init_units(void) {
    for (int i = 0; i < MAX_UNITS; i++) {
        units[i].factor = pow(10, i * 3);
    }
}

void convert_unit(double value, char *from_unit, char *to_unit) {
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            value *= units[i].factor;
            break;
        }
    }

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            value /= units[i].factor;
            break;
        }
    }
}

void print_units(void) {
    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%s: %f\n", units[i].name, units[i].factor);
    }
}