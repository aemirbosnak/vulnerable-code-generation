//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

// Structure to hold unit information
typedef struct {
    char name[20];  // Unit name (e.g. "meter")
    double factor;   // Conversion factor (e.g. 1.0 for meter to meter)
} unit_t;

// Array to hold all supported units
unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {" millimeter", 0.001},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"inch", 0.0254},
    {"pound", 0.453592}
};

// Function to convert a value from one unit to another
double convert_value(double value, char from_unit[20], char to_unit[20]) {
    int from_index = 0;
    int to_index = 0;
    double factor = 1.0;

    // Find the index of the from unit and the to unit in the units array
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_index = i;
            break;
        }
    }

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, to_unit) == 0) {
            to_index = i;
            break;
        }
    }

    // Calculate the conversion factor
    factor = units[to_index].factor / units[from_index].factor;

    // Return the converted value
    return value * factor;
}

int main() {
    double value = 5.0;  // Start with a value of 5.0

    // Ask the user for the from unit and to unit
    char from_unit[20];
    char to_unit[20];

    printf("Enter the value in the from unit (e.g. meter): ");
    fgets(from_unit, 20, stdin);

    printf("Enter the to unit (e.g. kilometer): ");
    fgets(to_unit, 20, stdin);

    // Convert the value from the from unit to the to unit
    double converted_value = convert_value(value, from_unit, to_unit);

    // Print the converted value and the conversion factor
    printf("The value of %s is %f %s\n", from_unit, converted_value, to_unit);

    return 0;
}