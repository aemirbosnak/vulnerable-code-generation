//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: artistic
// The Great Uniter
// A C Unit Converter Extravaganza

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_COUNT 12
#define UNIT_NAMES \
    "inch", "foot", "yard", "mile", \
    "centimeter", "meter", "kilometer", \
    "pound", "ounce", "ton", "kilo"

// Define the unit conversion table
const double unit_conversion[UNIT_COUNT][UNIT_COUNT] = {
    // Length
    {1, 12, 36, 5280, 100, 1000, 3048, 50000},
    // Weight
    {1, 16, 48, 640, 10, 100, 400, 4000},
    // Volume
    {1, 2, 4, 8, 16, 32, 64, 1024},
    // Speed
    {1, 3.6, 10.8, 100.8, 3600, 10000, 30688, 1000000}
};

// Function to convert units
void unit_convert(double value, int from_unit, int to_unit) {
    double converted_value = value;
    int i, j;

    for (i = 0; i < UNIT_COUNT; i++) {
        if (from_unit == UNIT_NAMES[i]) {
            for (j = 0; j < UNIT_COUNT; j++) {
                if (to_unit == UNIT_NAMES[j]) {
                    converted_value = converted_value * unit_conversion[i][j];
                    break;
                }
            }
            break;
        }
    }

    printf("Converted value: %f %s\n", converted_value, UNIT_NAMES[to_unit]);
}

int main() {
    double value;

    // Ask user for input
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Prompt user for unit selection
    printf("Select a unit: ");
    int unit = 0;
    while (unit < UNIT_COUNT) {
        printf("%d. %s\n", unit + 1, UNIT_NAMES[unit]);
        if (scanf("%d", &unit) == 1) {
            break;
        }
    }

    // Convert value to selected unit
    unit_convert(value, unit, UNIT_COUNT - 1);

    return 0;
}