//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the conversion factors
#define INCHES_PER_FEET 12
#define FEET_PER_YARD 3
#define YARDS_PER_MILE 1760

// Define the unit types
typedef enum {
    INCHES,
    FEET,
    YARDS,
    MILES
} unit_type;

// Define the conversion function
double convert(double value, unit_type from, unit_type to) {
    // Check if the conversion is valid
    if (from == to) {
        return value;
    }

    // Convert the value to inches
    double inches = value;
    switch (from) {
        case FEET:
            inches *= INCHES_PER_FEET;
            break;
        case YARDS:
            inches *= INCHES_PER_FEET * FEET_PER_YARD;
            break;
        case MILES:
            inches *= INCHES_PER_FEET * FEET_PER_YARD * YARDS_PER_MILE;
            break;
    }

    // Convert the value to the desired unit
    double result = inches;
    switch (to) {
        case FEET:
            result /= INCHES_PER_FEET;
            break;
        case YARDS:
            result /= INCHES_PER_FEET * FEET_PER_YARD;
            break;
        case MILES:
            result /= INCHES_PER_FEET * FEET_PER_YARD * YARDS_PER_MILE;
            break;
    }

    return result;
}

// Get the input from the user
double get_input(char *prompt) {
    double value;
    printf("%s", prompt);
    scanf("%lf", &value);
    return value;
}

// Print the result
void print_result(double value, unit_type to) {
    char *unit_name;
    switch (to) {
        case INCHES:
            unit_name = "inches";
            break;
        case FEET:
            unit_name = "feet";
            break;
        case YARDS:
            unit_name = "yards";
            break;
        case MILES:
            unit_name = "miles";
            break;
    }
    printf("The value is %.2f %s.\n", value, unit_name);
}

// Main function
int main() {
    // Get the input from the user
    double value = get_input("Enter the value: ");
    unit_type from = get_input("Enter the input unit (inches, feet, yards, miles): ");
    unit_type to = get_input("Enter the output unit (inches, feet, yards, miles): ");

    // Convert the value
    double result = convert(value, from, to);

    // Print the result
    print_result(result, to);

    return 0;
}