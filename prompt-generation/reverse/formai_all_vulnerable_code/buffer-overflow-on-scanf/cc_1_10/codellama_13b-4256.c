//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: surprised
/*
 * Unique C Unit Converter Example Program
 *
 * This program takes input from the user and converts it from one unit to another.
 * The program supports the following units:
 * - Distance (km, mi, m, cm, mm)
 * - Weight (kg, lb, g)
 * - Temperature (C, F, K)
 * - Time (s, min, h)
 */

#include <stdio.h>
#include <string.h>

// Define the struct for the unit converter
typedef struct {
    char unit[10];
    float conversion_factor;
} Unit;

// Define the units supported by the program
Unit units[] = {
    {"km", 1.0},
    {"mi", 0.621371},
    {"m", 0.001},
    {"cm", 100.0},
    {"mm", 1000.0},
    {"kg", 1.0},
    {"lb", 2.20462},
    {"g", 0.001},
    {"C", 1.0},
    {"F", 1.8},
    {"K", 0.0},
    {"s", 1.0},
    {"min", 0.016667},
    {"h", 0.0002777778}
};

// Define the number of units supported by the program
int num_units = sizeof(units) / sizeof(units[0]);

// Define the function to convert the input value
void convert_value(float value, char* from_unit, char* to_unit) {
    // Find the from and to unit indices in the units array
    int from_index = -1, to_index = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].unit, from_unit) == 0) {
            from_index = i;
        }
        if (strcmp(units[i].unit, to_unit) == 0) {
            to_index = i;
        }
    }

    // Check if the from and to units are valid
    if (from_index == -1 || to_index == -1) {
        printf("Invalid units provided\n");
        return;
    }

    // Convert the value from the from unit to the to unit
    float converted_value = value * units[to_index].conversion_factor / units[from_index].conversion_factor;

    // Print the converted value
    printf("%.2f %s = %.2f %s\n", value, from_unit, converted_value, to_unit);
}

// Define the main function
int main() {
    // Take input from the user
    float value;
    char from_unit[10], to_unit[10];
    printf("Enter the value: ");
    scanf("%f", &value);
    printf("Enter the from unit (e.g. km): ");
    scanf("%s", from_unit);
    printf("Enter the to unit (e.g. mi): ");
    scanf("%s", to_unit);

    // Convert the value
    convert_value(value, from_unit, to_unit);

    return 0;
}