//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 7

struct unit {
    char *name;
    double factor;
};

struct unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"grams", 1.0},
    {"kilograms", 1000.0},
    {"liters", 1.0},
    {"gallons", 3.78541},
    {"fahrenheit", 1.0}
};

int main() {
    char input[100], output[100];
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Please select a unit to convert from:\n");

    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Please enter the value to convert: ");
    scanf("%s", input);

    printf("Please select a unit to convert to:\n");

    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    double result = atof(input) * units[choice-1].factor;

    printf("%.2f %s is equal to %.2f %s.\n", atof(input), units[choice-1].name, result, units[(choice-1+NUM_UNITS)%NUM_UNITS].name);

    return 0;
}