//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_UNITS 7

struct unit {
    char *name;
    double factor;
};

struct unit units[MAX_UNITS] = {
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
    char unit_name[50];

    printf("Welcome to the Unit Converter!\n\n");
    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit_name);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit_name);

    choice = -1;
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, unit_name) == 0) {
            choice = i;
            break;
        }
    }

    if (choice == -1) {
        printf("Invalid unit entered.\n");
        return 1;
    }

    if (strcmp(units[choice].name, "celsius") == 0) {
        result = value * units[choice].factor;
    } else {
        result = value / units[choice].factor;
    }

    printf("%.2lf %s = %.2lf %s\n", value, unit_name, result, units[choice].name);

    return 0;
}