//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define supported units and their conversion factors
typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[] = {
    {"m", 1},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934},
    {"l", 1},
    {"ml", 0.001},
    {"gal", 3.785},
    {"kg", 1},
    {"g", 0.001},
    {"lb", 0.453},
    {"oz", 0.028},
    {"C", 1},
    {"F", 1.8},
};

// Function to validate unit input
bool validate_unit(char *unit) {
    for (int i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(unit, units[i].name) == 0) {
            return true;
        }
    }
    return false;
}

// Function to convert between units
double convert(double value, char *from_unit, char *to_unit) {
    for (int i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            for (int j = 0; j < sizeof(units) / sizeof(units[0]); j++) {
                if (strcmp(to_unit, units[j].name) == 0) {
                    return value * units[i].factor / units[j].factor;
                }
            }
        }
    }
    return 0;
}

int main() {
    // Prompt user for input
    char from_unit[10], to_unit[10];
    printf("Enter the unit you want to convert from: ");
    scanf("%s", from_unit);
    printf("Enter the unit you want to convert to: ");
    scanf("%s", to_unit);
    double value;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    // Validate input
    if (!validate_unit(from_unit) ||!validate_unit(to_unit)) {
        printf("Invalid unit.\n");
        return 1;
    }

    // Convert and display result
    double result = convert(value, from_unit, to_unit);
    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);
    return 0;
}