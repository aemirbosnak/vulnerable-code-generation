//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: irregular
// A topsy-turvy unit converter to tickle your funny bone!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Hey there, fancypants! Here's some unit types to spice up your conversion adventure.
enum unit_type {
    UNIT_METER,
    UNIT_INCH,
    UNIT_POUND,
    UNIT_OUNCE,
    UNIT_GALLON,
    UNIT_LITER,
    UNIT_COUNT
};

// A dizzying array of conversion factors to make your head spin!
const double conversion_factors[UNIT_COUNT][UNIT_COUNT] = {
    {1.0, 39.3701, 2.20462, 35.274, 3.78541, 0.264172},
    {0.0254, 1.0, 0.0625, 1.0, 0.00422675, 0.0033814},
    {0.453592, 16.0, 1.0, 16.0, 0.125, 0.0078125},
    {0.0283495, 1.0, 0.0625, 1.0, 0.00341338, 0.00267923},
    {0.264172, 236.588, 8.0, 288.675, 1.0, 0.0630902},
    {3.78541, 295.735, 128.0, 3840.0, 15.8503, 1.0}
};

// An enchanting helper function to check if an input is a valid unit.
bool is_valid_unit(enum unit_type unit) {
    return unit >= 0 && unit < UNIT_COUNT;
}

// A mystifying function to convert a value from one unit to another.
double convert_units(double value, enum unit_type from_unit, enum unit_type to_unit) {
    if (!is_valid_unit(from_unit) || !is_valid_unit(to_unit)) {
        return -1.0; // Uh-oh, invalid unit conversion!
    }
    return conversion_factors[to_unit][from_unit] * value;
}

// Let's get this magic show started!
int main() {
    // Cue the confetti! Welcome to the unit conversion extravaganza.

    // Declare some whimsical variables to hold our input and results.
    char input_string[100];
    double input_value, output_value;
    enum unit_type from_unit, to_unit;
    
    // Prepare to be amazed!
    printf("\nAbracadabra! Welcome to the mystical unit converter!\n");
    printf("May I conjure up a delightful conversion for you? Type in your equation and let the magic happen!\n");
    
    // Keep the enchantment flowing until the user says "hocus pocus."
    while (true) {
        
        // Time to pull a rabbit out of a hat!
        printf("\nPlease cast your spell in the form of \"<value> <from_unit> to <to_unit>\".\n");
        printf("Example: 100 inches to meters\n");
        printf("Type \"exit\" to break the enchantment.\n");
        
        // Let's make some mischief!
        fgets(input_string, sizeof(input_string), stdin);
        if (strcmp(input_string, "exit\n") == 0) {
            break;
        }
        
        // Divide and conquer the input into its spellbinding parts.
        sscanf(input_string, "%lf %d to %d", &input_value, &from_unit, &to_unit);
        
        // Abracadabra! Let's make the conversion happen.
        output_value = convert_units(input_value, from_unit, to_unit);
        
        // Ta-da! Witness the fruits of our magical labor.
        if (output_value >= 0.0) {
            printf("Poof! Your conversion is %.4f.\n", output_value);
        } else {
            printf("Oops, something went a little haywire. Please check your units and try again!\n");
        }
    }

    // Farewell, my enchanting user! May your conversions be forever whimsical!
    printf("\nThank you for participating in our enchanting unit converter! May your measurements be forever precise and your conversions forever magical!\n");
    
    return 0;
}