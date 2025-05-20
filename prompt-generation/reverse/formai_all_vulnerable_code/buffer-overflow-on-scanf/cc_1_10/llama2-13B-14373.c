//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define UNIT_COUNT 10
#define UNIT_MAX_LEN 20

typedef struct unit {
    char name[UNIT_MAX_LEN];
    double conversion_factor;
} unit_t;

unit_t units[] = {
    {"inch", 2.54},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 1760.0},
    {"kilogram", 0.001},
    {"gram", 0.000001},
    {"ounce", 0.0283495},
    {"pound", 0.453592},
    {"cup", 0.236608},
    {"gallon", 3.785014}
};

int main() {
    int i, j;
    double input, output;
    char unit_input[UNIT_MAX_LEN];
    char unit_output[UNIT_MAX_LEN];

    srand(time(NULL));

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("Enter a value: ");
        scanf("%lf", &input);

        // Generate a random unit to convert to
        i = rand() % UNIT_COUNT;
        unit_t *unit = units + i;

        // Convert the input value to the random unit
        output = input * unit->conversion_factor;

        // Print the output value in the random unit
        printf("%.2lf %s = %.2lf %s\n", input, unit->name, output, unit->name);

        // Ask the user if they want to convert again
        printf("Do you want to convert again? (y/n): ");
        scanf(" %c", &j);

    } while (j == 'y');

    return 0;
}