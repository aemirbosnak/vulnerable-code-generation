//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_CONVERSIONS 10

struct unit_converter {
    char *name;
    double factor;
};

struct unit_converter unit_converters[UNIT_CONVERTER_MAX_UNITS] = {
    {"cm", 1},
    {"m", 10},
    {"km", 100},
    {"mm", 0.1},
    {"in", 2.54},
    {"ft", 12},
    {"yd", 36},
    {"mi", 1609.34},
    {"pt", 0.0283464},
    {"lb", 0.453592}
};

int main() {
    int i, j;
    double value, converted_value;
    char input_unit[20], output_unit[20];

    printf("Welcome to the Unit Converter! Please enter a value to convert: ");
    scanf("%lf", &value);

    printf("Now, please enter the unit you want to convert from: ");
    fgets(input_unit, 20, stdin);
    input_unit[strcspn(input_unit, "\n")] = 0; // ignore the newline character

    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(input_unit, unit_converters[i].name) == 0) {
            converted_value = value * unit_converters[i].factor;
            printf("The value in %s is %lf\n", unit_converters[i].name, converted_value);
            break;
        }
    }

    if (i == UNIT_CONVERTER_MAX_UNITS) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    printf("Now, please enter the unit you want to convert to: ");
    fgets(output_unit, 20, stdin);
    output_unit[strcspn(output_unit, "\n")] = 0; // ignore the newline character

    for (j = 0; j < UNIT_CONVERTER_MAX_UNITS; j++) {
        if (strcmp(output_unit, unit_converters[j].name) == 0) {
            converted_value = converted_value / unit_converters[j].factor;
            printf("The value in %s is %lf\n", output_unit, converted_value);
            break;
        }
    }

    if (j == UNIT_CONVERTER_MAX_UNITS) {
        printf("Invalid unit. Please try again.\n");
        return 1;
    }

    return 0;
}