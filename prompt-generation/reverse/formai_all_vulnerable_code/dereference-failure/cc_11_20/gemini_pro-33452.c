//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define the supported units
#define UNIT_CELSIUS "Celsius"
#define UNIT_FAHRENHEIT "Fahrenheit"
#define UNIT_KILOMETERS "Kilometers"
#define UNIT_MILES "Miles"
#define UNIT_POUNDS "Pounds"
#define UNIT_KILOGRAMS "Kilograms"
#define UNIT_LITERS "Liters"
#define UNIT_GALLONS "Gallons"

// Define the conversion factors
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.5555555555555556
#define KILOMETERS_TO_MILES 0.621371192237334
#define MILES_TO_KILOMETERS 1.609344
#define POUNDS_TO_KILOGRAMS 0.45359237
#define KILOGRAMS_TO_POUNDS 2.2046226218
#define LITERS_TO_GALLONS 0.2641720523581484
#define GALLONS_TO_LITERS 3.785411784

// Define the unit types
typedef enum unit_type {
    UNIT_TYPE_TEMPERATURE,
    UNIT_TYPE_DISTANCE,
    UNIT_TYPE_WEIGHT,
    UNIT_TYPE_VOLUME
} unit_type;

// Define the conversion function
double convert(double value, unit_type from_unit, unit_type to_unit) {
    // Check if the units are the same
    if (from_unit == to_unit) {
        return value;
    }

    // Convert the value based on the unit type
    switch (from_unit) {
    case UNIT_TYPE_TEMPERATURE:
        if (to_unit == UNIT_TYPE_TEMPERATURE) {
            return value;
        } else if (to_unit == UNIT_TYPE_DISTANCE) {
            return NAN;
        } else if (to_unit == UNIT_TYPE_WEIGHT) {
            return NAN;
        } else if (to_unit == UNIT_TYPE_VOLUME) {
            return NAN;
        }
        break;
    case UNIT_TYPE_DISTANCE:
        if (to_unit == UNIT_TYPE_TEMPERATURE) {
            return NAN;
        } else if (to_unit == UNIT_TYPE_DISTANCE) {
            return value;
        } else if (to_unit == UNIT_TYPE_WEIGHT) {
            return NAN;
        } else if (to_unit == UNIT_TYPE_VOLUME) {
            return NAN;
        }
        break;
    case UNIT_TYPE_WEIGHT:
        if (to_unit == UNIT_TYPE_TEMPERATURE) {
            return NAN;
        } else if (to_unit == UNIT_TYPE_DISTANCE) {
            return NAN;
        } else if (to_unit == UNIT_TYPE_WEIGHT) {
            return value;
        } else if (to_unit == UNIT_TYPE_VOLUME) {
            return NAN;
        }
        break;
    case UNIT_TYPE_VOLUME:
        if (to_unit == UNIT_TYPE_TEMPERATURE) {
            return NAN;
        } else if (to_unit == UNIT_TYPE_DISTANCE) {
            return NAN;
        } else if (to_unit == UNIT_TYPE_WEIGHT) {
            return NAN;
        } else if (to_unit == UNIT_TYPE_VOLUME) {
            return value;
        }
        break;
    }

    // Return an error if the conversion is not supported
    return NAN;
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user provided enough arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the value, from unit, and to unit from the user
    double value = atof(argv[1]);
    char *from_unit_str = argv[2];
    char *to_unit_str = argv[3];

    // Convert the from unit and to unit strings to unit types
    unit_type from_unit = UNIT_TYPE_TEMPERATURE;
    unit_type to_unit = UNIT_TYPE_TEMPERATURE;
    if (strcmp(from_unit_str, UNIT_CELSIUS) == 0) {
        from_unit = UNIT_TYPE_TEMPERATURE;
    } else if (strcmp(from_unit_str, UNIT_FAHRENHEIT) == 0) {
        from_unit = UNIT_TYPE_TEMPERATURE;
    } else if (strcmp(from_unit_str, UNIT_KILOMETERS) == 0) {
        from_unit = UNIT_TYPE_DISTANCE;
    } else if (strcmp(from_unit_str, UNIT_MILES) == 0) {
        from_unit = UNIT_TYPE_DISTANCE;
    } else if (strcmp(from_unit_str, UNIT_POUNDS) == 0) {
        from_unit = UNIT_TYPE_WEIGHT;
    } else if (strcmp(from_unit_str, UNIT_KILOGRAMS) == 0) {
        from_unit = UNIT_TYPE_WEIGHT;
    } else if (strcmp(from_unit_str, UNIT_LITERS) == 0) {
        from_unit = UNIT_TYPE_VOLUME;
    } else if (strcmp(from_unit_str, UNIT_GALLONS) == 0) {
        from_unit = UNIT_TYPE_VOLUME;
    }

    if (strcmp(to_unit_str, UNIT_CELSIUS) == 0) {
        to_unit = UNIT_TYPE_TEMPERATURE;
    } else if (strcmp(to_unit_str, UNIT_FAHRENHEIT) == 0) {
        to_unit = UNIT_TYPE_TEMPERATURE;
    } else if (strcmp(to_unit_str, UNIT_KILOMETERS) == 0) {
        to_unit = UNIT_TYPE_DISTANCE;
    } else if (strcmp(to_unit_str, UNIT_MILES) == 0) {
        to_unit = UNIT_TYPE_DISTANCE;
    } else if (strcmp(to_unit_str, UNIT_POUNDS) == 0) {
        to_unit = UNIT_TYPE_WEIGHT;
    } else if (strcmp(to_unit_str, UNIT_KILOGRAMS) == 0) {
        to_unit = UNIT_TYPE_WEIGHT;
    } else if (strcmp(to_unit_str, UNIT_LITERS) == 0) {
        to_unit = UNIT_TYPE_VOLUME;
    } else if (strcmp(to_unit_str, UNIT_GALLONS) == 0) {
        to_unit = UNIT_TYPE_VOLUME;
    }

    // Convert the value
    double converted_value = convert(value, from_unit, to_unit);

    // Print the converted value
    printf("%f %s = %f %s\n", value, from_unit_str, converted_value, to_unit_str);

    return EXIT_SUCCESS;
}