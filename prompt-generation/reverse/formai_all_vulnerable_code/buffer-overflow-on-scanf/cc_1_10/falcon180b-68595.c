//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define NUM_UNITS 7

typedef struct {
    char symbol[5];
    double factor;
} Unit;

void print_units(Unit units[]) {
    printf("Available units:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%s (%c)\n", units[i].symbol, i + 65);
    }
}

int main() {
    Unit units[NUM_UNITS] = {{"meters", 1}, {"centimeters", 0.01}, {"inches", 0.0254},
                             {"kilograms", 1}, {"grams", 0.001}, {"pounds", 0.453592},
                             {"gallons", 3.78541}};

    char input_unit[5];
    char output_unit[5];
    double input_value;
    int input_unit_index, output_unit_index;

    printf("Enter the input unit: ");
    scanf("%s", input_unit);

    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input_unit, units[i].symbol) == 0) {
            input_unit_index = i;
            break;
        }
    }

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(output_unit, units[i].symbol) == 0) {
            output_unit_index = i;
            break;
        }
    }

    printf("Enter the value to convert: ");
    scanf("%lf", &input_value);

    double result = input_value * units[output_unit_index].factor / units[input_unit_index].factor;

    printf("%.2lf %s = %.2lf %s\n", input_value, input_unit, result, output_unit);

    return 0;
}