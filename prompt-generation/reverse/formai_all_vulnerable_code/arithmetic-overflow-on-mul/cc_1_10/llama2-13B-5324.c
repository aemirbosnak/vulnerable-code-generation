//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define UNIT_COUNT 10
#define UNIT_NAMES "hslmnt"

struct unit {
    const char *name;
    double factor;
};

static struct unit units[UNIT_COUNT] = {
    {"hour", 3600},
    {"second", 1},
    {"minute", 60},
    {"kilogram", 1000},
    {"liter", 1000},
    {"meter", 1000},
    {"celsius", 1},
    {"fahrenheit", 1.8},
    {" kilometer", 1000000},
    {"miles", 1609.34}
};

int main() {
    int i, j, k;
    double value, conversion;
    char input[100], output[100];

    // Initialize the unit array with random values
    for (i = 0; i < UNIT_COUNT; i++) {
        units[i].factor = drand48() * 10 - 5;
    }

    printf("Welcome to the Unit Converter Puzzle!\n");

    // Prompt the user to enter a value
    printf("Enter a value: ");
    fgets(input, 100, stdin);

    // Convert the value to the chosen unit
    for (i = 0; i < UNIT_COUNT; i++) {
        conversion = value * units[i].factor;
        printf("Conversion: %s (%f)\n", units[i].name, conversion);

        // Print the result in the chosen unit
        sprintf(output, "%.2f %s", conversion, units[i].name);
        printf("%s\n", output);
    }

    return 0;
}