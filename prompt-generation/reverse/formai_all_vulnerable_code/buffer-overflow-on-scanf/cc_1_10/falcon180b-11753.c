//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>

#define NUM_UNITS 7

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
    {"miles", 160934.4},
    {"kilometers", 1000.0}
};

int main() {
    int unitIndex;
    double value, result;
    char input[50];

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (e.g. meters): ");
    scanf("%s", input);

    for (unitIndex = 0; unitIndex < NUM_UNITS; ++unitIndex) {
        if (strcmp(input, units[unitIndex].name) == 0) {
            break;
        }
    }

    if (unitIndex == NUM_UNITS) {
        printf("Invalid unit.\n");
        return 1;
    }

    printf("Enter the unit to convert to (e.g. inches): ");
    scanf("%s", input);

    for (unitIndex = 0; unitIndex < NUM_UNITS; ++unitIndex) {
        if (strcmp(input, units[unitIndex].name) == 0) {
            break;
        }
    }

    if (unitIndex == NUM_UNITS) {
        printf("Invalid unit.\n");
        return 1;
    }

    result = value * units[unitIndex].factor;

    printf("%.2lf %s = %.2lf %s\n", value, units[0].name, result, units[unitIndex].name);

    return 0;
}