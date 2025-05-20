//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 7

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
    {"celsius", 1.0}
};

int main() {
    char input[100];
    char *unit_name;
    double value, result;
    int i;

    printf("Enter a value and a unit to convert from:\n");
    scanf("%s %s", input, input+strcspn(input, " "));

    unit_name = strtok(input, " ");
    value = atof(unit_name);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            break;
        }
    }

    if (i == NUM_UNITS) {
        printf("Invalid unit.\n");
        return 1;
    }

    printf("Enter a unit to convert to:\n");
    scanf("%s", input);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%f %s = %f %s\n", value, unit_name, result, input);
            return 0;
        }
    }

    printf("Invalid unit.\n");
    return 1;
}