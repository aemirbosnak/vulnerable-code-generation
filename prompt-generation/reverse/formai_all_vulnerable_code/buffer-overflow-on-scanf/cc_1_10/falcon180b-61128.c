//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSION_FACTORS 5
#define MAX_CONVERSION_FACTOR_NAME_LENGTH 20

// Define the units and their conversion factors
typedef struct {
    char name[MAX_CONVERSION_FACTOR_NAME_LENGTH];
    double factor;
} conversion_factor;

conversion_factor units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"l", 1.0},
    {"ml", 0.001}
};

// Function to convert a value from one unit to another
double convert(double value, char from_unit[], char to_unit[]) {
    int i, j;

    // Find the index of the input unit
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            break;
        }
    }

    // Find the index of the output unit
    for (j = 0; j < MAX_UNITS; j++) {
        if (strcmp(units[j].name, to_unit) == 0) {
            break;
        }
    }

    // Convert the value using the conversion factors
    return (value * units[i].factor) / units[j].factor;
}

int main() {
    char from_unit[MAX_CONVERSION_FACTOR_NAME_LENGTH], to_unit[MAX_CONVERSION_FACTOR_NAME_LENGTH];
    double value;

    // Get the input value and units from the user
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the input unit: ");
    scanf("%s", from_unit);
    printf("Enter the output unit: ");
    scanf("%s", to_unit);

    // Convert the value and display the result
    printf("%.2lf %s = %.2lf %s\n", value, from_unit, convert(value, from_unit, to_unit), to_unit);

    return 0;
}