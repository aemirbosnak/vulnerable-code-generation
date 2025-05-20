//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char unit_name[20];
    double conversion_factor;
} Unit;

void initialize_units(Unit units[]) {
    // Initialize unit conversions
    strcpy(units[0].unit_name, "meters");
    units[0].conversion_factor = 1.0;

    strcpy(units[1].unit_name, "kilometers");
    units[1].conversion_factor = 0.001;

    strcpy(units[2].unit_name, "centimeters");
    units[2].conversion_factor = 100.0;

    strcpy(units[3].unit_name, "millimeters");
    units[3].conversion_factor = 1000.0;

    strcpy(units[4].unit_name, "feet");
    units[4].conversion_factor = 3.28084;

    strcpy(units[5].unit_name, "inches");
    units[5].conversion_factor = 39.3701;

    strcpy(units[6].unit_name, "yards");
    units[6].conversion_factor = 1.09361;

    strcpy(units[7].unit_name, "miles");
    units[7].conversion_factor = 0.000621371;
}

void display_units(Unit units[], int num_units) {
    printf("Available units for conversion:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d: %s\n", i + 1, units[i].unit_name);
    }
}

double convert_units(double value, Unit from_unit, Unit to_unit) {
    return value * (from_unit.conversion_factor / to_unit.conversion_factor);
}

void show_conversion(double value, Unit from_unit, Unit to_unit) {
    double result = convert_units(value, from_unit, to_unit);
    printf("%.2f %s is equal to %.2f %s\n", value, from_unit.unit_name, result, to_unit.unit_name);
}

int main() {
    printf("Ah, Watson! Welcome to my humble abode of knowledge.\n");
    printf("Today, we embark on a quest—no, a journey!—of unit conversions.\n");

    Unit units[8];
    initialize_units(units);
    
    int num_units = sizeof(units) / sizeof(units[0]);
    display_units(units, num_units);

    int from_index, to_index;
    double value;

    printf("Pray, tell me the number of the unit you wish to convert from: ");
    scanf("%d", &from_index);
    from_index--; // Adjust for zero-based indexing

    printf("And the number of the unit you wish to convert to: ");
    scanf("%d", &to_index);
    to_index--; // Adjust for zero-based indexing

    printf("I need the value you would like to convert: ");
    scanf("%lf", &value);
    
    // Ensure index validity
    if (from_index < 0 || from_index >= num_units || to_index < 0 || to_index >= num_units) {
        printf("Alas, Watson! You've made an incorrect choice. Please restart the program and try again.\n");
        return EXIT_FAILURE;
    }

    show_conversion(value, units[from_index], units[to_index]);

    printf("Thus, our journey through the realm of units concludes. Until next time, dear friend!\n");
    return EXIT_SUCCESS;
}