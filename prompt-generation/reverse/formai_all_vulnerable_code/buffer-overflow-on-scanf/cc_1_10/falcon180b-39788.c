//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: complete
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
    {"inches", 0.0254},
    {"feet", 0.3048},
    {"yards", 0.9144},
    {"miles", 160934.4},
    {"kilograms", 1.0},
    {"grams", 0.001},
    {"pounds", 0.453592}
};

int main() {
    char input[100];
    char output[100];
    char unit_name[100];
    double value, result;
    int i, choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the value you want to convert: ");
    scanf("%s", input);

    printf("Please enter the unit of the value: ");
    scanf("%s", unit_name);

    printf("Please enter the unit you want to convert to: ");
    scanf("%s", output);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            value = atof(input);
            break;
        }
    }

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(output, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%s %s is equal to %s %s.\n", input, unit_name, output, units[i].name);
            break;
        }
    }

    return 0;
}