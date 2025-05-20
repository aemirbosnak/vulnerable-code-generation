//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_UNITS 5
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
        {"mi", 1609.34}
    };

    struct conversion conversions[MAX_CONVERSIONS] = {
        {"m", "cm", 0.01},
        {"cm", "mm", 0.001},
        {"mm", "km", 0.00001},
        {"km", "mi", 0.00621371},
        {"mi", "m", 1609.34}
    };

    char input_unit[20];
    char output_unit[20];
    double input_value;
    double output_value;

    while (1) {
        printf("Enter a value in %s: ", units[0].name);
        scanf("%lf", &input_value);

        for (int i = 0; i < MAX_UNITS; i++) {
            if (strcmp(units[i].name, input_unit) == 0) {
                break;
            }
        }

        for (int j = 0; j < MAX_CONVERSIONS; j++) {
            if (strcmp(conversions[j].from_unit, input_unit) == 0) {
                output_value = input_value * conversions[j].factor;
                break;
            }
        }

        if (output_value == 0) {
            printf("Invalid input\n");
            continue;
        }

        printf("Value in %s is %lf\n", output_unit, output_value);

        if (input_unit[0] == '\0') {
            break;
        }

        input_unit[0] = '\0';
    }

    return 0;
}