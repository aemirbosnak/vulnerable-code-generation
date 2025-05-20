//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

// Unit conversion factors
double length_factors[MAX_UNITS] = {1, 0.001, 0.000001, 0.000000001};
double weight_factors[MAX_UNITS] = {1, 0.001, 0.000001, 0.000000001};
double volume_factors[MAX_UNITS] = {1, 0.001, 0.000001, 0.000000001};

// Function to perform unit conversion
double convert_unit(double value, int from_unit, int to_unit) {
    double factor = 1.0;
    if (from_unit == to_unit) {
        return value;
    } else if (from_unit < to_unit) {
        factor = length_factors[to_unit];
    } else {
        factor = length_factors[from_unit];
    }
    return value * factor;
}

int main() {
    int choice, num_units, i;
    char unit_name[MAX_UNITS][10];
    double value, converted_value;

    // Initialize unit names
    strcpy(unit_name[0], "Meters");
    strcpy(unit_name[1], "Centimeters");
    strcpy(unit_name[2], "Millimeters");
    strcpy(unit_name[3], "Kilometers");
    strcpy(unit_name[4], "Grams");
    strcpy(unit_name[5], "Milligrams");
    strcpy(unit_name[6], "Micrograms");
    strcpy(unit_name[7], "Kilograms");
    strcpy(unit_name[8], "Liters");
    strcpy(unit_name[9], "Milliliters");

    // Get number of units from user
    printf("Enter number of units (1-10): ");
    scanf("%d", &num_units);

    // Get unit names from user
    for (i = 0; i < num_units; i++) {
        printf("Enter unit name %d: ", i+1);
        scanf("%s", unit_name[i]);
    }

    // Get value to convert
    printf("Enter value to convert: ");
    scanf("%lf", &value);

    // Perform unit conversion
    for (i = 0; i < num_units; i++) {
        converted_value = convert_unit(value, 0, i);
        printf("%s = %lf %s\n", unit_name[i], converted_value, unit_name[i]);
    }

    return 0;
}