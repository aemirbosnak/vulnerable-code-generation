//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_MAX 10
#define UNIT_NAME_LEN 20

typedef struct unit {
    char name[UNIT_NAME_LEN];
    double factor;
} unit_t;

unit_t units[UNIT_MAX] = {
    {"cm", 100.0},
    {"m", 1000.0},
    {"km", 100000.0},
    {"mm", 1.0},
    {"inch", 2.54},
    {"ft", 12.0},
    {"yd", 36.0},
    {"mile", 1609.344},
    {"kg", 0.001},
    {"g", 0.01},
    {"ton", 1000.0}
};

int main() {
    int i, j, num_units;
    double value, converted_value;
    char input_unit[UNIT_NAME_LEN];
    char output_unit[UNIT_NAME_LEN];

    printf("Welcome to the Unit Converter!\n");

    // Get the number of units the user wants to convert
    printf("Enter the number of units you want to convert: ");
    scanf("%d", &num_units);

    // Loop through the units and convert each one
    for (i = 0; i < num_units; i++) {
        // Get the input unit and value
        printf("Enter the value and unit (e.g. 5 cm): ");
        scanf("%lf %s", &value, input_unit);

        // Find the corresponding unit struct
        for (j = 0; j < UNIT_MAX; j++) {
            if (strcmp(units[j].name, input_unit) == 0) {
                break;
            }
        }

        // Convert the value to the output unit
        converted_value = value * units[j].factor;

        // Print the converted value and unit
        printf("The value of %s is %lf %s\n", input_unit, converted_value, units[j].name);
    }

    return 0;
}