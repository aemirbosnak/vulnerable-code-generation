//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert units of measurement
void convert_units(float value, char from_unit, char to_unit) {
    // Define conversion factors
    const float conv_factors[] = {
        // Length
        1, // None (no conversion)
        0.03048, // Meter to Inch
        0.01097, // Inch to Meter
        // Weight
        1, // None (no conversion)
        0.001, // Pound to Kilogram
        1000, // Kilogram to Pound
        // Capacity
        1, // None (no conversion)
        0.23659, // Gallon to Liter
        0.03785, // Liter to Gallon
    };

    // Check for invalid inputs
    if (from_unit == to_unit) {
        printf("Invalid input: From and To units cannot be the same.\n");
        return;
    }

    // Calculate conversion factor
    float conv_factor = conv_factors[from_unit * 2 + to_unit];

    // Perform conversion
    value *= conv_factor;

    // Print result
    printf("Converted value: %f %s\n", value, to_unit);
}

int main() {
    // Declare variables
    float value;
    char from_unit, to_unit;

    // Get input values
    printf("Enter a value: ");
    scanf("%f", &value);
    printf("Enter From unit (m/in/gal): ");
    scanf(" %c", &from_unit);
    printf("Enter To unit (m/in/gal): ");
    scanf(" %c", &to_unit);

    // Convert units
    convert_units(value, from_unit, to_unit);

    return 0;
}