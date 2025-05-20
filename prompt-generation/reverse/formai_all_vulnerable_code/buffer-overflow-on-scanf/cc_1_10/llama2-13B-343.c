//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to store unit information
typedef struct {
    char name[20]; // unit name
    double factor; // conversion factor
} unit_t;

// Declare an array to store all units
unit_t units[] = {
    {"m", 1.0}, // meter
    {"cm", 0.01}, // centimeter
    {"mm", 0.001}, // millimeter
    {"km", 1000}, // kilometer
    {"mi", 1609.344}, // mile
    {"yd", 0.9144}, // yard
    {"ft", 0.3048}, // foot
    {"in", 0.0254}, // inch
    {"pt", 0.0007874}, // point
    {"pc", 0.00002835}, // pica
};

// Declare a function to convert between units
void convert(unit_t from, unit_t to, double value) {
    // Check if the from and to units are the same
    if (from.name == to.name) {
        // If so, just return the value
        printf("%.2f %s\n", value, from.name);
        return;
    }

    // Calculate the conversion factor
    double factor = from.factor / to.factor;

    // Recursively call the function with the converted value
    convert(to, from, value * factor);
}

int main() {
    // Prompt the user for the value and unit
    double value = 10.5;
    char unit[20];
    printf("Enter a value and unit (e.g. 10.5 m or 10.5 ft): ");
    scanf("%lf %19s", &value, unit);

    // Find the unit in the array
    int i = 0;
    while (strcmp(units[i].name, unit) != 0) {
        i++;
    }

    // Convert the value to the target unit
    convert(units[i], units[0], value);

    return 0;
}