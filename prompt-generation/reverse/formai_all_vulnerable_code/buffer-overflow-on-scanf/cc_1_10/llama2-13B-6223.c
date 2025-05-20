//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: dynamic
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
        {"km", 1000.0},
        {"mi", 1609.34},
    };

    struct conversion conversions[MAX_CONVERTIONS] = {
        {"m", "cm", 0.01},
        {"cm", "mm", 0.001},
        {"mm", "m", 1.0},
        {"m", "km", 0.001},
        {"km", "mi", 0.621371},
    };

    char input_unit[20];
    char output_unit[20];
    double input_value;
    double output_value;

    printf("Enter a value: ");
    scanf("%lf", &input_value);

    printf("Enter the unit (m, cm, mm, km, mi): ");
    fgets(input_unit, 20, stdin);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input_unit) == 0) {
            input_value *= units[i].factor;
            break;
        }
    }

    for (int i = 0; i < MAX_CONVERTIONS; i++) {
        if (strcmp(conversions[i].from_unit, input_unit) == 0) {
            output_value = input_value * conversions[i].factor;
            output_value /= conversions[i].factor;
            break;
        }
    }

    printf("Value in %s is %lf\n", output_unit, output_value);

    return 0;
}