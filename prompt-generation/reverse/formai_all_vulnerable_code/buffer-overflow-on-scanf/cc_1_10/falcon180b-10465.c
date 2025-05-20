//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double (*convert)(double);
} Unit;

double meter_to_feet(double value) {
    return value * 3.28084;
}

double feet_to_meter(double value) {
    return value / 3.28084;
}

double kilogram_to_pound(double value) {
    return value * 2.20462;
}

double pound_to_kilogram(double value) {
    return value / 2.20462;
}

double liter_to_gallon(double value) {
    return value * 0.264172;
}

double gallon_to_liter(double value) {
    return value / 0.264172;
}

double celsius_to_fahrenheit(double value) {
    return (value * 9 / 5) + 32;
}

double fahrenheit_to_celsius(double value) {
    return (value - 32) * 5 / 9;
}

void print_units(Unit *units, int num_units) {
    for (int i = 0; i < num_units; i++) {
        printf("%s\n", units[i].name);
    }
}

int main() {
    Unit units[] = {{"Meter", meter_to_feet}, {"Feet", feet_to_meter}, {"Kilogram", kilogram_to_pound}, {"Pound", pound_to_kilogram}, {"Liter", liter_to_gallon}, {"Gallon", gallon_to_liter}, {"Celsius", celsius_to_fahrenheit}, {"Fahrenheit", fahrenheit_to_celsius}};
    int num_units = sizeof(units) / sizeof(units[0]);

    printf("Enter the unit you want to convert from:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    int choice;
    scanf("%d", &choice);

    printf("Enter the value you want to convert:\n");
    double value;
    scanf("%lf", &value);

    printf("Enter the unit you want to convert to:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    int to_choice;
    scanf("%d", &to_choice);

    double result = units[to_choice - 1].convert(value);

    printf("The result is: %.2lf %s\n", result, units[to_choice - 1].name);

    return 0;
}