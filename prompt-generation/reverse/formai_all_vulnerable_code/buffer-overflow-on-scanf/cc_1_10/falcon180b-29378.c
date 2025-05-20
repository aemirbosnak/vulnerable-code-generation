//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define UNITS 12

struct unit {
    char name[10];
    double value;
};

struct unit units[UNITS] = {
    {"meters", 1.0},
    {"centimeters", 0.01},
    {"millimeters", 0.001},
    {"kilometers", 1000.0},
    {"inches", 0.0254},
    {"feet", 0.3048},
    {"yards", 0.9144},
    {"miles", 160934.4},
    {"pounds", 0.453592},
    {"ounces", 0.0283495},
    {"gallons", 3.78541},
    {"liters", 0.264172}
};

int main() {
    char input[50];
    char unit1[20], unit2[20];
    double value, result;
    int i, j;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf("%s", input);

    for (i = 0; i < UNITS; i++) {
        if (strcmp(input, units[i].name) == 0) {
            break;
        }
    }

    printf("Enter the unit to convert to: ");
    scanf("%s", input);

    for (j = 0; j < UNITS; j++) {
        if (strcmp(input, units[j].name) == 0) {
            break;
        }
    }

    if (i == j) {
        printf("Cannot convert from and to the same unit.\n");
        return 0;
    }

    result = value * units[i].value / units[j].value;

    printf("Result: %.2lf %s = %.2lf %s\n", value, units[i].name, result, units[j].name);

    return 0;
}