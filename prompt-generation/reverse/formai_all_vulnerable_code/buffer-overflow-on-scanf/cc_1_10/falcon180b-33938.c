//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"feet", 3.28084},
    {"inches", 39.3701},
    {"kilograms", 1.0},
    {"pounds", 2.20462},
    {"celsius", 1.0},
    {"fahrenheit", 1.8}
};

int main() {
    char input[100];
    char from_unit[20], to_unit[20];
    double value, result;
    int i, j;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    i = 0;
    while (i < NUM_UNITS && strcmp(units[i].name, from_unit)!= 0) {
        i++;
    }
    if (i == NUM_UNITS) {
        printf("Invalid unit: %s\n", from_unit);
        return 1;
    }

    j = 0;
    while (j < NUM_UNITS && strcmp(units[j].name, to_unit)!= 0) {
        j++;
    }
    if (j == NUM_UNITS) {
        printf("Invalid unit: %s\n", to_unit);
        return 1;
    }

    result = value * units[i].factor / units[j].factor;

    printf("%lf %s is %lf %s\n", value, from_unit, result, to_unit);

    return 0;
}