//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_UNITS 6

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"centimeters", 0.01},
    {"inches", 0.0254},
    {"feet", 0.3048},
    {"yards", 0.9144},
    {"miles", 160934.4}
};

int main() {
    char input[100];
    int choice;
    double value, result;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter the unit you want to convert from: ");
    scanf("%s", input);

    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", input);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            choice = i;
            break;
        }
    }

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            result = value * units[choice].factor;
            printf("%.2lf %s = %.2lf %s\n", value, input, result, units[i].name);
            break;
        }
    }

    return 0;
}