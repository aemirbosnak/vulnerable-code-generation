//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define KILOS_TO_POUNDS 2.20462
#define POUNDS_TO_KILOS 0.453592
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.555556

// Define the unit types
typedef enum {
    METERS,
    FEET,
    KILOS,
    POUNDS,
    CELSIUS,
    FAHRENHEIT
} unit_type;

// Define the conversion function
double convert(double value, unit_type from, unit_type to) {
    switch (from) {
        case METERS:
            switch (to) {
                case FEET:
                    return value * METERS_TO_FEET;
                case KILOS:
                    return value * 0.001;
                case POUNDS:
                    return value * 0.00220462;
                case CELSIUS:
                    return value;
                case FAHRENHEIT:
                    return value * 1.8 + 32;
                default:
                    return value;
            }
        case FEET:
            switch (to) {
                case METERS:
                    return value * FEET_TO_METERS;
                case KILOS:
                    return value * 0.0003048;
                case POUNDS:
                    return value * 0.0006096;
                case CELSIUS:
                    return value;
                case FAHRENHEIT:
                    return value * 1.8 + 32;
                default:
                    return value;
            }
        case KILOS:
            switch (to) {
                case METERS:
                    return value * 1000;
                case FEET:
                    return value * 3280.84;
                case POUNDS:
                    return value * 2.20462;
                case CELSIUS:
                    return value;
                case FAHRENHEIT:
                    return value * 1.8 + 32;
                default:
                    return value;
            }
        case POUNDS:
            switch (to) {
                case METERS:
                    return value * 0.453592;
                case FEET:
                    return value * 1625.76;
                case KILOS:
                    return value * 0.453592;
                case CELSIUS:
                    return value;
                case FAHRENHEIT:
                    return value * 1.8 + 32;
                default:
                    return value;
            }
        case CELSIUS:
            switch (to) {
                case METERS:
                    return value;
                case FEET:
                    return value;
                case KILOS:
                    return value;
                case POUNDS:
                    return value;
                case FAHRENHEIT:
                    return value * 1.8 + 32;
                default:
                    return value;
            }
        case FAHRENHEIT:
            switch (to) {
                case METERS:
                    return (value - 32) * 0.555556;
                case FEET:
                    return (value - 32) * 0.555556;
                case KILOS:
                    return (value - 32) * 0.555556;
                case POUNDS:
                    return (value - 32) * 0.555556;
                case CELSIUS:
                    return value;
                default:
                    return value;
            }
        default:
            return value;
    }
}

// Define the main function
int main() {
    // Get the input value
    double value;
    printf("Enter the value: ");
    scanf("%lf", &value);

    // Get the input unit type
    unit_type from;
    printf("Enter the input unit type (meters, feet, kilos, pounds, celsius, fahrenheit): ");
    char unit[10];
    scanf("%s", unit);
    if (strcmp(unit, "meters") == 0) {
        from = METERS;
    } else if (strcmp(unit, "feet") == 0) {
        from = FEET;
    } else if (strcmp(unit, "kilos") == 0) {
        from = KILOS;
    } else if (strcmp(unit, "pounds") == 0) {
        from = POUNDS;
    } else if (strcmp(unit, "celsius") == 0) {
        from = CELSIUS;
    } else if (strcmp(unit, "fahrenheit") == 0) {
        from = FAHRENHEIT;
    } else {
        printf("Invalid input unit type.\n");
        return 1;
    }

    // Get the output unit type
    unit_type to;
    printf("Enter the output unit type (meters, feet, kilos, pounds, celsius, fahrenheit): ");
    scanf("%s", unit);
    if (strcmp(unit, "meters") == 0) {
        to = METERS;
    } else if (strcmp(unit, "feet") == 0) {
        to = FEET;
    } else if (strcmp(unit, "kilos") == 0) {
        to = KILOS;
    } else if (strcmp(unit, "pounds") == 0) {
        to = POUNDS;
    } else if (strcmp(unit, "celsius") == 0) {
        to = CELSIUS;
    } else if (strcmp(unit, "fahrenheit") == 0) {
        to = FAHRENHEIT;
    } else {
        printf("Invalid output unit type.\n");
        return 1;
    }

    // Convert the value
    double convertedValue = convert(value, from, to);

    // Print the converted value
    printf("The converted value is: %f %s\n", convertedValue, unit);

    return 0;
}