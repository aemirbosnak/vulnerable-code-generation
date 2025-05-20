//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

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
        {"m", 1.0},
        {"cm", 0.01},
        {"mm", 0.001},
        {"km", 1000.0},
        {"mi", 1609.34},
        {"yd", 0.9144},
        {"ft", 1.0},
        {"in", 0.0254},
        {"pt", 0.0007087},
        {"gal", 3.785},
    };

    struct conversion conversions[MAX_CONVERSIONS] = {
        {"m", "ft", 3.28084},
        {"cm", "in", 0.393701},
        {"mm", "pt", 0.0254},
        {"km", "mi", 0.621371},
        {"mi", "yd", 1760.0},
        {"yd", "ft", 3},
        {"in", "ft", 0.125},
        {"pt", "in", 0.00625},
        {"gal", "l", 3785.0},
    };

    int unit_index, conversion_index;
    double value, factor;
    char input[50], output[50];

    while (1) {
        printf("Enter a unit: ");
        fgets(input, 50, stdin);
        unit_index = strcmp(input, "q") - strcmp(input, " quit");
        if (unit_index == 0) break;

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(units[i].name, input) == 0) {
                value = atof(input);
                factor = units[i].factor;
                break;
            }
        }

        if (factor == 0) {
            printf("Invalid unit\n");
            continue;
        }

        printf("Enter a conversion: ");
        fgets(input, 50, stdin);
        conversion_index = strcmp(input, "q") - strcmp(input, " quit");
        if (conversion_index == 0) break;

        for (int i = 0; i < MAX_CONVERSIONS; i++) {
            if (strcmp(conversions[i].from_unit, input) == 0) {
                factor = conversions[i].factor;
                break;
            }
        }

        if (factor == 0) {
            printf("Invalid conversion\n");
            continue;
        }

        sprintf(output, "%.2f %s", value * factor, conversions[conversion_index].to_unit);
        printf("Result: %s\n", output);
    }

    return 0;
}