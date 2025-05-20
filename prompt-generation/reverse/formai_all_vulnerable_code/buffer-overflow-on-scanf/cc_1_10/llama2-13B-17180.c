//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 6
#define MAX_VALUE 1000000000

// Structure to hold unit information
typedef struct {
    char name[20];  // Unit name (e.g. "meter", "kilogram", etc.)
    double factor;   // Conversion factor (e.g. 1000 for meters to kilometers)
} unit_t;

// Array to hold all available units
unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"gram", 0.001},
    {"kilogram", 1000.0},
    {"liter", 0.001},
    {"cubic meter", 1000000.0}
};

// Function to convert a value from one unit to another
double convert(double value, unit_t from, unit_t to) {
    return value * to.factor / from.factor;
}

int main() {
    // Prompt user for input
    printf("Enter a value: ");
    double value;
    scanf("%lf", &value);

    // Loop through available units and display conversion options
    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s (%.2f %s): ", i + 1, units[i].name, value * units[i].factor, units[i].name);
        if (value * units[i].factor < MAX_VALUE) {
            printf(" (%.2f %s)\n", value * units[i].factor, units[i].name);
        } else {
            printf(" (%.2f %s)\n", value * units[i].factor, units[i].name);
        }
    }

    // Get user input and convert value
    int unit_choice;
    printf("Enter the number of the unit you want to convert to: ");
    scanf("%d", &unit_choice);
    unit_t to_unit = units[unit_choice - 1];
    double converted_value = convert(value, units[0], to_unit);

    // Print final conversion result
    printf("Value in %s: %.2f\n", to_unit.name, converted_value);

    return 0;
}