//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_LENGTH 32

typedef struct unit {
    char name[MAX_LENGTH];
    double factor;
} Unit;

Unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 1760},
    {"meter", 1000},
    {"centimeter", 0.01},
    {"kilometer", 1000000},
    {"gram", 0.001},
    {"kilogram", 1000},
    {"pound", 453.592}
};

int main() {
    char input[MAX_LENGTH];
    double value, converted_value;
    int i;

    printf("Enter a value: ");
    fgets(input, MAX_LENGTH, stdin);

    // Parse the input
    sscanf(input, "%lf", &value);

    // Find the corresponding unit
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, input) == 0) {
            break;
        }
    }

    // Convert the value to the chosen unit
    converted_value = value * units[i].factor;

    // Print the result
    printf("The value in %s is %f\n", units[i].name, converted_value);

    return 0;
}