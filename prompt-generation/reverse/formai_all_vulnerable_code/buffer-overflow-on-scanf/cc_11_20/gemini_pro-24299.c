//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_TO_CM 2.54
#define FEET_TO_M 0.3048
#define POUNDS_TO_KG 0.4536
#define GALLONS_TO_L 3.785

// Define the unit types
typedef enum {
    INCHES,
    FEET,
    POUNDS,
    GALLONS
} unit_type;

// Define the conversion function
double convert(double value, unit_type from, unit_type to) {
    switch (from) {
        case INCHES:
            switch (to) {
                case INCHES:
                    return value;
                case FEET:
                    return value / 12;
                case POUNDS:
                case GALLONS:
                    return -1;  // Not a valid conversion
            }
        case FEET:
            switch (to) {
                case INCHES:
                    return value * 12;
                case FEET:
                    return value;
                case POUNDS:
                case GALLONS:
                    return -1;  // Not a valid conversion
            }
        case POUNDS:
            switch (to) {
                case INCHES:
                case FEET:
                    return -1;  // Not a valid conversion
                case POUNDS:
                    return value;
                case GALLONS:
                    return -1;  // Not a valid conversion
            }
        case GALLONS:
            switch (to) {
                case INCHES:
                case FEET:
                    return -1;  // Not a valid conversion
                case POUNDS:
                    return -1;  // Not a valid conversion
                case GALLONS:
                    return value;
            }
    }

    return -1;  // Not a valid conversion
}

// Define the main function
int main() {
    // Get the user input
    double value;
    unit_type from, to;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from (inches, feet, pounds, gallons): ");
    scanf("%s", &from);
    printf("Enter the unit to convert to (inches, feet, pounds, gallons): ");
    scanf("%s", &to);

    // Convert the value
    double result = convert(value, from, to);

    // Print the result
    if (result >= 0) {
        printf("The converted value is: %lf\n", result);
    } else {
        printf("Invalid conversion\n");
    }

    return 0;
}