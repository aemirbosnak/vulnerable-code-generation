//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"feet", 0.3048},
    {"inches", 0.0254},
    {"kilograms", 1.0},
    {"pounds", 2.20462},
    {"celsius", 1.0},
    {"fahrenheit", 5.0/9.0}
};

int main() {
    int choice;
    double value, result;
    char unit_from[50], unit_to[50];

    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit_from);
    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit_to);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_from, units[i].name) == 0) {
            choice = i;
            break;
        }
    }

    if (choice == -1) {
        printf("Invalid unit of measurement.\n");
        return 1;
    }

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_to, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%.2lf %s = %.2lf %s\n", value, unit_from, result, units[i].name);
            return 0;
        }
    }

    printf("Invalid unit of measurement.\n");
    return 1;
}