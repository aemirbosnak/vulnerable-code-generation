//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

// Structure to store units and conversions
typedef struct {
    char *name;
    double factor;
} unit_t;

// Array to store units and conversions
unit_t units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.344}
};

// Function to convert between units
double convert(unit_t from, unit_t to) {
    return from.factor * (to.factor / from.factor);
}

// Function to print the conversions
void print_conversions(unit_t from, unit_t to) {
    printf("%s (%s) is equal to %s (%s)\n", from.name, from.name, to.name, to.name);
}

int main() {
    // Get the input from the user
    char from_unit[20];
    char to_unit[20];
    double value;

    printf("Enter a value and the unit you want to convert from: ");
    scanf("%lf%s", &value, from_unit);

    // Convert the value to the desired unit
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            value = convert(units[i], units[i]);
            break;
        }
    }

    // Print the conversions
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            print_conversions(units[i], units[i]);
        }
    }

    return 0;
}