//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_UNITS 10

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
    {"yards", 0.9144},
    {"miles", 160934.4},
    {"pounds", 0.453592},
    {"kilograms", 2.20462}
};

int main() {
    char input[100];
    char unit[20];
    double value, result;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", unit);

    int found = 0;
    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit, units[i].name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Invalid unit.\n");
        return 1;
    }

    printf("Enter the unit to convert to: ");
    scanf("%s", unit);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%.2lf %s = %.2lf %s\n", value, units[i].name, result, unit);
            return 0;
        }
    }

    printf("Invalid unit.\n");
    return 1;
}