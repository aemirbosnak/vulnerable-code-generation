//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define NUM_UNITS 7
#define UNIT_NAMES "meters", "centimeters", "millimeters", "kilometers", "inches", "feet", "yards"

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"centimeters", 0.01},
    {"millimeters", 0.001},
    {"kilometers", 1000.0},
    {"inches", 0.0254},
    {"feet", 0.3048},
    {"yards", 0.9144}
};

int main() {
    int choice;
    double value, result;
    char unit_name[20];

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the unit you want to convert from (e.g. meters): ");
    scanf("%s", unit_name);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            choice = i;
            break;
        }
    }

    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Please enter the unit you want to convert to: ");
    scanf("%s", unit_name);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%lf %s = %lf %s\n", value, unit_name, result, units[i].name);
            break;
        }
    }

    return 0;
}