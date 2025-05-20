//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

// Declare a struct to store unit information
typedef struct {
    char name[50];  // Unit name
    double factor;  // Conversion factor
} unit_t;

// Declare an array to store unit information
unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"centimeter", 0.01},
    {"kilometer", 1000.0},
    {" millimeter", 0.001},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"kilometer", 1000.0}
};

// Declare a function to perform conversions
void convert(double value, char *from_unit, char *to_unit) {
    int i, j;
    double factor;

    // Find the from unit in the array
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) break;
    }

    // If the from unit is not found, print an error message and exit
    if (i == MAX_UNITS) {
        printf("Error: Unknown unit %s\n", from_unit);
        return;
    }

    // Find the to unit in the array
    for (j = 0; j < MAX_UNITS; j++) {
        if (strcmp(units[j].name, to_unit) == 0) break;
    }

    // If the to unit is not found, print an error message and exit
    if (j == MAX_UNITS) {
        printf("Error: Unknown unit %s\n", to_unit);
        return;
    }

    // Calculate the conversion factor
    factor = units[i].factor / units[j].factor;

    // Perform the conversion
    value *= factor;

    // Print the converted value and the units
    printf("%.2f %s = %.2f %s\n", value, from_unit, value, to_unit);
}

int main() {
    double value;
    char from_unit[50], to_unit[50];

    // Prompt the user for input
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Prompt the user for the from unit
    printf("Enter the from unit (e.g. meter): ");
    fgets(from_unit, 50, stdin);

    // Prompt the user for the to unit
    printf("Enter the to unit (e.g. kilometer): ");
    fgets(to_unit, 50, stdin);

    // Perform the conversion
    convert(value, from_unit, to_unit);

    return 0;
}