//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERTIONS 5

// Structure to hold the unit and its conversion factors
typedef struct {
    char *name;
    double factor;
} Unit;

// Array to store the units and their conversion factors
Unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 5280.0},
    {"pound", 0.453592}
};

// Function to convert between units
void convert(Unit *from, Unit *to, double value) {
    double factor = from->factor / to->factor;
    double result = value * factor;
    printf("%.2f %s = %%.2f %s\n", from->name, value, to->name, result);
}

int main() {
    int choice;
    double value;
    char unit[20];

    // Welcome message
    printf("Welcome to the Unit Converter! \n");

    // Menu to select the units and conversion
    printf("Choose a unit to convert from: \n");
    printf("1. Inch\n2. Foot\n3. Yard\n4. Mile\n5. Pound\n");
    scanf("%d", &choice);

    // Get the value to convert
    printf("Enter a value to convert: ");
    scanf("%lf", &value);

    // Get the unit to convert to
    printf("Choose a unit to convert to: \n");
    printf("1. Inch\n2. Foot\n3. Yard\n4. Mile\n5. Pound\n");
    scanf("%d", &choice);

    // Convert the value between units
    convert(units + choice - 1, units + choice - 1, value);

    return 0;
}