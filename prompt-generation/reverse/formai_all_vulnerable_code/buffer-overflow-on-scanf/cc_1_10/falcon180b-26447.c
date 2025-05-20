//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"m", 1.0},
    {"km", 1000.0},
    {"cm", 0.01},
    {"in", 0.393701},
    {"ft", 3.28084},
    {"yd", 1.09361},
    {"mi", 160934.4}
};

int main() {
    char input_unit[10];
    char output_unit[10];
    double input_value;
    int input_unit_index, output_unit_index;

    printf("Enter the input unit: ");
    scanf("%s", input_unit);

    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    printf("Enter the value to convert: ");
    scanf("%lf", &input_value);

    input_unit_index = find_unit_index(input_unit);
    output_unit_index = find_unit_index(output_unit);

    if (input_unit_index == -1 || output_unit_index == -1) {
        printf("Invalid unit(s).\n");
        return 1;
    }

    double result = input_value * units[input_unit_index].factor / units[output_unit_index].factor;

    printf("%.2lf %s = %.2lf %s\n", input_value, input_unit, result, output_unit);

    return 0;
}

int find_unit_index(char *unit_name) {
    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            return i;
        }
    }

    return -1;
}