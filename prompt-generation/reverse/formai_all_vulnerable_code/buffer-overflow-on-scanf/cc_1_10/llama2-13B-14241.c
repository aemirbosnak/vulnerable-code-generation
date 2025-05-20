//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct {
    char name[20];
    double value;
} Unit;

Unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 1760},
    {"kilogram", 0.001},
    {"gram", 0.001},
    {"pound", 0.453592},
    {"ounce", 0.0283495},
    {"fluid_ounce", 0.0236588},
    {"gallon", 3.785}
};

int main() {
    int i, j, num_conversions = 0;
    double conversion_factors[MAX_CONVERSIONS][MAX_UNITS] = {
        {1, 1},
        {12, 1},
        {36, 1},
        {1760, 1},
        {0.001, 1},
        {0.001, 1},
        {0.453592, 1},
        {0.0283495, 1},
        {0.0236588, 1},
        {3.785, 1}
    };

    printf("Welcome to the Unit Converter!\n");

    // Prompt user for input
    printf("Enter the value you want to convert: ");
    double user_input;
    scanf("%lf", &user_input);

    // Convert value to all units
    for (i = 0; i < MAX_UNITS; i++) {
        for (j = 0; j < MAX_CONVERSIONS; j++) {
            double converted_value = user_input * conversion_factors[j][i];
            printf("Value in unit %s is %f\n", units[i].name, converted_value);
        }
    }

    return 0;
}