//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the unit types
enum unit_type {
    METERS,
    CENTIMETERS,
    KILOMETERS,
    INCHES,
    FEET,
    YARDS,
    MILES
};

// Define the conversion factors
double conversion_factors[7][7] = {
    {1.0, 0.01, 0.001, 0.393701, 0.328084, 0.010936, 0.000621371},
    {100.0, 1.0, 0.01, 39.3701, 32.8084, 1.09361, 0.00621371},
    {1000.0, 100.0, 1.0, 3937.01, 3280.84, 1093.61, 0.621371},
    {2.54, 0.0254, 0.00254, 1.0, 0.833333, 0.027778, 0.000157828},
    {3.048, 0.03048, 0.003048, 1.2, 1.0, 0.333333, 0.000189394},
    {91.44, 0.9144, 0.09144, 36.0, 3.0, 1.0, 0.000568182},
    {1609.34, 16.0934, 1.60934, 63360.0, 5280.0, 1760.0, 1.0}
};

// Define the unit names
char *unit_names[7] = {
    "meters",
    "centimeters",
    "kilometers",
    "inches",
    "feet",
    "yards",
    "miles"
};

// Get the unit type from the user
int get_unit_type(char *unit) {
    for (int i = 0; i < 7; i++) {
        if (strcmp(unit, unit_names[i]) == 0) {
            return i;
        }
    }

    return -1;
}

// Convert the value to the desired unit
double convert_value(double value, int from_unit, int to_unit) {
    return value * conversion_factors[from_unit][to_unit];
}

// Print the converted value
void print_converted_value(double value, int to_unit) {
    printf("%f %s\n", value, unit_names[to_unit]);
}

// Main function
int main() {
    // Get the input value and unit
    double value;
    char from_unit[20];
    char to_unit[20];
    printf("Enter the value: ");
    scanf("%lf", &value);
    printf("Enter the from unit: ");
    scanf("%s", from_unit);
    printf("Enter the to unit: ");
    scanf("%s", to_unit);

    // Get the unit types
    int from_unit_type = get_unit_type(from_unit);
    int to_unit_type = get_unit_type(to_unit);

    // Check if the unit types are valid
    if (from_unit_type == -1 || to_unit_type == -1) {
        printf("Invalid unit type\n");
        return 1;
    }

    // Convert the value
    double converted_value = convert_value(value, from_unit_type, to_unit_type);

    // Print the converted value
    print_converted_value(converted_value, to_unit_type);

    return 0;
}