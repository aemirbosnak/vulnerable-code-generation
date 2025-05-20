//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_CONVERTER_MAX_LENGTH 100

// Define the available units and their corresponding symbols
typedef struct unit_t {
    char symbol[5];    // symbol for the unit (e.g. "cm", "m", "km")
    double conversion_factor;  // conversion factor for the unit (e.g. 100 for cm to m)
} unit_t;

// Define a list of available units
unit_t units[] = {
    {"cm", 100},
    {"m", 1},
    {"km", 100000},
    {"mm", 0.01},
    {"mi", 1609.34},
    {"yd", 0.9144},
    {"ft", 0.3048},
    {"in", 0.0254}
};

// Define a function to convert a value from one unit to another
void convert_value(double value, unit_t from_unit, unit_t to_unit) {
    double conversion_factor = from_unit.conversion_factor / to_unit.conversion_factor;
    value *= conversion_factor;
}

// Define a function to print the converted value and the original value
void print_converted_value(double value, unit_t from_unit, unit_t to_unit) {
    printf("%.2f %s = %.2f %s\n", value, from_unit.symbol, value / from_unit.conversion_factor, to_unit.symbol);
}

int main() {
    // Get the input value and the from unit
    double value = atof(getenv("USER_INPUT"));
    char from_unit_symbol[5];
    gets(from_unit_symbol);

    // Find the from unit in the list of available units
    int from_unit_index = -1;
    for (int i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(from_unit_symbol, units[i].symbol) == 0) {
            from_unit_index = i;
            break;
        }
    }

    // Check if the from unit was found
    if (from_unit_index == -1) {
        printf("Invalid unit\n");
        return 1;
    }

    // Get the to unit
    char to_unit_symbol[5];
    gets(to_unit_symbol);

    // Find the to unit in the list of available units
    int to_unit_index = -1;
    for (int i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(to_unit_symbol, units[i].symbol) == 0) {
            to_unit_index = i;
            break;
        }
    }

    // Check if the to unit was found
    if (to_unit_index == -1) {
        printf("Invalid unit\n");
        return 1;
    }

    // Convert the value and print the result
    convert_value(value, units[from_unit_index], units[to_unit_index]);
    print_converted_value(value, units[from_unit_index], units[to_unit_index]);

    return 0;
}