//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[30];
    float conversionFactor;
} Unit;

Unit units[] = {
    {"Megabyte", 0.001},
    {"Gigabyte", 0.001E6},
    {"Terabyte", 0.001E12},
    {"Kilometer", 0.001},
    {"Mile", 1609.34},
    {"Lightyear", 9.461E12},
    {"Pound", 0.453592},
    {"Kilogram", 2.20462},
    {"Ounce", 0.03527},
    {"Stone", 14.0},
    {"Yard", 0.9144},
    {"Foot", 0.3048},
    {"Inch", 0.0254},
    {"Degree Celsius", 1.0},
    {"Degree Fahrenheit", 1.8},
    {"Degree Kelvin", 1.0},
    {"Radian", 57.2958},
    {"Degree", 0.0174532925199433}
};

void convert(Unit from, Unit to, float value) {
    printf("%.2f %s is equal to %.2f %s\n", value, from.name, value * (to.conversionFactor / from.conversionFactor), to.name);
}

int main() {
    char inputUnit1[30], inputUnit2[30], valueStr[20];
    Unit from, to;
    float value;

    printf("Welcome to the Quantum Unit Converter!\n");
    printf("Type the name of the unit you want to convert FROM: ");
    scanf("%s", inputUnit1);

    for (int i = 0; i < 14; i++) {
        if (strcmp(inputUnit1, units[i].name) == 0) {
            from = units[i];
            break;
        }
    }

    printf("Type the name of the unit you want to convert TO: ");
    scanf("%s", inputUnit2);

    for (int i = 0; i < 14; i++) {
        if (strcmp(inputUnit2, units[i].name) == 0) {
            to = units[i];
            break;
        }
    }

    if (from.name == NULL || to.name == NULL) {
        printf("Invalid units! Exiting...\n");
        return 1;
    }

    printf("Type the value you want to convert: ");
    scanf("%s", valueStr);
    value = atof(valueStr);

    convert(from, to, value);

    return 0;
}