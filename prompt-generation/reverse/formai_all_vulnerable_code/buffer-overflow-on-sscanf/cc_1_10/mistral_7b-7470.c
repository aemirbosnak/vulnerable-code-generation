//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char unit[10];
    float factor;
} UnitConversion;

bool is_valid_unit(char *unit, UnitConversion units[]) {
    for (int i = 0; i < 13; i++) {
        if (strcmp(units[i].unit, unit) == 0) {
            return true;
        }
    }
    return false;
}

float convert(float value, char from_unit[], UnitConversion units[]) {
    for (int i = 0; i < 13; i++) {
        if (strcmp(from_unit, units[i].unit) == 0) {
            value *= units[i].factor;
            break;
        }
    }
    return value;
}

void print_usage() {
    printf("Usage: %s [value] [from_unit] [to_unit]\n", __FILE__);
    printf("Example: %s 5.5m Celsius Fahrenheit\n", __FILE__);
}

int main(int argc, char **argv) {
    UnitConversion units[] = {
        {"Meter", 1.0},
        {"Kilometer", 1000.0},
        {"Centimeter", 0.01},
        {"Millimeter", 0.001},
        {"Foot", 0.3048},
        {"Yard", 0.9144},
        {"Mile", 1609.34},
        {"Gallon", 3.7854},
        {"Liter", 0.001},
        {"Ounce", 0.02957},
        {"Pound", 0.4536},
        {"Celsius", 1.0},
        {"Fahrenheit", 0.018}
    };

    if (argc < 4) {
        print_usage();
        return 1;
    }

    float value;
    char from_unit[10], to_unit[10];

    sscanf(argv[1], "%f", &value);
    strcpy(from_unit, argv[2]);
    strcpy(to_unit, argv[3]);

    if (!is_valid_unit(argv[2], units) || !is_valid_unit(argv[3], units)) {
        printf("Invalid unit provided.\n");
        print_usage();
        return 1;
    }

    float result = convert(value, from_unit, units);
    printf("%.2f %s is equal to %.2f %s\n", value, from_unit, result, to_unit);

    return 0;
}