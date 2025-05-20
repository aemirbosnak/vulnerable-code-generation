//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_CONVERTIONS 100

// Structure to store unit information
typedef struct {
    char name[20];  // Unit name
    double factor;  // Conversion factor
} unit_t;

// Array to store all units
unit_t units[UNIT_CONVERTER_MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {" millimeter", 0.001},
    {"yard", 0.9144},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"mile", 1609.344},
    {"liter", 0.001},
    {"gallon", 0.003785},
    {"cup", 0.0832768}
};

// Function to convert a value from one unit to another
double convert_unit(double value, char from_unit[20], char to_unit[20]) {
    int from_index = 0;
    int to_index = 0;
    double factor = 1.0;

    // Find the index of the from unit in the array
    while (from_index < UNIT_CONVERTER_MAX_UNITS && strcmp(units[from_index].name, from_unit) != 0) {
        from_index++;
    }

    // Find the index of the to unit in the array
    while (to_index < UNIT_CONVERTER_MAX_UNITS && strcmp(units[to_index].name, to_unit) != 0) {
        to_index++;
    }

    // Check if the conversion is valid
    if (from_index == UNIT_CONVERTER_MAX_UNITS || to_index == UNIT_CONVERTER_MAX_UNITS) {
        printf("Invalid unit conversion request. Please enter a valid unit name.\n");
        return 0.0;
    }

    // Calculate the conversion factor
    factor = units[from_index].factor / units[to_index].factor;

    // Perform the conversion
    return value * factor;
}

int main() {
    double value;
    char from_unit[20];
    char to_unit[20];

    // Get the value to convert
    printf("Enter a value to convert: ");
    scanf("%lf", &value);

    // Get the from unit
    printf("Enter the unit you want to convert from (e.g. meter): ");
    scanf("%19s", from_unit);

    // Get the to unit
    printf("Enter the unit you want to convert to (e.g. kilometer): ");
    scanf("%19s", to_unit);

    // Convert the value
    double converted_value = convert_unit(value, from_unit, to_unit);

    // Print the result
    printf("The value of %lf %s is %lf %s\n", value, from_unit, converted_value, to_unit);

    return 0;
}