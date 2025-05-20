//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: retro
// Welcome to the Retro Unit Converter!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define valid units
const char* units[] = { "km", "m", "cm", "mm", "in", "ft", "yd", "mi" };
const int num_units = sizeof(units) / sizeof(char*);

// Define conversion factors
const double conversion_factors[] = { 1000.0, 1.0, 0.01, 0.001, 25.4, 0.3048, 0.9144, 1609.34 };

// Main function
int main() {
    // Print welcome message
    printf("\nWelcome to the Retro Unit Converter!\n");

    // Get user input
    printf("Enter the value you want to convert: ");
    double value;
    scanf("%lf", &value);

    char unit_from[20];
    printf("Enter the unit of the value (e.g., km, m, cm, mm, in, ft, yd, mi): ");
    scanf("%s", unit_from);

    char unit_to[20];
    printf("Enter the unit you want to convert to (e.g., km, m, cm, mm, in, ft, yd, mi): ");
    scanf("%s", unit_to);

    // Find conversion factor
    int index_from = -1;
    int index_to = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(unit_from, units[i]) == 0) {
            index_from = i;
        }
        if (strcmp(unit_to, units[i]) == 0) {
            index_to = i;
        }
    }

    // Convert value
    double converted_value;
    if (index_from != -1 && index_to != -1) {
        converted_value = value * conversion_factors[index_from] / conversion_factors[index_to];
    } else {
        printf("Error: Invalid unit entered\n");
        return 1;
    }

    // Print converted value
    printf("\nConverted value: %.2f %s\n", converted_value, unit_to);

    // Exit
    return 0;
}