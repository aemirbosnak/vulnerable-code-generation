//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to store unit information
struct unit {
    char name[20];  // Unit name (e.g. "centimeters", "kilograms", etc.)
    double conversion_factor;  // Conversion factor to convert from base unit to this unit
};

// Declare an array to store all available units
struct unit units[10] = {
    {"centimeters", 1.0},
    {"meters", 100.0},
    {"kilometers", 100000.0},
    {"grams", 0.01},
    {"kilograms", 1.0},
    {"ounces", 0.0283495},
    {"pounds", 16.018437},
    {"feet", 0.3048},
    {"yards", 0.9144},
    {"inches", 0.02777777777777778}
};

// Declare a function to convert a value from one unit to another
void convert(double value, struct unit from_unit, struct unit to_unit) {
    // Calculate the conversion factor
    double conversion_factor = from_unit.conversion_factor / to_unit.conversion_factor;

    // Convert the value
    double converted_value = value * conversion_factor;

    // Print the converted value and the unit
    printf("%.2f %s\n", converted_value, to_unit.name);
}

// Declare a function to print the available units
void print_units() {
    int i;
    for (i = 0; i < sizeof(units) / sizeof(struct unit); i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
}

int main() {
    // Print the available units
    print_units();

    // Get the input from the user
    double value;
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Get the input for the from unit
    char from_unit_name[20];
    printf("Enter the unit to convert from (e.g. 'centimeters'): ");
    scanf("%19s", from_unit_name);

    // Get the input for the to unit
    char to_unit_name[20];
    printf("Enter the unit to convert to (e.g. 'kilograms'): ");
    scanf("%19s", to_unit_name);

    // Find the structs for the from and to units
    int from_unit_index = 0;
    for (int i = 0; i < sizeof(units) / sizeof(struct unit); i++) {
        if (strcmp(units[i].name, from_unit_name) == 0) {
            from_unit_index = i;
            break;
        }
    }

    int to_unit_index = 0;
    for (int i = 0; i < sizeof(units) / sizeof(struct unit); i++) {
        if (strcmp(units[i].name, to_unit_name) == 0) {
            to_unit_index = i;
            break;
        }
    }

    // Convert the value
    convert(value, units[from_unit_index], units[to_unit_index]);

    return 0;
}