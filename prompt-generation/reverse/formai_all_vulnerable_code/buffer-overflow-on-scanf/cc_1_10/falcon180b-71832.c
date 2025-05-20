//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit;

unit units[MAX_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"centimeters", 0.01},
    {"millimeters", 0.001},
    {"inches", 0.0254},
    {"feet", 0.3048},
    {"yards", 0.9144},
    {"miles", 160934.4},
    {"pounds", 0.453592},
    {"kilograms", 2.20462}
};

int main() {
    int num_units, i;
    char input_unit[20], output_unit[20];
    double value, result;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the input unit: ");
    scanf("%s", input_unit);

    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    num_units = 0;
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            num_units++;
            break;
        }
    }

    if (num_units == 0) {
        printf("Invalid input unit.\n");
        exit(1);
    }

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(output_unit, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%.2lf %s = %.2lf %s\n", value, input_unit, result, units[i].name);
            break;
        }
    }

    return 0;
}