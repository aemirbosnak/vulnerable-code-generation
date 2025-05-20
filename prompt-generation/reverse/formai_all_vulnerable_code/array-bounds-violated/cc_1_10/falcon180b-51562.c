//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define NUM_UNITS 7

struct Unit {
    char *name;
    double factor;
};

struct Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"grams", 1.0},
    {"kilograms", 1000.0},
    {"liters", 1.0},
    {"milliliters", 0.001},
    {"celsius", 1.0}
};

int main() {
    int choice;
    double value, result;
    char unit_name[20];

    printf("Welcome to the Unit Converter!\n");
    printf("Please choose a unit to convert from:\n");

    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Please enter the value you want to convert:\n");
    scanf("%lf", &value);

    printf("Please choose a unit to convert to:\n");

    for (int i = 0; i < NUM_UNITS; i++) {
        if (i == choice)
            continue;
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Please enter the name of the output unit:\n");
    scanf("%s", unit_name);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%.2lf %s = %.2lf %s\n", value, units[choice].name, result, unit_name);
            break;
        }
    }

    return 0;
}