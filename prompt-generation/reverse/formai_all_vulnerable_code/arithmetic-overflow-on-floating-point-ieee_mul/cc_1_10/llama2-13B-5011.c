//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_OPERATIONS 5

typedef struct {
    char *name;
    double value;
} unit_t;

unit_t units[UNIT_CONVERTER_MAX_UNITS] = {
    {"m", 1},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.344},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.9144},
    {"lg", 0.254},
    {"oz", 0.0283168}
};

void init_units(void) {
    int i;
    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        units[i].value = pow(10, (i * 3) / 2);
    }
}

void convert_units(unit_t *from, unit_t *to) {
    double value = from->value * to->value;
    from->value = value / from->value;
    to->value = value;
}

void convert_units_multi(unit_t *from, unit_t *to, int operations) {
    int i, j;
    for (i = 0; i < operations; i++) {
        for (j = 0; j < UNIT_CONVERTER_MAX_UNITS; j++) {
            if (from->name == units[j].name) {
                convert_units(from, units + j);
                break;
            }
        }
        from = units + j;
    }
}

int main(void) {
    init_units();

    unit_t from, to;
    from.name = "ft";
    from.value = 5;
    to.name = "m";

    convert_units_multi(&from, &to, 3);

    printf("5 ft is equal to %f m\n", to.value);

    return 0;
}