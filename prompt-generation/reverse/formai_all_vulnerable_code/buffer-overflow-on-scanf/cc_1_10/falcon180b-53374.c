//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_VALUE_LENGTH 10
#define MAX_UNIT_LENGTH 10

struct Unit {
    char name[MAX_VALUE_LENGTH];
    double factor;
};

struct Value {
    char unit[MAX_UNIT_LENGTH];
    double value;
};

struct Unit Celsius = {"Celsius", 1.0};
struct Unit Fahrenheit = {"Fahrenheit", 1.8};
struct Unit Kelvin = {"Kelvin", 1.0};

struct Unit* units[] = {&Celsius, &Fahrenheit, &Kelvin};

int main() {
    int num_units = sizeof(units) / sizeof(units[0]);
    struct Unit* selected_unit = &Celsius;
    char input[MAX_VALUE_LENGTH + MAX_UNIT_LENGTH + 1];
    char* value_str;
    char* unit_str;
    double value;
    double result;

    printf("Select a unit of measurement:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i + 1, units[i]->name);
    }

    scanf("%d", &selected_unit - units);

    while (1) {
        printf("Enter a temperature value followed by its unit (e.g. 25C): ");
        scanf("%[^CELSIUSFALCONKELVIN]", input);

        value_str = strtok(input, " ");
        unit_str = strtok(NULL, " ");

        if (value_str == NULL || unit_str == NULL) {
            printf("Invalid input. Please enter a temperature value followed by its unit.\n");
            continue;
        }

        value = atof(value_str);

        if (strcmp(unit_str, "C") == 0) {
            result = value * selected_unit->factor;
        } else if (strcmp(unit_str, "F") == 0) {
            result = (value * selected_unit->factor) + 32;
        } else if (strcmp(unit_str, "K") == 0) {
            result = value + 273.15;
        } else {
            printf("Invalid unit. Please enter C, F, or K.\n");
            continue;
        }

        printf("%.2f%s = %.2f%s\n", value, unit_str, result, selected_unit->name);
    }

    return 0;
}