//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the unit types and their conversion factors
typedef enum {
    UNIT_NONE = 0,
    UNIT_METRIC,
    UNIT_IMPERIAL,
    UNIT_OTHER
} UnitType;

typedef struct {
    UnitType type;
    double factor;
} UnitConversion;

// Define the available units and their conversions
static UnitConversion unitConversions[] = {
    { UNIT_METRIC, 1.0 },
    { UNIT_IMPERIAL, 0.3048 },
    { UNIT_OTHER, 1.0 }
};

int main() {
    // Define the input and output units
    int inputUnit = UNIT_NONE, outputUnit = UNIT_NONE;

    // Get the input and output values from the user
    double inputValue = 0.0;
    double outputValue = 0.0;

    do {
        // Print the available units and their conversions
        printf("Available units: \n");
        for (int i = 0; i < sizeof(unitConversions) / sizeof(UnitConversion); i++) {
            printf("  %d: %s (%f)\n", unitConversions[i].type, unitConversions[i].type == UNIT_METRIC ? "metric" : "imperial", unitConversions[i].factor);
        }

        // Get the input unit and value from the user
        printf("Enter the input value (%s): ", inputUnit == UNIT_NONE ? "any" : unitConversions[inputUnit].type == UNIT_METRIC ? "metric" : "imperial");
        scanf("%lf", &inputValue);

        // Get the output unit and value from the user
        printf("Enter the output value (%s): ", outputUnit == UNIT_NONE ? "any" : unitConversions[outputUnit].type == UNIT_METRIC ? "metric" : "imperial");
        scanf("%lf", &outputValue);

        // Convert the input value to the output unit
        if (inputUnit != UNIT_NONE && outputUnit != UNIT_NONE) {
            outputValue = inputValue * unitConversions[inputUnit].factor / unitConversions[outputUnit].factor;
        }
    } while (inputUnit != outputUnit);

    // Print the converted value and unit
    printf("The value %f %s is equal to %f %s.\n", inputValue, inputUnit == UNIT_METRIC ? "meters" : "feet", outputValue, outputUnit == UNIT_METRIC ? "meters" : "feet");

    return 0;
}