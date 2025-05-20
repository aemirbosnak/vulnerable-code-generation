//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_OPERATIONS 5

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[UNIT_CONVERTER_MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34},
    {"yd", 0.9144},
    {"ft", 1.0},
    {"in", 0.0254},
    {"pt", 0.0007087}
};

double convert_unit(unit_t from, unit_t to, double value) {
    if (from.factor == to.factor) {
        return value;
    }

    double result = value * from.factor / to.factor;

    if (from.name == to.name) {
        return result;
    }

    for (int i = 0; i < UNIT_CONVERTER_MAX_OPERATIONS; i++) {
        if (from.name == units[i].name && to.name == units[i + 1].name) {
            result = result * units[i].factor / units[i + 1].factor;
            break;
        }
    }

    return result;
}

int main() {
    char input[50];
    char output[50];

    printf("Enter a value in meters: ");
    fgets(input, 50, stdin);

    double value = atof(input);

    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        printf(" %s: %f", units[i].name, value * units[i].factor);
    }

    printf("\n");

    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        printf(" Convert to %s: ", units[i].name);
        double result = convert_unit(units[i - 1], units[i], value);
        printf("%f\n", result);
    }

    return 0;
}