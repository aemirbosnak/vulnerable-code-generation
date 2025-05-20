//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the units to convert from and to
typedef struct {
    char *name;
    double factor;
} unit_t;

#define UNIT_COUNT 7

unit_t units[UNIT_COUNT] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"meter", 1000},
    {"centimeter", 0.01},
    {"kilometer", 1000000}
};

// Function to convert between units
double convert(double value, unit_t from, unit_t to) {
    return value * from.factor / to.factor;
}

int main() {
    // Prompt user for input
    printf("Enter a value to convert: ");
    double value;
    scanf("%lf", &value);

    // Prompt user for units to convert from and to
    char from_unit[20];
    char to_unit[20];
    printf("Enter the unit to convert from (e.g. 'inch'): ");
    fgets(from_unit, 20, stdin);
    printf("Enter the unit to convert to (e.g. 'meter'): ");
    fgets(to_unit, 20, stdin);

    // Find the corresponding unit structures
    int from_index = 0;
    for (int i = 0; i < UNIT_COUNT; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_index = i;
            break;
        }
    }

    int to_index = 0;
    for (int i = 0; i < UNIT_COUNT; i++) {
        if (strcmp(units[i].name, to_unit) == 0) {
            to_index = i;
            break;
        }
    }

    // Perform the conversion
    double converted_value = convert(value, units[from_index], units[to_index]);

    // Print the result
    printf("Value in %s is %lf\n", units[to_index].name, converted_value);

    return 0;
}