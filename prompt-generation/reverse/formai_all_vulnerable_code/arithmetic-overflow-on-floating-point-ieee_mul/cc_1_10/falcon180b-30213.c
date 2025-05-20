//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_UNITS 10

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
    {"milliliters", 0.001},
    {"seconds", 1.0},
    {"minutes", 60.0},
    {"hours", 3600.0},
    {"degrees Celsius", 1.0}
};

int main() {
    int choice;
    double value, result;
    char unit_name[20];

    printf("Welcome to the Shocked Unit Converter!\n");
    printf("Please choose a unit to convert from:\n");

    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Please enter a value to convert: ");
    scanf("%lf", &value);

    printf("Please enter the unit you want to convert to:\n");
    scanf("%s", unit_name);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(units[i].name, unit_name) == 0) {
            result = value * units[i].factor;
            printf("%.2lf %s = %.2lf %s\n", value, units[i].name, result, units[i].name);
            break;
        }
    }

    return 0;
}