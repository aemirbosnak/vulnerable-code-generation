//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

// Structure to store unit information
typedef struct unit {
    char name[20];
    double factor;
} unit_t;

// Array to store unit information
unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"inch", 0.0254},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"gram", 0.001},
    {"ton", 1000000.0}
};

// Function to convert units
void convert(double value, char *from_unit, char *to_unit) {
    int i = 0;
    double factor = 1.0;

    // Find the from unit in the array
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            break;
        }
    }

    // Calculate the conversion factor
    if (i < MAX_UNITS) {
        factor = units[i].factor;
    }

    // Convert the value to the to unit
    double to_value = value * factor;

    // Print the converted value
    printf("%.2f %s = %.2f %s\n", value, from_unit, to_value, to_unit);
}

int main() {
    double value;
    char from_unit[20];
    char to_unit[20];

    // Get the value to convert
    printf("Enter a value: ");
    scanf("%lf", &value);

    // Get the from unit
    printf("Enter the unit to convert from (meter, kilometer, foot, yard, inch, pound, ounce, gram, ton): ");
    fgets(from_unit, 20, stdin);

    // Get the to unit
    printf("Enter the unit to convert to (meter, kilometer, foot, yard, inch, pound, ounce, gram, ton): ");
    fgets(to_unit, 20, stdin);

    // Convert the value
    convert(value, from_unit, to_unit);

    return 0;
}