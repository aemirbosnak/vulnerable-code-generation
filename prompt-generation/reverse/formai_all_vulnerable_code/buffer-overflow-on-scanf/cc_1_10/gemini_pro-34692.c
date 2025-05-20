//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Constants for unit conversions
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462

// Function to convert meters to feet
float meters_to_feet(float meters) {
    return meters * METERS_TO_FEET;
}

// Function to convert feet to meters
float feet_to_meters(float feet) {
    return feet * FEET_TO_METERS;
}

// Function to convert pounds to kilograms
float pounds_to_kilograms(float pounds) {
    return pounds * POUNDS_TO_KILOGRAMS;
}

// Function to convert kilograms to pounds
float kilograms_to_pounds(float kilograms) {
    return kilograms * KILOGRAMS_TO_POUNDS;
}

// Main function
int main() {
    // Variables to store the user's input
    float value;
    char unit_from;
    char unit_to;

    // Prompt the user to enter the value and units
    printf("Enter the value: ");
    scanf("%f", &value);
    printf("Enter the unit to convert from (m/ft): ");
    scanf(" %c", &unit_from);
    printf("Enter the unit to convert to (m/ft): ");
    scanf(" %c", &unit_to);

    // Convert the value to the desired unit
    float converted_value;
    switch (unit_from) {
        case 'm':
            if (unit_to == 'ft') {
                converted_value = meters_to_feet(value);
            } else {
                printf("Invalid unit conversion.");
                return 1;
            }
            break;
        case 'f':
            if (unit_to == 'm') {
                converted_value = feet_to_meters(value);
            } else {
                printf("Invalid unit conversion.");
                return 1;
            }
            break;
        default:
            printf("Invalid unit entered.");
            return 1;
    }

    // Print the converted value
    printf("The converted value is: %.2f %c\n", converted_value, unit_to);

    return 0;
}