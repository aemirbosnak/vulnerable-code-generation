//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_VALUE 10000

struct unit_converter {
    char *name;
    double factor;
};

struct unit_converter units[UNIT_CONVERTER_MAX_UNITS] = {
    {"cm", 0.01},
    {"m", 0.1},
    {"km", 100},
    {"mm", 0.001},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.9144},
    {"mi", 1609.344},
    {"lb", 0.453592},
    {"oz", 0.0283495}
};

void init_units(void) {
    int i;
    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        units[i].factor = 1;
    }
}

double convert_unit(char *from_unit, char *to_unit) {
    int from_idx = 0;
    int to_idx = 0;
    double value = 0;

    for (from_idx = 0; from_unit[from_idx] != '\0'; from_idx++) {
        if (from_unit[from_idx] == ' ') {
            continue;
        }
        break;
    }

    for (to_idx = 0; to_unit[to_idx] != '\0'; to_idx++) {
        if (to_unit[to_idx] == ' ') {
            continue;
        }
        break;
    }

    value = atof(from_unit + from_idx) * units[to_idx].factor;

    return value;
}

int main() {
    srand(time(NULL));

    init_units();

    printf("Welcome to the Unit Converter! \n");

    char from_unit[20];
    char to_unit[20];

    printf("Enter a value in %s: ", "cm");
    fgets(from_unit, 20, stdin);

    printf("Enter a unit to convert to: ");
    fgets(to_unit, 20, stdin);

    double value = convert_unit(from_unit, to_unit);

    printf("The value in %s is %f\n", to_unit, value);

    return 0;
}