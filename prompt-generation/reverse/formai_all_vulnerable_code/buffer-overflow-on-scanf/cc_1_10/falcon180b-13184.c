//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 10

struct unit {
    char symbol[5];
    double value;
};

int main() {
    char input[50];
    char from_unit[5], to_unit[5];
    double value;
    int i, j, from_index, to_index;

    // Initialize units array
    struct unit units[MAX_UNITS] = {{"m", 1.0}, {"cm", 0.01}, {"mm", 0.001}, {"in", 0.0254}, {"ft", 0.3048}, {"yd", 0.9144}, {"mi", 160934.4}, {"kg", 1.0}, {"g", 0.001}, {"lb", 0.453592}};

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit you are converting from: ");
    scanf("%s", from_unit);

    printf("Enter the unit you are converting to: ");
    scanf("%s", to_unit);

    // Find indices of from_unit and to_unit in units array
    from_index = -1;
    to_index = -1;
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].symbol, from_unit) == 0) {
            from_index = i;
        }
        if (strcmp(units[i].symbol, to_unit) == 0) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        printf("Invalid units entered.\n");
        return 1;
    }

    // Convert value from from_unit to to_unit
    value = value * units[from_index].value / units[to_index].value;

    // Print result
    printf("%.2lf %s = %.2lf %s\n", value, to_unit, value, from_unit);

    return 0;
}