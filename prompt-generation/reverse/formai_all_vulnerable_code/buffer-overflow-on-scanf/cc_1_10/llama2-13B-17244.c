//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for each unit type
typedef struct {
    char *name; // unit name (e.g. "inch")
    double factor; // conversion factor to base unit (e.g. 1 inch = 2.54 cm)
} unit_t;

// Define an array to store all available unit types
unit_t units[] = {
    {"inch", 2.54},
    {"foot", 12.0},
    {"yard", 36.0},
    {"centimeter", 0.01},
    {"meter", 100.0},
    {"kilometer", 100000.0}
};

// Define a function to perform conversions
double convert(double value, unit_t from_unit, unit_t to_unit) {
    return value * from_unit.factor / to_unit.factor;
}

int main() {
    double value, from_value;
    unit_t from_unit, to_unit;

    // Get the input values
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Get the from unit
    printf("Enter the from unit (inch/foot/yard/etc.): ");
    scanf("%s", &from_unit.name);

    // Get the to unit
    printf("Enter the to unit (inch/foot/yard/etc.): ");
    scanf("%s", &to_unit.name);

    // Perform the conversion
    from_value = value;
    if (strcmp(from_unit.name, "inch") == 0) {
        from_value = convert(from_value, from_unit, units[1]);
    } else if (strcmp(from_unit.name, "foot") == 0) {
        from_value = convert(from_value, from_unit, units[2]);
    } else if (strcmp(from_unit.name, "yard") == 0) {
        from_value = convert(from_value, from_unit, units[3]);
    } else {
        from_value = convert(from_value, from_unit, units[4]);
    }

    // Print the result
    printf("The value of %s is %lf %s\n", from_unit.name, from_value, to_unit.name);

    return 0;
}