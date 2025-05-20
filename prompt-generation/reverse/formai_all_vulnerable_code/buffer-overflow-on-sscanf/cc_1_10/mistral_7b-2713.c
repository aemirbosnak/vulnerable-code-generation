//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 100
#define NUM_UNITS 10

typedef struct {
    char name[20];
    float conversion_factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"Mile", 0.000621371},
    {"Kilometer", 1.60934},
    {"Foot", 0.3048},
    {"Meter", 3.28084},
    {"Yard", 0.9144},
    {"Gallon (US)", 3.78541},
    {"Liter", 0.264172},
    {"Pound", 0.453592},
    {"Kilogram", 2.20462},
    {"Ounce", 0.035274}
};

void print_menu() {
    int i;
    printf("Unit Converter\n");
    printf("===================\n");
    printf("Available Units:\n");
    for (i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
    printf("\nEnter the numbers of the units you want to convert from and to, separated by a space:\n");
}

void convert(Unit from_unit, Unit to_unit, float value) {
    float result;
    result = value * (to_unit.conversion_factor / from_unit.conversion_factor);
    printf("%.2f %s is equal to %.2f %s\n", value, from_unit.name, result, to_unit.name);
}

int main() {
    char line[MAX_LINE_LENGTH];
    int i, j, from_index, to_index;
    float value;

    print_menu();

    fgets(line, MAX_LINE_LENGTH, stdin);
    sscanf(line, "%d %d %f", &i, &j, &value);

    from_index = i - 1;
    to_index = j - 1;

    if (from_index < 0 || from_index >= NUM_UNITS || to_index < 0 || to_index >= NUM_UNITS) {
        printf("Invalid units selected.\n");
        return 1;
    }

    convert(units[from_index], units[to_index], value);

    return 0;
}