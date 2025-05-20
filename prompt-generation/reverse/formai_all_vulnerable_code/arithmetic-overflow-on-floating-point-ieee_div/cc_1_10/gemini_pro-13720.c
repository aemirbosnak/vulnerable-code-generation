//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the supported units
enum unit_type {
    METER,
    KILOMETER,
    CENTIMETER,
    INCH,
    FOOT,
    YARD,
    MILE
};

// Define the conversion factors
const double conversion_factors[] = {
    1.0,
    1000.0,
    0.01,
    0.0254,
    0.3048,
    0.9144,
    1609.34
};

// Get the unit type from a string
enum unit_type get_unit_type(const char *unit) {
    if (!strcmp(unit, "m")) {
        return METER;
    } else if (!strcmp(unit, "km")) {
        return KILOMETER;
    } else if (!strcmp(unit, "cm")) {
        return CENTIMETER;
    } else if (!strcmp(unit, "in")) {
        return INCH;
    } else if (!strcmp(unit, "ft")) {
        return FOOT;
    } else if (!strcmp(unit, "yd")) {
        return YARD;
    } else if (!strcmp(unit, "mi")) {
        return MILE;
    } else {
        return -1;
    }
}

// Convert a value from one unit to another
double convert_unit(double value, enum unit_type from, enum unit_type to) {
    return value * conversion_factors[to] / conversion_factors[from];
}

// Print a list of the supported units
void print_units() {
    printf("Supported units:\n");
    for (int i = 0; i < sizeof(conversion_factors) / sizeof(double); i++) {
        printf("  %s\n", i == 0 ? "m" : i == 1 ? "km" : i == 2 ? "cm" : i == 3 ? "in" : i == 4 ? "ft" : i == 5 ? "yd" : "mi");
    }
}

// Get the user's input
void get_input(double *value, char *unit) {
    printf("Enter a value and unit (e.g., 1.5 m): ");
    scanf("%lf %s", value, unit);
}

// Print the converted value
void print_converted_value(double value, enum unit_type to) {
    printf("Converted value: %.2f %s\n", value, to == 0 ? "m" : to == 1 ? "km" : to == 2 ? "cm" : to == 3 ? "in" : to == 4 ? "ft" : to == 5 ? "yd" : "mi");
}

int main() {
    // Print a list of the supported units
    print_units();

    // Get the user's input
    double value;
    char unit[3];
    get_input(&value, unit);

    // Get the unit type from the user's input
    enum unit_type from = get_unit_type(unit);
    if (from == -1) {
        printf("Invalid unit: %s\n", unit);
        return EXIT_FAILURE;
    }

    // Get the unit type to convert to
    char to_unit[3];
    printf("Enter the unit to convert to (e.g., m, km, cm, in, ft, yd, mi): ");
    scanf("%s", to_unit);
    enum unit_type to = get_unit_type(to_unit);
    if (to == -1) {
        printf("Invalid unit: %s\n", to_unit);
        return EXIT_FAILURE;
    }

    // Convert the value
    double converted_value = convert_unit(value, from, to);

    // Print the converted value
    print_converted_value(converted_value, to);

    return EXIT_SUCCESS;
}