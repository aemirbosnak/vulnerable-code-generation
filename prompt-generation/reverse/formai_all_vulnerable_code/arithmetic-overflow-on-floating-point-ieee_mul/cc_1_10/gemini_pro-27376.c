//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the conversion rates
#define INCHES_PER_FOOT 12
#define FEET_PER_YARD 3
#define YARDS_PER_MILE 1760
#define METERS_PER_KILOMETER 1000
#define KILOMETERS_PER_MILE 1.60934

// Define the unit types
typedef enum {
    UNIT_INCHES,
    UNIT_FEET,
    UNIT_YARDS,
    UNIT_MILES,
    UNIT_METERS,
    UNIT_KILOMETERS
} unit_type;

// Define the unit names
const char *unit_names[] = {
    "inches",
    "feet",
    "yards",
    "miles",
    "meters",
    "kilometers"
};

// Print the welcome message
void print_welcome() {
    printf("Welcome to the Unit Converter!\n");
    printf("This program can convert between the following units:\n");
    for (int i = 0; i < UNIT_KILOMETERS + 1; i++) {
        printf("  - %s\n", unit_names[i]);
    }
}

// Get the user's input
void get_input(double *value, unit_type *unit) {
    printf("Enter the value you want to convert: ");
    scanf("%lf", value);

    printf("Enter the unit of the value you want to convert: ");
    char unit_name[32];
    scanf("%s", unit_name);

    // Convert the unit name to the corresponding unit type
    for (int i = 0; i < UNIT_KILOMETERS + 1; i++) {
        if (strcmp(unit_name, unit_names[i]) == 0) {
            *unit = i;
            break;
        }
    }
}

// Convert the value to the desired unit
double convert_value(double value, unit_type from_unit, unit_type to_unit) {
    // Convert the value to inches
    double inches = value;
    switch (from_unit) {
        case UNIT_FEET:
            inches *= INCHES_PER_FOOT;
            break;
        case UNIT_YARDS:
            inches *= INCHES_PER_FOOT * FEET_PER_YARD;
            break;
        case UNIT_MILES:
            inches *= INCHES_PER_FOOT * FEET_PER_YARD * YARDS_PER_MILE;
            break;
        case UNIT_METERS:
            inches *= METERS_PER_KILOMETER * KILOMETERS_PER_MILE * INCHES_PER_FOOT * FEET_PER_YARD * YARDS_PER_MILE;
            break;
        case UNIT_KILOMETERS:
            inches *= METERS_PER_KILOMETER * KILOMETERS_PER_MILE * INCHES_PER_FOOT * FEET_PER_YARD * YARDS_PER_MILE;
            break;
    }

    // Convert the inches to the desired unit
    switch (to_unit) {
        case UNIT_FEET:
            return inches / INCHES_PER_FOOT;
        case UNIT_YARDS:
            return inches / (INCHES_PER_FOOT * FEET_PER_YARD);
        case UNIT_MILES:
            return inches / (INCHES_PER_FOOT * FEET_PER_YARD * YARDS_PER_MILE);
        case UNIT_METERS:
            return inches / (METERS_PER_KILOMETER * KILOMETERS_PER_MILE * INCHES_PER_FOOT * FEET_PER_YARD * YARDS_PER_MILE);
        case UNIT_KILOMETERS:
            return inches / (METERS_PER_KILOMETER * KILOMETERS_PER_MILE * INCHES_PER_FOOT * FEET_PER_YARD * YARDS_PER_MILE);
    }

    return 0;
}

// Print the converted value
void print_converted_value(double value, unit_type to_unit) {
    printf("The converted value is %.2f %s.\n", value, unit_names[to_unit]);
}

// Main function
int main() {
    // Print the welcome message
    print_welcome();

    // Get the user's input
    double value;
    unit_type from_unit;
    get_input(&value, &from_unit);

    // Convert the value to the desired unit
    double converted_value = convert_value(value, from_unit, UNIT_METERS);

    // Print the converted value
    print_converted_value(converted_value, UNIT_METERS);

    return 0;
}