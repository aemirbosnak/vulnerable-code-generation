//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"centimeter", 0.01},
    {" millimeter", 0.001},
    {"kilogram", 1000.0},
    {"gram", 0.001}
};

int main() {
    int i, j, num_units, num_conversions;
    double value, converted_value;
    char input_unit[20], output_unit[20];

    // Initialize variables
    num_units = 0;
    num_conversions = 0;

    // Get input value and unit
    printf("Enter a value: ");
    scanf("%lf", &value);
    gets(input_unit);

    // Convert value to all available units
    for (i = 0; i < MAX_UNITS; i++) {
        converted_value = value * units[i].factor;
        printf("%s: %f\n", units[i].name, converted_value);
        num_conversions++;
    }

    // Convert value to all available units in reverse order
    for (i = MAX_UNITS - 1; i >= 0; i--) {
        converted_value = value / units[i].factor;
        printf("%s: %f\n", units[i].name, converted_value);
        num_conversions++;
    }

    // Check if user wants to convert again
    printf("Do you want to convert again? (y/n): ");
    gets(input_unit);
    if (strcmp(input_unit, "y") == 0) {
        // Loop back to convert again
        main();
    } else {
        // End program
        printf("Program ended.%c", '\n');
    }

    return 0;
}