//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure for a unit of measurement
typedef struct {
    char name[20];   // Unit name (e.g. "meter", "kilogram", "second")
    double conversion_factor; // Conversion factor to base units (e.g. 1000 for meters to centimeters)
} unit_t;

// Define an array of units
unit_t units[] = {
    {"meter", 1.0},
    {"kilogram", 1000.0},
    {"second", 1.0},
    {"celsius", 100.0},
    {"fahrenheit", 180.0},
    {"inch", 2.54},
    {"pound", 453.592},
    {"minute", 60.0},
    {"hour", 3600.0},
    {"mile", 1609.344},
    {"foot", 0.3048},
    {"yard", 0.9144}
};

// Define a function to convert between units
void convert(unit_t from, unit_t to, double value) {
    double conversion_factor = from.conversion_factor / to.conversion_factor;
    value *= conversion_factor;
    printf("%.2f %s = %.2f %s\n", value, from.name, value, to.name);
}

int main() {
    double value;
    char unit_input[20];

    // Prompt user for value and unit
    printf("Enter a value: ");
    scanf("%lf", &value);
    printf("Enter a unit (e.g. meter, kilogram, second): ");
    fgets(unit_input, 20, stdin);

    // Find the unit in the array
    int i = 0;
    for (; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(unit_input, units[i].name) == 0) break;
    }

    // Convert the value to the selected unit
    if (i != sizeof(units) / sizeof(units[0])) {
        convert(units[i - 1], units[i], value);
    } else {
        printf("Invalid unit\n");
    }

    return 0;
}