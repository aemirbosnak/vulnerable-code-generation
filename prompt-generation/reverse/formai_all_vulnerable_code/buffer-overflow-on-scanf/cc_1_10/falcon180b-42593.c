//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 10

struct unit_conversion {
    char *name;
    double factor;
};

struct unit_conversion units[MAX_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"grams", 1.0},
    {"kilograms", 1000.0},
    {"liters", 1.0},
    {"gallons", 3.78541},
    {"celsius", 1.0},
    {"fahrenheit", 1.8},
    {"joules", 1.0},
    {"calories", 4.184}
};

int main() {
    int choice, i;
    double value, result;
    char input[100];

    printf("Welcome to the Unit Converter!\n");
    printf("Please choose a unit to convert:\n");

    for (i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }

    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            result = value * units[0].factor;
            printf("%.2lf %s is equal to %.2lf %s.\n", value, units[0].name, result, units[choice-1].name);
            break;
        case 2:
            result = value / units[0].factor;
            printf("%.2lf %s is equal to %.2lf %s.\n", value, units[0].name, result, units[choice-1].name);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}