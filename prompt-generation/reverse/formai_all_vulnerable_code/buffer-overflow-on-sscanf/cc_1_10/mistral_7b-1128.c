//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    double conversion_factor;
} Unit;

Unit length_units[] = {{"Inch", 0.0254}, {"Foot", 0.3048}, {"Yard", 0.9144}, {"Mile", 1609.34}, {"Centimeter", 0.01}, {"Meter", 1.0}, {"Kilometer", 1000.0}, {"Astronomical Unit", 149597870700.0}, {"Light Year", 9.461e+15}};

Unit weight_units[] = {{"Carat", 0.0002}, {"Gram", 0.001}, {"Kilogram", 1.0}, {"Ounce", 0.035274}, {"Pound", 0.453592}, {"Stone", 6.35029}};

Unit temperature_units[] = {{"Fahrenheit", 32.0}, {"Celsius", 0.0}, {"Kelvin", 273.15}};

void print_usage() {
    printf("Usage: converter <source_unit> <target_unit> <value>\n");
    printf("Example: converter inch meter 5.5\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    char source_unit[30], target_unit[30];
    double value, result;
    sscanf(argv[1], "%[^ ]", source_unit);
    sscanf(argv[2], "%[^ ]", target_unit);
    sscanf(argv[3], "%lf", &value);

    int source_unit_index = -1, target_unit_index = -1;

    for (int i = 0; i < sizeof(length_units) / sizeof(Unit); i++) {
        if (strcmp(source_unit, length_units[i].name) == 0) {
            source_unit_index = i;
            break;
        }
    }

    for (int i = 0; i < sizeof(length_units) / sizeof(Unit); i++) {
        if (strcmp(target_unit, length_units[i].name) == 0) {
            target_unit_index = i;
            break;
        }
    }

    if (source_unit_index == -1 || target_unit_index == -1) {
        printf("Invalid units specified.\n");
        return 1;
    }

    double source_unit_factor = length_units[source_unit_index].conversion_factor;
    double target_unit_factor = length_units[target_unit_index].conversion_factor;

    result = value * (source_unit_factor / target_unit_factor);

    printf("%.2lf %s is equal to %.2lf %s\n", value, source_unit, result, target_unit);

    return 0;
}