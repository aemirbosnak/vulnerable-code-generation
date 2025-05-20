//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

// Define unit conversion factors
struct unit_conversion {
    char *name;
    double factor;
};

struct unit_conversion units[MAX_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"grams", 1.0},
    {"kilograms", 1000.0},
    {"liters", 1.0},
    {"milliliters", 0.001},
    {"seconds", 1.0},
    {"minutes", 60.0},
    {"hours", 3600.0},
    {"days", 86400.0}
};

int main() {
    char input[100];
    char output_unit[100];
    double value, result;
    int i, num_units;

    // Get user input
    printf("Enter a value to convert: ");
    scanf("%lf", &value);
    printf("Enter the input unit: ");
    scanf("%s", input);

    // Find the input unit in the list of units
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid input unit.\n");
        return 1;
    }

    // Get the output unit from the user
    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    // Find the output unit in the list of units
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(output_unit, units[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid output unit.\n");
        return 1;
    }

    // Convert the value
    result = value * units[i].factor / units[0].factor;

    // Print the result
    printf("%.2lf %s = %.2lf %s\n", value, input, result, output_unit);

    return 0;
}