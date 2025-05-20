//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

struct unit_conversion {
    char *name;
    double factor;
};

struct unit_conversion units[MAX_UNITS] = {
    {"meters", 1.0},
    {"feet", 3.28084},
    {"inches", 39.3701},
    {"kilograms", 1.0},
    {"pounds", 2.20462},
    {"ounces", 35.274},
    {"gallons", 3.78541},
    {"liters", 1.0},
    {"celsius", 1.0},
    {"fahrenheit", 1.8}
};

int main() {
    int choice, num_units;
    double value, result;
    char input[100];

    printf("Welcome to the Unit Converter!\n");
    printf("Please select a unit of measurement:\n");

    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_UNITS) {
        printf("Invalid choice. Exiting program.\n");
        return 1;
    }

    printf("Please enter the value to convert:\n");
    scanf("%lf", &value);

    printf("Please enter the number of units to convert:\n");
    scanf("%d", &num_units);

    printf("Please enter the unit of measurement to convert from:\n");
    scanf("%s", input);

    if (strcmp(input, units[choice - 1].name)!= 0) {
        printf("Invalid unit of measurement. Exiting program.\n");
        return 1;
    }

    for (int i = 0; i < num_units; i++) {
        result = value * units[choice - 1].factor;
        printf("%lf %s = %lf %s\n", value, input, result, units[choice - 1].name);
        value = result;
    }

    return 0;
}