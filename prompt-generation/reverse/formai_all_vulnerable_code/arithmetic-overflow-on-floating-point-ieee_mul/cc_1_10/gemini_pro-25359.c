//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the unit types
typedef enum {
    UNIT_METER,
    UNIT_CENTIMETER,
    UNIT_INCH,
    UNIT_FOOT,
    UNIT_YARD,
    UNIT_MILE,
    UNIT_KILOMETER
} unit_type;

// Define the conversion factors
const double conversion_factors[][UNIT_KILOMETER + 1] = {
    {1.0, 0.01, 0.393701, 0.3048, 0.9144, 1609.34, 1000.0},
    {100.0, 1.0, 39.3701, 30.48, 91.44, 160934.0, 100000.0},
    {2.54, 0.0254, 1.0, 0.0833333, 0.254, 40233.6, 25400.0},
    {3.28084, 0.0328084, 12.0, 1.0, 3.0, 5280.0, 3280.84},
    {1.09361, 0.0109361, 3.93701, 0.333333, 1.0, 1760.0, 1093.61},
    {0.000621371, 0.00000621371, 0.0000249085, 0.000189394, 0.000568182, 1.0, 0.621371},
    {0.001, 0.00001, 0.000393701, 0.0003048, 0.0009144, 1.60934, 1.0}
};

// Define the unit names
const char *unit_names[] = {
    "meter",
    "centimeter",
    "inch",
    "foot",
    "yard",
    "mile",
    "kilometer"
};

// Print the conversion table
void print_conversion_table() {
    printf("Conversion table:\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("| From | To | Meter | Centimeter | Inch | Foot | Yard | Mile | Kilometer |\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    for (int from_unit = UNIT_METER; from_unit <= UNIT_KILOMETER; from_unit++) {
        for (int to_unit = UNIT_METER; to_unit <= UNIT_KILOMETER; to_unit++) {
            printf("| %5s | %5s | %8.6f | %11.8f | %6.4f | %6.4f | %6.4f | %6.4f | %9.6f |\n",
                unit_names[from_unit], unit_names[to_unit],
                conversion_factors[from_unit][to_unit], conversion_factors[from_unit][to_unit] * 100.0,
                conversion_factors[from_unit][to_unit] * 39.3701, conversion_factors[from_unit][to_unit] * 32.8084,
                conversion_factors[from_unit][to_unit] * 10.9361, conversion_factors[from_unit][to_unit] * 1.60934,
                conversion_factors[from_unit][to_unit] * 1000.0);
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
    }
}

// Convert a value from one unit to another
double convert_unit(double value, unit_type from_unit, unit_type to_unit) {
    return value * conversion_factors[from_unit][to_unit];
}

// Get the unit type from the user
unit_type get_unit_type(const char *unit_name) {
    for (int i = UNIT_METER; i <= UNIT_KILOMETER; i++) {
        if (strcmp(unit_name, unit_names[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Get the value from the user
double get_value() {
    double value;
    printf("Enter the value: ");
    scanf("%lf", &value);
    return value;
}

// Get the from unit from the user
unit_type get_from_unit() {
    char unit_name[20];
    printf("Enter the from unit: ");
    scanf("%s", unit_name);
    return get_unit_type(unit_name);
}

// Get the to unit from the user
unit_type get_to_unit() {
    char unit_name[20];
    printf("Enter the to unit: ");
    scanf("%s", unit_name);
    return get_unit_type(unit_name);
}

// Print the converted value
void print_converted_value(double value, unit_type to_unit) {
    printf("The converted value is: %f %s\n", value, unit_names[to_unit]);
}

// Main function
int main() {
    // Print the conversion table
    print_conversion_table();

    // Get the value from the user
    double value = get_value();

    // Get the from unit from the user
    unit_type from_unit = get_from_unit();

    // Get the to unit from the user
    unit_type to_unit = get_to_unit();

    // Convert the value
    double converted_value = convert_unit(value, from_unit, to_unit);

    // Print the converted value
    print_converted_value(converted_value, to_unit);

    return 0;
}