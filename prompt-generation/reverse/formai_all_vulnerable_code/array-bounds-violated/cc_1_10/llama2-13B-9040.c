//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

// Structure to store unit information
typedef struct {
    char name[20];  // Unit name
    double factor;  // Conversion factor
} unit_t;

// Array to store unit information
unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.344}
};

// Function to perform unit conversion
double convert_unit(double value, unit_t from_unit, unit_t to_unit) {
    return value * from_unit.factor / to_unit.factor;
}

int main() {
    int i, j;
    double value, result;
    char input_unit[20], output_unit[20];

    // Print menu to select input and output units
    printf("Select input unit: ");
    for (i = 0; i < MAX_UNITS; i++) {
        printf("%d: %s\n", i, units[i].name);
    }
    scanf("%d", &i);
    printf("Select output unit: ");
    for (j = 0; j < MAX_UNITS; j++) {
        printf("%d: %s\n", j, units[j].name);
    }
    scanf("%d", &j);

    // Get input value from user
    printf("Enter value: ");
    scanf("%lf", &value);

    // Perform unit conversion
    result = convert_unit(value, units[i], units[j]);

    // Print result in selected output unit
    sprintf(output_unit, "%.2f %s", result, units[j].name);
    printf("Result: %s\n", output_unit);

    return 0;
}