//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUM_UNITS 7
#define INPUT_BUFFER_SIZE 100

struct unit_conversion {
    char *name;
    double factor;
};

struct unit_conversion units[NUM_UNITS] = {
    {"meters", 1.0},
    {"feet", 0.3048},
    {"inches", 0.0254},
    {"kilograms", 1.0},
    {"pounds", 2.20462},
    {"gallons", 3.78541},
    {"liters", 1.0}
};

int main() {
    char input_buffer[INPUT_BUFFER_SIZE];
    char *unit_from;
    char *unit_to;
    double value;
    int from_unit_index;
    int to_unit_index;

    printf("Enter a value to convert:\n");
    fgets(input_buffer, INPUT_BUFFER_SIZE, stdin);

    // Extract the value from the input string
    sscanf(input_buffer, "%lf", &value);

    // Extract the units from the input string
    unit_from = strtok(input_buffer, " ");
    unit_to = strtok(NULL, " ");

    // Find the indices of the input and output units in the units array
    from_unit_index = -1;
    to_unit_index = -1;
    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_from, units[i].name) == 0) {
            from_unit_index = i;
        } else if (strcmp(unit_to, units[i].name) == 0) {
            to_unit_index = i;
        }
    }

    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("Invalid input units or output units.\n");
        return 1;
    }

    // Perform the conversion
    double result = value * units[from_unit_index].factor / units[to_unit_index].factor;

    printf("%.2lf %s is equal to %.2lf %s.\n", value, unit_from, result, unit_to);

    return 0;
}