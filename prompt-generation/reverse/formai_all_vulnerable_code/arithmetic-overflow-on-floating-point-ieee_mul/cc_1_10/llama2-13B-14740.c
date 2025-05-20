//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_LENGTH 1024
#define UNIT_CONVERTER_PRECISION 3

struct unit_converter {
    char name[UNIT_CONVERTER_MAX_LENGTH];
    double factor;
};

static struct unit_converter unit_converters[10] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"mi", 1609.344},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.09144},
    {"lb", 0.453592},
    {"oz", 0.0283495}
};

void unit_converter_init(void) {
    int i;
    for (i = 0; i < sizeof(unit_converters) / sizeof(unit_converters[0]); i++) {
        unit_converters[i].factor = pow(10, (i * UNIT_CONVERTER_PRECISION));
    }
}

double unit_converter_convert(const char *from_unit, const char *to_unit, double value) {
    int from_index = 0;
    int to_index = 0;
    double factor = 1.0;

    while (from_index < sizeof(unit_converters) / sizeof(unit_converters[0]) && to_index < sizeof(unit_converters) / sizeof(unit_converters[0])) {
        if (strcmp(unit_converters[from_index].name, from_unit) == 0) {
            from_index++;
            break;
        }
    }

    if (from_index == sizeof(unit_converters) / sizeof(unit_converters[0])) {
        printf("Invalid from unit: %s\n", from_unit);
        return 0.0;
    }

    while (to_index < sizeof(unit_converters) / sizeof(unit_converters[0]) && strcmp(unit_converters[to_index].name, to_unit) != 0) {
        to_index++;
    }

    if (to_index == sizeof(unit_converters) / sizeof(unit_converters[0])) {
        printf("Invalid to unit: %s\n", to_unit);
        return 0.0;
    }

    factor = unit_converters[from_index].factor / unit_converters[to_index].factor;

    return value * factor;
}

int main(void) {
    unit_converter_init();

    double value = 5.0;
    char from_unit[] = "m";
    char to_unit[] = "ft";

    double converted_value = unit_converter_convert(from_unit, to_unit, value);

    printf("Value in %s is %f\n", to_unit, converted_value);

    return 0;
}