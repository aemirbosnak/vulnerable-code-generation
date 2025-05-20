#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    double factor;
} Unit;

Unit units[] = {
    {"Meter", 1.0},
    {"Kilometer", 1000.0},
    {"Mile", 1609.34},
    {"Yard", 0.9144},
    {"Foot", 0.3048},
    {"Inch", 0.0254}
};

int main() {
    char inputUnit[20], convertToUnit[20];
    double value, result;

    printf("Enter the length in a unit (Meter, Kilometer, Mile, Yard, Foot, Inch): ");
    scanf("%s", inputUnit);
    printf("Enter the value: ");
    scanf("%lf", &value);

    int i;
    for (i = 0; i < 6; i++) {
        if (strcmp(inputUnit, units[i].name) == 0) break;
    }

    if (i == 6) {
        printf("Invalid input. Please choose from the given units.\n");
        return 1;
    }

    printf("Convert to: ");
    scanf("%s", convertToUnit);

    for (i = 0; i < 6; i++) {
        if (strcmp(convertToUnit, units[i].name) == 0) break;
    }

    if (i == 6) {
        printf("Invalid input. Please choose from the given units.\n");
        return 1;
    }

    result = value * (units[i].factor / units[i].factor);
    printf("%.2lf %s is equal to %.2lf %s\n", value, inputUnit, result, convertToUnit);

    return 0;
}
