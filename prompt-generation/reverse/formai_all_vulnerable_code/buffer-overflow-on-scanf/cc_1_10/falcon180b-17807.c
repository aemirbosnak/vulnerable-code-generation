//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

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
    char output[100];
    char *unit_str;
    double value, result;
    int i, choice;

    printf("Enter a value and its unit (e.g. 3.5 meters): ");
    scanf("%s %s", input, output);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(output, units[i].name) == 0) {
            break;
        }
    }

    if (i == NUM_UNITS) {
        printf("Invalid unit.\n");
        return 1;
    }

    value = atof(input);
    result = value * units[i].factor;

    printf("%.2f %s = ", value, output);

    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(units[i].name, "meters") == 0) {
            continue;
        }
        unit_str = units[i].name;
        if (i == NUM_UNITS - 1) {
            printf("%s\n", unit_str);
        } else {
            printf("%s, ", unit_str);
        }
    }

    return 0;
}