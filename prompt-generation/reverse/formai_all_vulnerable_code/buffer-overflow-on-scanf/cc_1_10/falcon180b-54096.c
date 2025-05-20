//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_UNITS 10

// Define the units and their corresponding values
typedef struct {
    char name[10];
    double value;
} Unit;

Unit units[MAX_UNITS] = {
    {"m", 1.0},
    {"km", 1000.0},
    {"cm", 0.01},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"mi", 160934.4},
    {"yd", 0.9144},
    {"mm", 0.001},
    {"kg", 1.0},
    {"lb", 0.453592}
};

int main() {
    int choice;
    double value, result;
    char unit[10];

    // Get the user's input
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from: ");
    scanf("%s", unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", unit);

    // Find the indices of the input units
    int from_index = -1;
    int to_index = -1;
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, unit) == 0) {
            if (from_index == -1) {
                from_index = i;
            } else if (to_index == -1) {
                to_index = i;
            }
        }
    }

    // Check if the input units are valid
    if (from_index == -1 || to_index == -1) {
        printf("Invalid unit.\n");
        return 1;
    }

    // Convert the value
    result = value * units[from_index].value / units[to_index].value;

    // Print the result
    printf("%.3lf %s = %.3lf %s\n", value, unit, result, units[to_index].name);

    return 0;
}