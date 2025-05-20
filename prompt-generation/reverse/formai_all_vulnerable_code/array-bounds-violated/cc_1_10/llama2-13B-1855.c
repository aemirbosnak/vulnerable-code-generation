//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 10

// Structure to hold unit information
typedef struct {
    char name[20];
    double value;
} unit_t;

// Array to hold all units
unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144}
};

// Function to convert between units
double convert_unit(unit_t from, unit_t to) {
    double conversion = 1.0;

    switch (from.name[0]) {
        case 'm':
            conversion = to.value / 1000.0;
            break;
        case 'k':
            conversion = to.value / 100000.0;
            break;
        case 'i':
            conversion = to.value * 25.4;
            break;
        case 'f':
            conversion = to.value * 3.2808;
            break;
        case 'y':
            conversion = to.value * 0.9144;
            break;
        default:
            printf("Invalid unit: %s\n", from.name);
            return 0.0;
    }

    return conversion;
}

// Function to print the conversion
void print_conversion(unit_t from, unit_t to) {
    printf("Conversion: %s (%g) to %s (%g)\n", from.name, from.value, to.name, to.value);
}

int main() {
    srand(time(NULL));

    // Create a list of conversions to perform
    int conversions[MAX_CONVERSIONS] = {
        1, // Convert meter to kilometer
        2, // Convert kilometer to inch
        3, // Convert inch to foot
        4, // Convert foot to yard
        5  // Convert yard to meter
    };

    // Perform the conversions
    for (int i = 0; i < MAX_CONVERSIONS; i++) {
        unit_t from = units[conversions[i] - 1];
        unit_t to = units[conversions[i] % MAX_UNITS];
        double conversion = convert_unit(from, to);

        // Print the conversion
        print_conversion(from, to);

        // Display the result in the correct unit
        printf("Result: %g %s\n", conversion, to.name);
    }

    return 0;
}