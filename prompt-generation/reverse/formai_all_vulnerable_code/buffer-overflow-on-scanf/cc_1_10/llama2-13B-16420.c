//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

typedef struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
} conversion_t;

unit_t units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"mi", 1609.344}
};

conversion_t conversions[MAX_CONVERSIONS] = {
    {"m", "cm", 100.0},
    {"cm", "mm", 10.0},
    {"mm", "km", 0.001},
    {"km", "mi", 0.621371},
    {"mi", "m", 1609.344}
};

int main() {
    int i, j;
    char input_unit[20];
    char output_unit[20];
    double input_value;
    double output_value;

    printf("Welcome to the Unit Converter!\n");

    // Initialize the input and output units
    input_unit[0] = '\0';
    output_unit[0] = '\0';

    // Get the input value
    printf("Enter a value: ");
    scanf("%lf", &input_value);

    // Get the input unit
    printf("Enter the unit of the input value (e.g. 'm', 'cm', etc.): ");
    fgets(input_unit, 20, stdin);
    input_unit[strcspn(input_unit, "\n")] = '\0';

    // Iterate through the list of units and convert the input value
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid unit. Please enter a valid unit (e.g. 'm', 'cm', etc.).\n");
        return 1;
    }

    for (j = 0; j < MAX_CONVERSIONS; j++) {
        if (strcmp(input_unit, conversions[j].from_unit) == 0) {
            break;
        }
    }

    if (j == MAX_CONVERSIONS) {
        printf("Invalid conversion. Please enter a valid conversion (e.g. 'm to cm').\n");
        return 1;
    }

    // Perform the conversion
    output_value = input_value * conversions[j].factor;

    // Print the output value and unit
    printf("The value of %s is %lf %s.\n", input_unit, output_value, conversions[j].to_unit);

    return 0;
}