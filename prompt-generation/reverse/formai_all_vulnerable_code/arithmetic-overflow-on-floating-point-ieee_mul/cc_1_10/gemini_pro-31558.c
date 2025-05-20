//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>

#define NUM_UNITS 6

// Define the units
typedef enum {
    METERS,
    KILOMETERS,
    CENTIMETERS,
    INCHES,
    FEET,
    YARDS
} unit_t;

// Define the conversion factors
static const double conversion_factors[NUM_UNITS][NUM_UNITS] = {
    { 1.0, 0.001, 100.0, 39.3701, 3.28084, 1.09361 },
    { 1000.0, 1.0, 100000.0, 39370.1, 3280.84, 1093.61 },
    { 0.01, 0.00001, 1.0, 0.393701, 0.0328084, 0.0109361 },
    { 0.0254, 0.0000254, 2.54, 1.0, 0.0833333, 0.0277778 },
    { 0.3048, 0.0003048, 30.48, 12.0, 1.0, 0.333333 },
    { 0.9144, 0.0009144, 91.44, 36.0, 3.0, 1.0 }
};

// Get the unit name
static const char *get_unit_name(unit_t unit) {
    switch (unit) {
        case METERS:
            return "meters";
        case KILOMETERS:
            return "kilometers";
        case CENTIMETERS:
            return "centimeters";
        case INCHES:
            return "inches";
        case FEET:
            return "feet";
        case YARDS:
            return "yards";
        default:
            return "unknown unit";
    }
}

// Convert the value from one unit to another
double convert_value(double value, unit_t from_unit, unit_t to_unit) {
    return value * conversion_factors[from_unit][to_unit];
}

// Print the converted value
void print_converted_value(double value, unit_t from_unit, unit_t to_unit) {
    printf("%f %s = %f %s\n", value, get_unit_name(from_unit), convert_value(value, from_unit, to_unit), get_unit_name(to_unit));
}

int main(void) {
    // Get the value to convert
    double value;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    // Get the from unit
    unit_t from_unit;
    printf("Enter the unit to convert from: ");
    scanf("%d", &from_unit);

    // Get the to unit
    unit_t to_unit;
    printf("Enter the unit to convert to: ");
    scanf("%d", &to_unit);

    // Print the converted value
    print_converted_value(value, from_unit, to_unit);

    return 0;
}