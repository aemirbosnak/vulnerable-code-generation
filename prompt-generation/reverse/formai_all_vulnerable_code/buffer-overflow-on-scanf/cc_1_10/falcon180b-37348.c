//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
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

int main() {
    char input[100];
    char *unit_name;
    double value, result;
    int i;

    printf("Enter a value and its unit (e.g. 5 meters): ");
    scanf("%s", input);

    // find the unit
    unit_name = strtok(input, " ");
    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            break;
        }
    }
    if (i == NUM_UNITS) {
        printf("Invalid unit.\n");
        return 1;
    }

    // convert the value
    value = atof(strtok(NULL, " "));
    result = value * units[i].factor;

    printf("%.2f %s = %.2f %s\n", value, unit_name, result, units[i].name);

    return 0;
}