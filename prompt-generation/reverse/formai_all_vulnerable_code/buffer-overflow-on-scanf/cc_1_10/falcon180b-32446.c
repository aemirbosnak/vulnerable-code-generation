//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_UNITS 5

typedef struct {
    char *name;
    double factor;
} Unit;

void print_units(Unit units[]) {
    int i;
    for (i = 0; i < NUM_UNITS; i++) {
        printf("%s\t", units[i].name);
    }
    printf("\n");
}

int main() {
    Unit units[NUM_UNITS] = {{"meters", 1}, {"feet", 3.28084}, {"inches", 39.3701}, {"kilograms", 1}, {"pounds", 2.20462}};
    char input_unit[20];
    char output_unit[20];
    double value;

    printf("Enter the value to be converted:\n");
    scanf("%lf", &value);

    printf("Enter the input unit:\n");
    scanf("%s", input_unit);

    printf("Enter the output unit:\n");
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

    double result = value * units[input_unit_index].factor / units[output_unit_index].factor;

    printf("Result: %.2lf %s = %.2lf %s\n", value, input_unit, result, output_unit);

    return 0;
}