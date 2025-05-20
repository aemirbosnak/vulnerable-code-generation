//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"grams", 1.0},
    {"kilograms", 1000.0},
    {"liters", 1.0},
    {"milliliters", 0.001},
    {"celsius", 1.0}
};

int main() {
    char input[100];
    char *unit1, *unit2;
    double value, result;
    int choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Please select the unit you want to convert from:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    scanf("%d", &choice);
    unit1 = units[choice - 1].name;

    printf("Please select the unit you want to convert to:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    scanf("%d", &choice);
    unit2 = units[choice - 1].name;

    result = value * units[choice - 1].factor;

    if (strcmp(unit1, unit2) == 0) {
        printf("The value %.2lf %s is equal to %.2lf %s.\n", value, unit1, value, unit2);
    } else {
        printf("The value %.2lf %s is equal to %.2lf %s.\n", value, unit1, result, unit2);
    }

    return 0;
}