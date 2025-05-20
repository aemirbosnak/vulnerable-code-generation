//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    double conversion_factor;
} Unit;

Unit length_units[] = {{"Meter", 1.0}, {"Kilometer", 1000.0}, {"Centimeter", 0.01}, {"Millimeter", 0.001}, {"Foot", 0.3048}, {"Yard", 0.9144}, {"Mile", 1609.34}, {"Nautical Mile", 1852.0}};
Unit mass_units[] = {{"Gram", 0.001}, {"Kilogram", 1000.0}, {"Milligram", 0.000001}, {"Pound", 0.453592}, {"Ounce", 0.035274}};
Unit temperature_units[] = {{"Celsius", 1.0}, {"Fahrenheit", 1.8}};

void print_usage() {
    printf("Usage: unit_converter <source_unit> <target_unit> <value>\n");
    printf("Example: unit_converter \"Kilometer\" \"Meter\" 5.0\n");
    printf("Available units:\n");

    int i, j;
    for (i = 0; i < 3; i++) {
        printf("%s units:\n", i == 0 ? "Length" : i == 1 ? "Mass" : "Temperature");
        for (j = 0; j < sizeof(length_units) / sizeof(Unit); j++) {
            printf("%s: %f\n", length_units[j].name, length_units[j].conversion_factor);
        }
        printf("\n");
    }
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        print_usage();
    }

    int i, j, k;
    Unit source_unit, target_unit, value;
    double result;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < sizeof(length_units) / sizeof(Unit); j++) {
            if (strcmp(argv[1], length_units[j].name) == 0) {
                source_unit = length_units[j];
                break;
            }
        }

        for (k = 0; k < sizeof(length_units) / sizeof(Unit); k++) {
            if (strcmp(argv[2], length_units[k].name) == 0) {
                target_unit = length_units[k];
                break;
            }
        }

        if (i == 0) {
            for (j = 0; j < sizeof(mass_units) / sizeof(Unit); j++) {
                if (strcmp(argv[1], mass_units[j].name) == 0) {
                    source_unit = mass_units[j];
                    i = 1;
                }
            }

            for (j = 0; j < sizeof(mass_units) / sizeof(Unit); j++) {
                if (strcmp(argv[2], mass_units[j].name) == 0) {
                    target_unit = mass_units[j];
                    i = 2;
                }
            }

            if (i != 1 && i != 2) {
                for (j = 0; j < sizeof(temperature_units) / sizeof(Unit); j++) {
                    if (strcmp(argv[1], temperature_units[j].name) == 0) {
                        source_unit = temperature_units[j];
                        i = 3;
                    }
                }

                for (j = 0; j < sizeof(temperature_units) / sizeof(Unit); j++) {
                    if (strcmp(argv[2], temperature_units[j].name) == 0) {
                        target_unit = temperature_units[j];
                        i = 3;
                    }
                }
            }
        }
    }

    value.conversion_factor = atof(argv[3]);

    if (source_unit.conversion_factor == 0 || target_unit.conversion_factor == 0) {
        print_usage();
    }

    result = value.conversion_factor * (target_unit.conversion_factor / source_unit.conversion_factor);

    printf("Result: %f %s\n", result, target_unit.name);

    return 0;
}