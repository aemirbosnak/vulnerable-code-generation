//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_UNITS 7

struct unit {
    char name[10];
    double factor;
};

void print_units(struct unit units[]) {
    printf("Available units:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%s\n", units[i].name);
    }
}

int main() {
    struct unit units[NUM_UNITS] = {
        {"meters", 1},
        {"feet", 0.3048},
        {"inches", 0.0254},
        {"kilograms", 1},
        {"pounds", 2.20462},
        {"grams", 0.001},
        {"ounces", 0.035274}
    };

    char input_unit[10];
    char output_unit[10];

    printf("Enter input unit: ");
    scanf("%s", input_unit);

    printf("Enter output unit: ");
    scanf("%s", output_unit);

    int input_unit_index = -1;
    int output_unit_index = -1;

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(units[i].name, input_unit) == 0) {
            input_unit_index = i;
        }
        if (strcmp(units[i].name, output_unit) == 0) {
            output_unit_index = i;
        }
    }

    if (input_unit_index == -1 || output_unit_index == -1) {
        printf("Invalid unit.\n");
        return 1;
    }

    double input, output;

    printf("Enter value to convert: ");
    scanf("%lf", &input);

    output = input * units[output_unit_index].factor / units[input_unit_index].factor;

    printf("%.2lf %s = %.2lf %s\n", input, input_unit, output, output_unit);

    return 0;
}