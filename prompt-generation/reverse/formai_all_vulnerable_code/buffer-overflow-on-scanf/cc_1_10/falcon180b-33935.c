//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[] = {
        {"m", 1.0},
        {"km", 1000.0},
        {"cm", 0.01},
        {"mm", 0.001},
        {"mi", 160934.4},
        {"yd", 0.9144},
        {"ft", 0.3048},
        {"in", 0.0254},
        {"l", 1.0},
        {"ml", 0.001},
        {"fl oz", 0.0295735},
        {"gal", 3.78541},
        {"kg", 1.0},
        {"g", 0.001},
        {"lb", 0.453592},
        {"oz", 0.0283495},
        {"C", 1.0},
        {"F", 1.8},
        {"K", 1.0},
    };
    int num_units = sizeof(units) / sizeof(units[0]);
    char input_unit[10], output_unit[10];
    double input_value, output_value;

    printf("Enter input unit: ");
    scanf("%s", input_unit);

    printf("Enter output unit: ");
    scanf("%s", output_unit);

    printf("Enter input value: ");
    scanf("%lf", &input_value);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, input_unit) == 0) {
            for (int j = 0; j < num_units; j++) {
                if (strcmp(units[j].name, output_unit) == 0) {
                    output_value = input_value * units[i].factor / units[j].factor;
                    printf("%.2lf %s = %.2lf %s\n", input_value, input_unit, output_value, output_unit);
                    exit(0);
                }
            }
        }
    }

    printf("Invalid input or output unit.\n");

    return 0;
}