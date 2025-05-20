//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

struct unit {
    char name[20];
    double factor;
};

struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
};

int main() {
    struct unit units[MAX_UNITS] = {
        {"meter", 1.0},
        {"kilometer", 1000.0},
        {"foot", 0.3048},
        {"yard", 0.9144},
        {"inch", 0.0254}
    };

    struct conversion conversions[MAX_CONVERTIONS] = {
        {"meter", "foot", 3.28084},
        {"kilometer", "mile", 0.621371},
        {"foot", "yard", 1.09361},
        {"yard", "meter", 0.9144}
    };

    char input_unit[20];
    char output_unit[20];
    double input_value;
    double output_value;

    printf("Enter a value in the input unit: ");
    scanf("%lf%19s", &input_value, input_unit);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            output_value = input_value * units[i].factor;
            break;
        }
    }

    for (int i = 0; i < MAX_CONVERTIONS; i++) {
        if (strcmp(output_unit, conversions[i].from_unit) == 0) {
            output_value = output_value / conversions[i].factor;
            break;
        }
    }

    printf("The value in %s is %lf\n", output_unit, output_value);

    return 0;
}