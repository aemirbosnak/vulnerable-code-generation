//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

// Structure to store unit information
typedef struct {
    char name[20];  // Unit name
    double factor;  // Conversion factor
} unit_t;

// Array to store unit information
unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.344}
};

// Function to perform conversions
void convert(double value, char *from_unit, char *to_unit) {
    int i = 0;
    double factor = 1.0;

    // Find the from unit in the array
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            break;
        }
    }

    // If the from unit is not found, print an error message
    if (i == MAX_UNITS) {
        printf("Error: Unknown unit '%s'.\n", from_unit);
        return;
    }

    // Calculate the conversion factor
    factor = units[i].factor;

    // Convert the value to the target unit
    value *= factor;

    // Print the converted value and the new unit
    printf("%.2f %s = %.2f %s\n", value, to_unit, value, from_unit);
}

int main() {
    double value;
    char from_unit[20];
    char to_unit[20];

    // Get the value to convert
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Get the from and to units
    printf("Enter the from unit (e.g. meter): ");
    fgets(from_unit, 20, stdin);
    printf("Enter the to unit (e.g. kilometer): ");
    fgets(to_unit, 20, stdin);

    // Perform the conversion
    convert(value, from_unit, to_unit);

    return 0;
}