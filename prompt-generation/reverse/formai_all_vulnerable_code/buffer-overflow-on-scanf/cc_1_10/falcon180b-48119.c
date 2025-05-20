//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    char input[100];
    char from_unit[20];
    char to_unit[20];
    double value;
    int i;

    Unit units[MAX_UNITS] = {
        {"meters", 1.0},
        {"centimeters", 0.01},
        {"millimeters", 0.001},
        {"kilograms", 1.0},
        {"grams", 0.001},
        {"liters", 1.0},
        {"milliliters", 0.001},
        {"seconds", 1.0},
        {"minutes", 60.0},
        {"hours", 3600.0}
    };

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid input: %s is not a recognized unit.\n", from_unit);
        return 1;
    }

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Invalid input: %s is not a recognized unit.\n", to_unit);
        return 1;
    }

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, value * units[i].factor, to_unit);

    return 0;
}