//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_TO_CM 2.54
#define CM_TO_INCHES 0.393701
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define MILES_TO_KILOMETERS 1.60934
#define KILOMETERS_TO_MILES 0.621371

// Define the unit types
typedef enum {
    INCHES,
    CM,
    POUNDS,
    KILOGRAMS,
    MILES,
    KILOMETERS
} unit_type;

// Define the conversion function
double convert(double value, unit_type from_unit, unit_type to_unit) {
    // Check if the conversion is valid
    if (from_unit == to_unit) {
        return value;
    }

    // Convert the value to the intermediate unit
    double intermediate_value;
    switch (from_unit) {
        case INCHES:
            intermediate_value = value * INCHES_TO_CM;
            break;
        case POUNDS:
            intermediate_value = value * POUNDS_TO_KILOGRAMS;
            break;
        case MILES:
            intermediate_value = value * MILES_TO_KILOMETERS;
            break;
        default:
            printf("Invalid conversion from unit %d to unit %d\n", from_unit, to_unit);
            exit(1);
    }

    // Convert the intermediate value to the final unit
    double final_value;
    switch (to_unit) {
        case CM:
            final_value = intermediate_value / INCHES_TO_CM;
            break;
        case KILOGRAMS:
            final_value = intermediate_value / POUNDS_TO_KILOGRAMS;
            break;
        case KILOMETERS:
            final_value = intermediate_value / MILES_TO_KILOMETERS;
            break;
        default:
            printf("Invalid conversion from unit %d to unit %d\n", from_unit, to_unit);
            exit(1);
    }

    // Return the final value
    return final_value;
}

// Define the main function
int main() {
    // Get the input value and units
    double value;
    unit_type from_unit, to_unit;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from (inches, cm, pounds, kilograms, miles, kilometers): ");
    scanf(" %c", &from_unit);
    printf("Enter the unit to convert to (inches, cm, pounds, kilograms, miles, kilometers): ");
    scanf(" %c", &to_unit);

    // Convert the value
    double converted_value = convert(value, from_unit, to_unit);

    // Print the result
    printf("%lf %c is equal to %lf %c\n", value, from_unit, converted_value, to_unit);

    return 0;
}