//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char *name;
    double (*func)(double);
} Unit;

double meter_to_feet(double value) {
    return value * 3.28084;
}

double feet_to_meter(double value) {
    return value / 3.28084;
}

double gram_to_ounce(double value) {
    return value * 0.035274;
}

double ounce_to_gram(double value) {
    return value / 0.035274;
}

double liter_to_gallon(double value) {
    return value * 0.264172;
}

double gallon_to_liter(double value) {
    return value / 0.264172;
}

double celsius_to_fahrenheit(double value) {
    return (value * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double value) {
    return (value - 32.0) * 5.0 / 9.0;
}

int main() {
    Unit units[] = {
        {"meter", meter_to_feet},
        {"feet", feet_to_meter},
        {"gram", gram_to_ounce},
        {"ounce", ounce_to_gram},
        {"liter", liter_to_gallon},
        {"gallon", gallon_to_liter},
        {"celsius", celsius_to_fahrenheit},
        {"fahrenheit", fahrenheit_to_celsius}
    };

    int num_units = sizeof(units) / sizeof(Unit);

    printf("Select a unit to convert from:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    int from_unit;
    scanf("%d", &from_unit);

    printf("Enter a value to convert:\n");
    double value;
    scanf("%lf", &value);

    printf("Select a unit to convert to:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    int to_unit;
    scanf("%d", &to_unit);

    double result = units[to_unit].func(value);

    printf("%.2lf %s = %.2lf %s\n", value, units[from_unit].name, result, units[to_unit].name);

    return 0;
}