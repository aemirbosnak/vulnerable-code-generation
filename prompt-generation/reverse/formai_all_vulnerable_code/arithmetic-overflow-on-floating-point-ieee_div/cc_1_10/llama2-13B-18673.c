//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

// Global variables
float units[MAX_UNITS][MAX_CONVERTIONS];
int num_units = 0;
int current_unit = 0;

void init_units() {
    units[0][0] = 1; // Initialize unit 0 with 1 as the base value
    units[1][0] = 10; // Initialize unit 1 with 10 as the base value
    units[2][0] = 100; // Initialize unit 2 with 100 as the base value
    units[3][0] = 1000; // Initialize unit 3 with 1000 as the base value
    units[4][0] = 10000; // Initialize unit 4 with 10000 as the base value
    units[5][0] = 100000; // Initialize unit 5 with 100000 as the base value
}

void add_unit(int unit_num, float value) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached (%d)\n", MAX_UNITS);
        return;
    }

    units[num_units][0] = value;
    num_units++;
}

void convert_unit(int from_unit, int to_unit) {
    if (from_unit < 0 || from_unit >= MAX_UNITS) {
        printf("Error: Invalid from unit (%d)\n", from_unit);
        return;
    }

    if (to_unit < 0 || to_unit >= MAX_UNITS) {
        printf("Error: Invalid to unit (%d)\n", to_unit);
        return;
    }

    if (from_unit == to_unit) {
        printf("No conversion needed. Value remains the same.\n");
        return;
    }

    // Calculate the conversion factor
    float factor = units[to_unit][0] / units[from_unit][0];

    // Apply the conversion
    for (int i = 1; i < MAX_CONVERTIONS; i++) {
        units[from_unit][i] *= factor;
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    init_units();

    int unit_num = 0;
    float value = 42.0; // Start with a random value

    while (unit_num < 5) {
        int from_unit = rand() % MAX_UNITS;
        int to_unit = rand() % MAX_UNITS;

        // Add the unit to the list
        add_unit(from_unit, value);

        // Convert the unit
        convert_unit(from_unit, to_unit);

        // Print the converted value
        printf("Unit %d converted to unit %d: %f\n", from_unit, to_unit, units[to_unit][0]);

        unit_num++;
    }

    return 0;
}