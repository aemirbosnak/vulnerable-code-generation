//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define the unit types
enum unit_type {
    LENGTH,
    MASS,
    TIME,
    TEMPERATURE
};

// Define the unit conversion functions
double length_converter(double value, char from_unit, char to_unit);
double mass_converter(double value, char from_unit, char to_unit);
double time_converter(double value, char from_unit, char to_unit);
double temperature_converter(double value, char from_unit, char to_unit);

// Define the unit conversion table
const char* unit_conversion_table[][3] = {
    {"km", "m", "1000"},
    {"m", "cm", "100"},
    {"cm", "mm", "10"},
    {"kg", "g", "1000"},
    {"g", "mg", "1000"},
    {"h", "min", "60"},
    {"min", "s", "60"},
    {"C", "F", "32"},
    {"F", "C", "32"}
};

// Get the unit type from the user
enum unit_type get_unit_type() {
    int choice;
    printf("Enter the unit type:\n");
    printf("1. Length\n");
    printf("2. Mass\n");
    printf("3. Time\n");
    printf("4. Temperature\n");
    scanf("%d", &choice);
    return choice - 1;
}

// Get the unit conversion details from the user
void get_unit_conversion_details(enum unit_type unit_type, double* value, char* from_unit, char* to_unit) {
    printf("Enter the value to convert: ");
    scanf("%lf", value);
    printf("Enter the from unit: ");
    scanf(" %c", from_unit);
    printf("Enter the to unit: ");
    scanf(" %c", to_unit);
}

// Convert the unit
double convert_unit(enum unit_type unit_type, double value, char from_unit, char to_unit) {
    switch (unit_type) {
        case LENGTH:
            return length_converter(value, from_unit, to_unit);
        case MASS:
            return mass_converter(value, from_unit, to_unit);
        case TIME:
            return time_converter(value, from_unit, to_unit);
        case TEMPERATURE:
            return temperature_converter(value, from_unit, to_unit);
        default:
            return -1;
    }
}

// Print the result
void print_result(double result) {
    printf("The converted value is: %lf\n", result);
}

// Main function
int main() {
    enum unit_type unit_type = get_unit_type();
    double value;
    char from_unit, to_unit;
    get_unit_conversion_details(unit_type, &value, &from_unit, &to_unit);
    double result = convert_unit(unit_type, value, from_unit, to_unit);
    print_result(result);
    return 0;
}

// Unit conversion functions
double length_converter(double value, char from_unit, char to_unit) {
    int i;
    for (i = 0; i < 3; i++) {
        if (unit_conversion_table[i][0] == from_unit && unit_conversion_table[i][1] == to_unit) {
            return value * atof(unit_conversion_table[i][2]);
        } else if (unit_conversion_table[i][1] == from_unit && unit_conversion_table[i][0] == to_unit) {
            return value / atof(unit_conversion_table[i][2]);
        }
    }
    return -1;
}

double mass_converter(double value, char from_unit, char to_unit) {
    int i;
    for (i = 0; i < 3; i++) {
        if (unit_conversion_table[i][0] == from_unit && unit_conversion_table[i][1] == to_unit) {
            return value * atof(unit_conversion_table[i][2]);
        } else if (unit_conversion_table[i][1] == from_unit && unit_conversion_table[i][0] == to_unit) {
            return value / atof(unit_conversion_table[i][2]);
        }
    }
    return -1;
}

double time_converter(double value, char from_unit, char to_unit) {
    int i;
    for (i = 0; i < 3; i++) {
        if (unit_conversion_table[i][0] == from_unit && unit_conversion_table[i][1] == to_unit) {
            return value * atof(unit_conversion_table[i][2]);
        } else if (unit_conversion_table[i][1] == from_unit && unit_conversion_table[i][0] == to_unit) {
            return value / atof(unit_conversion_table[i][2]);
        }
    }
    return -1;
}

double temperature_converter(double value, char from_unit, char to_unit) {
    int i;
    for (i = 0; i < 3; i++) {
        if (unit_conversion_table[i][0] == from_unit && unit_conversion_table[i][1] == to_unit) {
            return value * atof(unit_conversion_table[i][2]);
        } else if (unit_conversion_table[i][1] == from_unit && unit_conversion_table[i][0] == to_unit) {
            return value / atof(unit_conversion_table[i][2]);
        }
    }
    return -1;
}