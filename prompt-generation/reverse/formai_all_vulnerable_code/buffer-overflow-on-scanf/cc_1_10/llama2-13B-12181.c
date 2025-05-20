//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159
#define EULER 2.71828

// Define the units and their conversions
typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.09144},
    {"mi", 1609.344},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"gal", 0.003785},
    {"pt", 0.000625},
    {"cup", 0.002366},
    {"fl oz", 0.0011368},
    {"qt", 0.25},
    {"gal", 0.003785}
};

int main() {
    // Declare variables for user input
    double value, unit_factor;
    char unit_input[20];

    // Print the menu
    printf("Welcome to Unity of Measure!\n");
    printf("Select a unit of measurement and a value to convert:\n");
    printf("Available units: \n");
    for (int i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        printf("%s (%f)\n", units[i].name, units[i].factor);
    }

    // Get the user input
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit of measurement: ");
    fgets(unit_input, 20, stdin);

    // Find the corresponding unit factor
    for (int i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(unit_input, units[i].name) == 0) {
            unit_factor = units[i].factor;
            break;
        }
    }

    // Perform the conversion
    value *= unit_factor;

    // Print the result
    printf("Value in %s: %f\n", unit_input, value);

    return 0;
}