//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_DIGITS 10

typedef struct unit_t {
    char name[20];
    double factor;
} unit_t;

unit_t units[UNIT_CONVERTER_MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.09144},
    {"lb", 0.453592},
    {"oz", 0.0283495}
};

void unit_converter_init(void);
void unit_converter_cleanup(void);
double unit_converter_convert(const char* from_unit, const char* to_unit, double value);

int main(void) {
    unit_converter_init();

    double value = 5.0;
    double result = unit_converter_convert("m", "ft", value);
    printf("5.0 meters is equal to %f feet\n", result);

    result = unit_converter_convert("oz", "lb", 10.0);
    printf("10.0 ounces is equal to %f pounds\n", result);

    unit_converter_cleanup();
    return 0;
}

void unit_converter_init(void) {
    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        units[i].factor = pow(10, (i * 3) / 10);
    }
}

void unit_converter_cleanup(void) {
    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        units[i].factor = 1.0;
    }
}

double unit_converter_convert(const char* from_unit, const char* to_unit, double value) {
    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            value *= units[i].factor;
            break;
        }
    }

    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            value /= units[i].factor;
            break;
        }
    }

    return value;
}