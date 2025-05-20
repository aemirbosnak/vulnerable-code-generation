//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UNIT_COUNT 12

struct unit {
    char name[20];
    double factor;
};

static struct unit units[UNIT_COUNT] = {
    {"inch", 2.54},
    {"foot", 12 * 2.54},
    {"yard", 3 * 2.54},
    {"mile", 1760 * 2.54},
    {"centimeter", 0.01},
    {"meter", 100},
    {"kilometer", 100000},
    {"gram", 0.001},
    {"kilogram", 1000},
    {"ounce", 0.0283495},
    {"pound", 16 * 0.0283495},
    {"ton", 2000 * 0.0283495}
};

void init_units() {
    srand(time(NULL));
    for (int i = 0; i < UNIT_COUNT; i++) {
        units[i].factor = (double)rand() / RAND_MAX;
    }
}

void convert(double value, char *from_unit, char *to_unit) {
    for (int i = 0; i < UNIT_COUNT; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            value *= units[i].factor;
            break;
        }
    }
    for (int i = 0; i < UNIT_COUNT; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            value /= units[i].factor;
            break;
        }
    }
    printf("%.2f %s = %.2f %s\n", value, from_unit, value, to_unit);
}

int main() {
    init_units();
    double value = 4.5;
    char from_unit[] = "foot";
    char to_unit[] = "meter";
    convert(value, from_unit, to_unit);
    return 0;
}