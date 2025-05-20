//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double factor;
} Unit;

typedef struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
} Conversion;

Unit units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
};

Conversion conversions[MAX_CONVERTIONS] = {
    {"meter", "foot", 3.28084},
    {"kilometer", "mile", 0.621371},
    {"inch", "meter", 25.4},
    {"yard", "meter", 0.9144},
};

int main() {
    int i, j;
    double value;
    char input_unit[20];
    char output_unit[20];

    printf("Welcome to the Unit Converter!\n");

    // Get the input value from the user
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Get the input unit from the user
    printf("Enter the input unit (e.g. meter, kilometer, inch, etc.): ");
    scanf("%19s", input_unit);

    // Check if the input unit is valid
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid input unit. Please try again.\n");
        return 1;
    }

    // Get the output unit from the user
    printf("Do you want to convert to another unit? (y/n): ");
    scanf(" %c", &input_unit[0]);

    if (input_unit[0] == 'y') {
        // Get the output unit from the user
        printf("Enter the output unit (e.g. meter, kilometer, inch, etc.): ");
        scanf("%19s", output_unit);

        // Check if the output unit is valid
        for (j = 0; j < MAX_UNITS; j++) {
            if (strcmp(output_unit, units[j].name) == 0) {
                break;
            }
        }

        if (j == MAX_UNITS) {
            printf("Invalid output unit. Please try again.\n");
            return 1;
        }

        // Perform the conversion
        value *= conversions[i].factor;
        value /= conversions[j].factor;
    }

    // Print the result
    printf("The value of %s is %lf %s.\n", input_unit, value, output_unit);

    return 0;
}