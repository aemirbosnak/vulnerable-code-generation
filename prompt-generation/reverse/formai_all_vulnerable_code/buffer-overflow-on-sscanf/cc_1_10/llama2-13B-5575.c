//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_MAX 10

struct unit {
    char name[20];
    double factor;
};

struct unit units[UNIT_MAX] = {
    {"inch", 2.54},
    {"foot", 12},
    {"yard", 36},
    {"mile", 1760},
    {"centimeter", 0.01},
    {"meter", 100},
    {"kilometer", 100000},
    {"gram", 0.001},
    {"kilogram", 1000},
    {"ounce", 0.0283495}
};

int main() {
    char input[50];
    double value, conversion;
    int i;

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("Enter a value: ");
        fgets(input, 50, stdin);

        if (sscanf(input, "%lf", &value) == 1) {
            break;
        }

        printf("Invalid input. Please enter a number.\n");
    }

    printf("Enter the unit you want to convert to: ");
    fgets(input, 50, stdin);

    for (i = 0; i < UNIT_MAX; i++) {
        if (strcmp(units[i].name, input) == 0) {
            conversion = value * units[i].factor;
            printf("The value of %f is %f %s\n", value, conversion, units[i].name);
            break;
        }
    }

    if (i == UNIT_MAX) {
        printf("Invalid unit. Please enter a valid unit.\n");
    }

    return 0;
}