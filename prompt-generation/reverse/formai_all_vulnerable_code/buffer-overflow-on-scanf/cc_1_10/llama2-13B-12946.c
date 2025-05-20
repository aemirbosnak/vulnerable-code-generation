//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define UNIT_COUNT 12

// Define the units and their conversions
typedef struct {
    const char *name;
    double factor;
} unit_t;

static unit_t units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"km", 1000},
    {"g", 0.001},
    {"kg", 1000},
    {"oz", 0.0283495},
    {"lb", 0.45359237},
    {"in", 2.54},
    {"ft", 12},
    {"yd", 36}
};

int main() {
    int i, j;
    double value, converted_value;
    char input_unit[10], output_unit[10];

    // Ask the user for the input value
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Ask the user for the input unit
    printf("Enter the unit of the input value (m/cm/mm/km): ");
    scanf("%s", input_unit);

    // Convert the input value to the requested unit
    for (i = 0; i < UNIT_COUNT; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            converted_value = value * units[i].factor;
            break;
        }
    }

    // Print the converted value and the output unit
    printf("The value in %s is %lf\n", units[i].name, converted_value);

    // Ask the user for the output unit
    printf("Now, do you want to convert to another unit? (y/n): ");
    scanf("%s", output_unit);

    // Loop until the user enters "n"
    while (strcmp(output_unit, "n") != 0) {
        for (j = 0; j < UNIT_COUNT; j++) {
            if (strcmp(output_unit, units[j].name) == 0) {
                converted_value = converted_value * units[j].factor;
                break;
            }
        }
        printf("The value in %s is %lf\n", units[j].name, converted_value);
        printf("Do you want to convert to another unit? (y/n): ");
        scanf("%s", output_unit);
    }

    return 0;
}