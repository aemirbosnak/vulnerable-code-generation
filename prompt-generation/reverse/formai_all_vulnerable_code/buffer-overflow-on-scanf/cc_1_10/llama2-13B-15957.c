//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 3

// Define the units and their symbols
typedef struct {
    char *name;
    char *symbol;
} Unit;

Unit units[] = {
    {"foot", 'f'},
    {"yard", 'y'},
    {"mile", 'm'},
    {"inch", 'i'},
    {"pound", 'p'}
};

// Define the conversion table
typedef struct {
    char *from_unit;
    char *to_unit;
    double factor;
} Conversion;

Conversion conversions[] = {
    {"f", "y", 3.0},
    {"y", "m", 1.0/3.0},
    {"m", "i", 12.0/3.0},
    {"i", "p", 12.0/12.0},
    {"p", "f", 1.0/12.0}
};

// Function to convert a value from one unit to another
double convert(double value, char from_unit, char to_unit) {
    int i = 0;
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        if (conversions[i].from_unit == from_unit && conversions[i].to_unit == to_unit) {
            break;
        }
    }
    if (i == MAX_CONVERSIONS) {
        printf("Oops! No such conversion exists from %c to %c!\n", from_unit, to_unit);
        return 0;
    }
    return value * conversions[i].factor;
}

int main() {
    char input_unit[5];
    char output_unit[5];
    double input_value;
    double output_value;

    printf("Welcome to the medieval unit converter!\n");

    // Ask the user for the input value
    printf("What is the value you wish to convert? ");
    scanf("%lf", &input_value);

    // Ask the user for the input unit
    printf("In what unit do you wish to express the value? (f/y/m/i/p) ");
    scanf("%4s", input_unit);

    // Convert the value to the desired unit
    output_value = convert(input_value, input_unit[0], output_unit[0]);

    // Print the output value and unit
    printf("The value of %4.2f %s is equal to %4.2f %s.\n",
           input_value, input_unit, output_value, output_unit);

    return 0;
}