//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 5

// Define the units and their symbols
enum units {
    UNIT_NONE,
    UNIT_METric,
    UNIT_INCH,
    UNIT_FOOT,
    UNIT_YARD
};

const char *unit_names[MAX_UNITS] = {
    "None",
    "Metric",
    "Inch",
    "Foot",
    "Yard"
};

// Define the conversion factors
const double conversion_factors[MAX_UNITS][MAX_UNITS] = {
    {1, 100, 0.08, 0.3048, 0.9144}, // Metric to Inch
    {100, 1, 0.01, 0.0254, 0.0625}, // Inch to Metric
    {1, 12, 0.083333, 0.25, 0.625}, // Inch to Foot
    {12, 1, 0.0625, 0.125, 0.25}, // Foot to Inch
    {1, 36, 0.027778, 0.078125, 0.1953125} // Foot to Yard
};

// Function to convert between units
void convert(enum units from_unit, enum units to_unit, double value) {
    double factor = conversion_factors[from_unit][to_unit];
    value *= factor;
}

int main() {
    // Initialize the unit and value
    enum units unit = UNIT_NONE;
    double value = 0;

    // Get the input from the user
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Get the unit from the user
    printf("Enter the unit (Metric, Inch, Foot, or Yard): ");
    char unit_input;
    scanf(" %c", &unit_input);
    unit = unit_input == 'M' ? UNIT_METric :
                            unit_input == 'I' ? UNIT_INCH :
                            unit_input == 'F' ? UNIT_FOOT : UNIT_YARD;

    // Convert the value to the specified unit
    convert(unit, unit, value);

    // Print the result
    printf("The value is %g %s\n", value, unit_names[unit]);

    return 0;
}