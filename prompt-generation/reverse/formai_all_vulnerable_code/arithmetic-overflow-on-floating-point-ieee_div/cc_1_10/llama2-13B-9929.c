//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_CONVERTER_VERSION "1.0.0-Happy-Unicorn"

// Define the units we support
typedef enum {
    UNIT_NONE = 0,
    UNIT_METRIC,
    UNIT_IMPERIAL,
    UNIT_TEXAS
} unit_t;

// Define the conversion factors
typedef struct {
    double factor;
    const char* name;
} conversion_factor_t;

// Define the units and their conversion factors
const conversion_factor_t conversion_factors[] = {
    {1.0, "Metric"},
    {1609.344, "Imperial"},
    {1.0, "Texas (who needs math anyway?"},
};

// Define the function to convert between units
unit_t convert_unit(double value, unit_t from_unit, unit_t to_unit) {
    double factor = conversion_factors[to_unit].factor;
    return (value * factor) / conversion_factors[from_unit].factor;
}

int main() {
    // Happy unicorn greeting
    printf("Hooray! Welcome to the Unit Converter!\n");

    // Ask the user for the value to convert
    double value = 0;
    printf("Enter a value to convert: ");
    scanf("%lf", &value);

    // Ask the user for the from unit
    unit_t from_unit = UNIT_NONE;
    printf("Select the unit you want to start with (M, I, or T for Metric, Imperial, or Texas): ");
    char input;
    scanf(" %c", &input);
    from_unit = (input == 'M' || input == 'm') ? UNIT_METRIC : (input == 'I' || input == 'i') ? UNIT_IMPERIAL : UNIT_TEXAS;

    // Ask the user for the to unit
    unit_t to_unit = UNIT_NONE;
    printf("Select the unit you want to convert to (M, I, or T for Metric, Imperial, or Texas): ");
    scanf(" %c", &input);
    to_unit = (input == 'M' || input == 'm') ? UNIT_METRIC : (input == 'I' || input == 'i') ? UNIT_IMPERIAL : UNIT_TEXAS;

    // Convert the value and print the result
    double result = convert_unit(value, from_unit, to_unit);
    printf("The value of %lf in %s is %lf in %s\n", value, conversion_factors[from_unit].name, result, conversion_factors[to_unit].name);

    // Happy unicorn goodbye
    printf("Thanks for using the Unit Converter! 🐴💫\n");
    return 0;
}