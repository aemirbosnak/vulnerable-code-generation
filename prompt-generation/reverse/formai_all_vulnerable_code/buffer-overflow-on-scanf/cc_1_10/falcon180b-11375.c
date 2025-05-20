//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define UNIT_LENGTH 10

typedef struct {
    char name[UNIT_LENGTH];
    double factor;
} Unit;

Unit units[] = {
    {"meter", 1},
    {"centimeter", 0.01},
    {"millimeter", 0.001},
    {"kilometer", 1000},
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 160934.4},
    {"liter", 1},
    {"milliliter", 0.001},
    {"gallon", 3.78541},
    {"ounce", 0.0295735},
    {"pound", 0.453592},
    {"gram", 1},
    {"kilogram", 1000},
    {"second", 1},
    {"minute", 60},
    {"hour", 3600},
    {"day", 86400},
    {"week", 604800},
    {"month", 2592000},
    {"year", 31536000}
};

int main() {
    char input_unit[UNIT_LENGTH], output_unit[UNIT_LENGTH];
    double input_value, output_value;

    // Get user input for unit conversion
    printf("Enter input unit: ");
    scanf("%s", input_unit);

    printf("Enter input value: ");
    scanf("%lf", &input_value);

    // Get user input for output unit
    printf("Enter output unit: ");
    scanf("%s", output_unit);

    // Find the input and output units in the units array
    int input_unit_index = -1, output_unit_index = -1;
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(units[i].name, input_unit) == 0) {
            input_unit_index = i;
        }
        if (strcmp(units[i].name, output_unit) == 0) {
            output_unit_index = i;
        }
    }

    // Convert the input value to the output unit
    if (input_unit_index == -1 || output_unit_index == -1) {
        printf("Invalid unit!\n");
        return 1;
    }
    else {
        output_value = input_value * units[output_unit_index].factor / units[input_unit_index].factor;
        printf("%.2lf %s = %.2lf %s\n", input_value, input_unit, output_value, output_unit);
    }

    return 0;
}