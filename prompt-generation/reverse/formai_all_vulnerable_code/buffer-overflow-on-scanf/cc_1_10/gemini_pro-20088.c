//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the conversion rates
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048

// Define the unit types
typedef enum {
    METERS,
    FEET
} unit_type;

// Define the conversion function
double convert(double value, unit_type from_unit, unit_type to_unit) {
    if (from_unit == METERS && to_unit == FEET) {
        return value * METERS_TO_FEET;
    } else if (from_unit == FEET && to_unit == METERS) {
        return value * FEET_TO_METERS;
    } else {
        // Invalid conversion
        return -1;
    }
}

// Get the user's input
double get_input(char *prompt, unit_type unit) {
    double value;

    printf("%s (%s): ", prompt, unit == METERS ? "meters" : "feet");
    scanf("%lf", &value);

    return value;
}

// Print the converted value
void print_result(double value, unit_type unit) {
    printf("Converted value: %.2f %s\n", value, unit == METERS ? "meters" : "feet");
}

// Main function
int main() {
    // Get the user's input
    double meters = get_input("Enter the value in meters", METERS);
    double feet = get_input("Enter the value in feet", FEET);

    // Convert the values
    double converted_meters = convert(meters, METERS, FEET);
    double converted_feet = convert(feet, FEET, METERS);

    // Print the converted values
    print_result(converted_meters, FEET);
    print_result(converted_feet, METERS);

    return 0;
}