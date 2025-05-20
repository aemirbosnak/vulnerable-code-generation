//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    double conversion_factor;
} Unit;

// Function to initialize the units
void init_units(Unit units[], int *count) {
    strcpy(units[(*count)++].name, "meters");
    units[*count - 1].conversion_factor = 1.0; // base unit

    strcpy(units[(*count)++].name, "kilometers");
    units[*count - 1].conversion_factor = 1000.0;

    strcpy(units[(*count)++].name, "centimeters");
    units[*count - 1].conversion_factor = 0.01;

    strcpy(units[(*count)++].name, "millimeters");
    units[*count - 1].conversion_factor = 0.001;

    strcpy(units[(*count)++].name, "inches");
    units[*count - 1].conversion_factor = 0.0254;

    strcpy(units[(*count)++].name, "feet");
    units[*count - 1].conversion_factor = 0.3048;

    strcpy(units[(*count)++].name, "yards");
    units[*count - 1].conversion_factor = 0.9144;

    strcpy(units[(*count)++].name, "miles");
    units[*count - 1].conversion_factor = 1609.34;

    strcpy(units[(*count)++].name, "nautical miles");
    units[*count - 1].conversion_factor = 1852;
}

// Function to display the available units
void display_units(Unit units[], int count) {
    printf("Available Units:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, units[i].name);
    }
}

// Function to convert a value from one unit to another
double convert(double value, double from_factor, double to_factor) {
    return value * (from_factor / to_factor);
}

// Main function
int main() {
    Unit units[20];
    int unit_count = 0;
    init_units(units, &unit_count);

    display_units(units, unit_count);

    int from_unit, to_unit;
    double value;

    printf("Enter the unit you are converting from (1-%d): ", unit_count);
    scanf("%d", &from_unit);
    
    if (from_unit < 1 || from_unit > unit_count) {
        printf("Invalid selection. Exiting.\n");
        exit(1);
    }

    printf("Enter the unit you are converting to (1-%d): ", unit_count);
    scanf("%d", &to_unit);
    
    if (to_unit < 1 || to_unit > unit_count) {
        printf("Invalid selection. Exiting.\n");
        exit(1);
    }

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    double converted_value = convert(value, units[from_unit - 1].conversion_factor, units[to_unit - 1].conversion_factor);
    
    printf("%.2f %s is equal to %.2f %s\n", value, units[from_unit - 1].name, converted_value, units[to_unit - 1].name);

    return 0;
}