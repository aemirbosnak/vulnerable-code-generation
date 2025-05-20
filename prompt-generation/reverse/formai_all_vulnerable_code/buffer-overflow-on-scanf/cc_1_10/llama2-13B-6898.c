//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: optimized
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
        {"m", 1.0},
        {"cm", 0.01},
        {"mm", 0.001},
        {"ft", 0.3048},
        {"in", 0.0254},
        {"yd", 0.9144},
        {"mi", 1609.344}
    };

    struct conversion conversions[MAX_CONVERTIONS] = {
        {"m", "ft", 3.28084},
        {"ft", "in", 12},
        {"in", "yd", 0.10971},
        {"yd", "mi", 1609.344}
    };

    char input_unit[20];
    char output_unit[20];
    double input_value;
    double output_value;

    while (1) {
        printf("Enter a value in a unit: ");
        scanf("%lf %19s", &input_value, input_unit);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(units[i].name, input_unit) == 0) {
                output_value = input_value * units[i].factor;
                break;
            }
        }

        if (output_value == 0) {
            printf("Invalid unit or value\n");
            continue;
        }

        for (int j = 0; j < MAX_CONVERTIONS; j++) {
            if (strcmp(conversions[j].from_unit, input_unit) == 0) {
                output_value = output_value / conversions[j].factor;
                break;
            }
        }

        if (output_value == 0) {
            printf("No conversion possible\n");
            continue;
        }

        printf("Value in %s is %f\n", output_unit, output_value);
    }

    return 0;
}