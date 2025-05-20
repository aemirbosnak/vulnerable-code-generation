//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_LENGTH 20

// Define a struct to store the unit conversion information
typedef struct {
    char name[MAX_LENGTH];  // unit name
    double factor;      // conversion factor
} unit_conversion_t;

// Define an array to store the unit conversion information
unit_conversion_t conversions[MAX_UNITS] = {
    {"meter", 1.0},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"inch", 0.0254},
    {"kilogram", 0.001},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"gram", 0.001},
    {"ton", 1000}
};

// Function to convert between units
void convert_units(unit_conversion_t *conversions, int num_conversions, double value, char *unit) {
    int i;
    for (i = 0; i < num_conversions; i++) {
        if (strcmp(unit, conversions[i].name) == 0) {
            break;
        }
    }
    if (i == num_conversions) {
        printf("Invalid unit selected. Please enter a valid unit.\n");
        return;
    }
    printf("Value in %s is %f\n", conversions[i].name, value * conversions[i].factor);
}

int main() {
    int choice;
    double value;
    char unit[MAX_LENGTH];

    // Menu-driven interface
    printf("Welcome to the Unit Converter!\n");
    printf("Please select the unit you want to convert from: ");
    scanf("%s", unit);
    printf("Please enter a value: ");
    scanf("%lf", &value);

    // Display the conversion options
    printf("Here are the conversion options for %s:\n", unit);
    for (int i = 0; i < MAX_UNITS; i++) {
        printf("   - %s (%s)\n", conversions[i].name, conversions[i].name);
    }

    // Get the user's selection
    do {
        printf("Enter the number of the unit you want to convert to: ");
        scanf("%d", &choice);
        convert_units(conversions, MAX_UNITS, value, unit);
    } while (choice != -1);

    return 0;
}