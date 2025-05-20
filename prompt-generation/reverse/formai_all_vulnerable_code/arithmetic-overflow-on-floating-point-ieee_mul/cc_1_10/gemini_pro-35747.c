//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: safe
// C program to convert units of length, weight and temperature

#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_TO_CENTIMETERS 2.54
#define CENTIMETERS_TO_INCHES 0.393701
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define FAHRENHEIT_TO_CELSIUS (5.0 / 9.0) * (-32.0)
#define CELSIUS_TO_FAHRENHEIT (9.0 / 5.0) * (32.0)

// Define the unit types
typedef enum {
    INCHES,
    CENTIMETERS,
    POUNDS,
    KILOGRAMS,
    FAHRENHEIT,
    CELSIUS
} unit_type;

// Define the conversion function
double convert_units(double value, unit_type from_unit, unit_type to_unit) {
    // Check if the units are the same
    if (from_unit == to_unit) {
        return value;
    }

    // Convert the value to the intermediate unit
    double intermediate_value;
    switch (from_unit) {
        case INCHES:
            intermediate_value = value * INCHES_TO_CENTIMETERS;
            break;
        case CENTIMETERS:
            intermediate_value = value * CENTIMETERS_TO_INCHES;
            break;
        case POUNDS:
            intermediate_value = value * POUNDS_TO_KILOGRAMS;
            break;
        case KILOGRAMS:
            intermediate_value = value * KILOGRAMS_TO_POUNDS;
            break;
        case FAHRENHEIT:
            intermediate_value = (value + FAHRENHEIT_TO_CELSIUS) * CELSIUS_TO_FAHRENHEIT;
            break;
        case CELSIUS:
            intermediate_value = (value + CELSIUS_TO_FAHRENHEIT) * FAHRENHEIT_TO_CELSIUS;
            break;
    }

    // Convert the value to the target unit
    double target_value;
    switch (to_unit) {
        case INCHES:
            target_value = intermediate_value * CENTIMETERS_TO_INCHES;
            break;
        case CENTIMETERS:
            target_value = intermediate_value * INCHES_TO_CENTIMETERS;
            break;
        case POUNDS:
            target_value = intermediate_value * KILOGRAMS_TO_POUNDS;
            break;
        case KILOGRAMS:
            target_value = intermediate_value * POUNDS_TO_KILOGRAMS;
            break;
        case FAHRENHEIT:
            target_value = intermediate_value * CELSIUS_TO_FAHRENHEIT - FAHRENHEIT_TO_CELSIUS;
            break;
        case CELSIUS:
            target_value = intermediate_value * FAHRENHEIT_TO_CELSIUS - CELSIUS_TO_FAHRENHEIT;
            break;
    }

    return target_value;
}

// Get the input from the user
double get_input(const char *prompt) {
    double value;
    printf("%s", prompt);
    scanf("%lf", &value);
    return value;
}

// Print the result
void print_result(double value, unit_type to_unit) {
    switch (to_unit) {
        case INCHES:
            printf("%.2f inches\n", value);
            break;
        case CENTIMETERS:
            printf("%.2f centimeters\n", value);
            break;
        case POUNDS:
            printf("%.2f pounds\n", value);
            break;
        case KILOGRAMS:
            printf("%.2f kilograms\n", value);
            break;
        case FAHRENHEIT:
            printf("%.2f degrees Fahrenheit\n", value);
            break;
        case CELSIUS:
            printf("%.2f degrees Celsius\n", value);
            break;
    }
}

// Main function
int main() {
    // Get the input from the user
    double value = get_input("Enter the value: ");
    unit_type from_unit;
    printf("Enter the unit of the value (inches, centimeters, pounds, kilograms, fahrenheit, celsius): ");
    scanf("%d", &from_unit);
    unit_type to_unit;
    printf("Enter the unit to convert to (inches, centimeters, pounds, kilograms, fahrenheit, celsius): ");
    scanf("%d", &to_unit);

    // Convert the units
    double target_value = convert_units(value, from_unit, to_unit);

    // Print the result
    print_result(target_value, to_unit);

    return 0;
}