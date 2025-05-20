//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Unit types
typedef enum {
    UNIT_NONE,
    UNIT_LENGTH,
    UNIT_MASS,
    UNIT_TIME,
    UNIT_TEMPERATURE
} unit_type;

// Unit conversion functions
double convert_length(double value, char *from_unit, char *to_unit);
double convert_mass(double value, char *from_unit, char *to_unit);
double convert_time(double value, char *from_unit, char *to_unit);
double convert_temperature(double value, char *from_unit, char *to_unit);

// Unit table
static const struct unit_table {
    unit_type type;
    char *name;
    double conversion_factor;
} unit_table[] = {
    { UNIT_LENGTH, "meter", 1.0 },
    { UNIT_LENGTH, "kilometer", 1000.0 },
    { UNIT_LENGTH, "mile", 1609.34 },
    { UNIT_LENGTH, "foot", 0.3048 },
    { UNIT_LENGTH, "inch", 0.0254 },
    { UNIT_MASS, "kilogram", 1.0 },
    { UNIT_MASS, "gram", 0.001 },
    { UNIT_MASS, "pound", 0.453592 },
    { UNIT_MASS, "ounce", 0.0283495 },
    { UNIT_TIME, "second", 1.0 },
    { UNIT_TIME, "minute", 60.0 },
    { UNIT_TIME, "hour", 3600.0 },
    { UNIT_TIME, "day", 86400.0 },
    { UNIT_TEMPERATURE, "celsius", 1.0 },
    { UNIT_TEMPERATURE, "fahrenheit", (5.0/9.0) },
    { UNIT_TEMPERATURE, "kelvin", 1.0 },
};

// Main function
int main(void) {
    char input[100];
    double value;
    char from_unit[20];
    char to_unit[20];

    // Get user input
    printf("Enter a value and unit to convert: ");
    fgets(input, sizeof(input), stdin);

    // Parse user input
    sscanf(input, "%lf %s to %s", &value, from_unit, to_unit);

    // Find the conversion function
    double (*convert_func)(double, char *, char *) = NULL;
    for (int i = 0; i < sizeof(unit_table) / sizeof(unit_table[0]); i++) {
        if (strcmp(unit_table[i].name, from_unit) == 0) {
            convert_func = convert_length;
            break;
        } else if (strcmp(unit_table[i].name, to_unit) == 0) {
            convert_func = convert_length;
            break;
        }
    }

    // Convert the value
    double converted_value = convert_func(value, from_unit, to_unit);

    // Print the result
    printf("%lf %s = %lf %s\n", value, from_unit, converted_value, to_unit);

    return 0;
}

// Unit conversion functions
double convert_length(double value, char *from_unit, char *to_unit) {
    // Find the conversion factor
    double conversion_factor = 1.0;
    for (int i = 0; i < sizeof(unit_table) / sizeof(unit_table[0]); i++) {
        if (strcmp(unit_table[i].name, from_unit) == 0) {
            conversion_factor *= unit_table[i].conversion_factor;
        } else if (strcmp(unit_table[i].name, to_unit) == 0) {
            conversion_factor /= unit_table[i].conversion_factor;
        }
    }

    // Convert the value
    return value * conversion_factor;
}

double convert_mass(double value, char *from_unit, char *to_unit) {
    // Find the conversion factor
    double conversion_factor = 1.0;
    for (int i = 0; i < sizeof(unit_table) / sizeof(unit_table[0]); i++) {
        if (strcmp(unit_table[i].name, from_unit) == 0) {
            conversion_factor *= unit_table[i].conversion_factor;
        } else if (strcmp(unit_table[i].name, to_unit) == 0) {
            conversion_factor /= unit_table[i].conversion_factor;
        }
    }

    // Convert the value
    return value * conversion_factor;
}

double convert_time(double value, char *from_unit, char *to_unit) {
    // Find the conversion factor
    double conversion_factor = 1.0;
    for (int i = 0; i < sizeof(unit_table) / sizeof(unit_table[0]); i++) {
        if (strcmp(unit_table[i].name, from_unit) == 0) {
            conversion_factor *= unit_table[i].conversion_factor;
        } else if (strcmp(unit_table[i].name, to_unit) == 0) {
            conversion_factor /= unit_table[i].conversion_factor;
        }
    }

    // Convert the value
    return value * conversion_factor;
}

double convert_temperature(double value, char *from_unit, char *to_unit) {
    // Find the conversion factor
    double conversion_factor = 1.0;
    for (int i = 0; i < sizeof(unit_table) / sizeof(unit_table[0]); i++) {
        if (strcmp(unit_table[i].name, from_unit) == 0) {
            conversion_factor *= unit_table[i].conversion_factor;
        } else if (strcmp(unit_table[i].name, to_unit) == 0) {
            conversion_factor /= unit_table[i].conversion_factor;
        }
    }

    // Convert the value
    return value * conversion_factor;
}