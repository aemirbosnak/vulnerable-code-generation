//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT 10

typedef struct Unit {
    char name[20];
    int base_unit;
    double conversion_factor;
} Unit;

Unit units[] = {
    {"Gram", 1000, 1},
    {"Centigram", 1000, 0.001},
    {"Milligram", 1000, 0.00001},
    {"Ounces", 32, 0.00226},
    {"Pound", 32, 0.001638},
    {"Stone", 32, 0.000224},
    {"Liter", 1000, 1},
    {"Cubic Centimeter", 1000, 0.001},
    {"Cubic Meter", 1000, 0.000001},
    {"Quarts", 4, 0.001136}
};

void convert_units(double mass, Unit* from, Unit* to) {
    double factor = to->conversion_factor / from->conversion_factor;
    double converted_mass = mass * factor;
    printf("%f %s converted to %f %s is %f.\n", mass, from->name, to->name, converted_mass, converted_mass);
}

int main() {
    double mass;
    char from_unit[20];
    char to_unit[20];

    printf("Enter the mass: ");
    scanf("%lf", &mass);

    printf("Enter the unit of mass: ");
    scanf("%s", from_unit);

    printf("Enter the unit of mass you want to convert to: ");
    scanf("%s", to_unit);

    for (int i = 0; i < MAX_CONVERT; i++) {
        if (strcmp(units[i].name, from_unit) == 0 && strcmp(units[i].name, to_unit) == 0) {
            convert_units(mass, &units[i], &units[i]);
            break;
        }
    }

    return 0;
}