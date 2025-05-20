//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_CONVERSIONS 5

struct unit_converter {
    const char *name;
    double factor;
};

static struct unit_converter unit_converters[UNIT_CONVERTER_MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.9144},
    {"mi", 1609.344},
    {"kg", 0.001},
    {"g", 0.000001},
    {"oz", 0.0283168}
};

int main() {
    int i, j;
    double value, converted_value;
    char input_unit[20], output_unit[20];

    srand(time(NULL));

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("Enter a value: ");
        scanf("%lf", &value);

        for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
            if (strcmp(input_unit, unit_converters[i].name) == 0) {
                break;
            }
        }

        for (j = i + 1; j < UNIT_CONVERTER_MAX_UNITS; j++) {
            if (strcmp(unit_converters[j].name, output_unit) == 0) {
                converted_value = value * unit_converters[i].factor / unit_converters[j].factor;
                printf("Value in %s is %lf\n", output_unit, converted_value);
                break;
            }
        }

        printf("Invalid input. Please try again.\n");
    } while (1);

    return 0;
}