//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the unit types and their conversion factors
typedef enum {
    UNIT_NONE = 0,
    UNIT_METRIC,
    UNIT_IMPERIAL,
    UNIT_OTHER
} unit_type_t;

typedef struct {
    const char *name;
    double conversion_factor;
} unit_t;

static unit_t units[] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"gram", 0.001},
    {"kilogram", 1000.0},
    {"liter", 1000.0},
    {"milliliter", 0.001},
    {"celsius", 1.0},
    {"fahrenheit", 1.8},
    {"inch", 2.54},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"pound", 0.453592}
};

// Define the conversion functions
void convert_metric_to_metric(double value, unit_type_t from_unit, unit_type_t to_unit) {
    value *= units[from_unit].conversion_factor;
    value /= units[to_unit].conversion_factor;
}

void convert_metric_to_imperial(double value, unit_type_t from_unit, unit_type_t to_unit) {
    value *= units[from_unit].conversion_factor;
    value /= units[to_unit].conversion_factor;
    value += 273.15; // convert celsius to fahrenheit
}

void convert_imperial_to_metric(double value, unit_type_t from_unit, unit_type_t to_unit) {
    value *= units[from_unit].conversion_factor;
    value /= units[to_unit].conversion_factor;
    value -= 273.15; // convert fahrenheit to celsius
}

// Define the main function
int main() {
    unit_type_t from_unit, to_unit;
    double value;

    printf("Enter a value and two unit types (e.g. '50 meter' or '200 pound') : ");
    scanf("%lf %c %c", &value, &from_unit, &to_unit);

    if (from_unit == UNIT_METRIC && to_unit == UNIT_METRIC) {
        convert_metric_to_metric(value, from_unit, to_unit);
    } else if (from_unit == UNIT_METRIC && to_unit == UNIT_IMPERIAL) {
        convert_metric_to_imperial(value, from_unit, to_unit);
    } else if (from_unit == UNIT_IMPERIAL && to_unit == UNIT_METRIC) {
        convert_imperial_to_metric(value, from_unit, to_unit);
    } else {
        printf("Invalid unit types. Please try again.\n");
        return 1;
    }

    printf("Value in unit %c is %lf\n", to_unit, value);

    return 0;
}