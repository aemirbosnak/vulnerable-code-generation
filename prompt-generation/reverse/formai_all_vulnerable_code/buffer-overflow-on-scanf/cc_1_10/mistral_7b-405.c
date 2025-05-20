//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char unit[10];
    double conversion_factor;
} UnitConverter;

UnitConverter converters[] = {
    {"miles", 1609.34},
    {"kilometers", 0.621371},
    {"pounds", 0.453592},
    {"kilograms", 2.20462},
    {"degrees_Fahrenheit", 1.8},
    {"degrees_Celsius", 1},
    {"liters", 0.035274},
    {"gallons", 3.78541},
    {"volts", 1},
    {"amps", 1},
    {"watts", 1},
    {"joules", 1}
};

int find_converter(UnitConverter converters[], char *unit, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(unit, converters[i].unit) == 0) {
            return i;
        }
    }
    return -1;
}

void convert(UnitConverter converters[], char *from_unit, char *to_unit, double value, int size) {
    int index1 = find_converter(converters, from_unit, size);
    int index2 = find_converter(converters, to_unit, size);

    if (index1 != -1 && index2 != -1) {
        double conversion_factor1 = converters[index1].conversion_factor;
        double conversion_factor2 = converters[index2].conversion_factor;
        double result = value * conversion_factor1 * conversion_factor2;
        printf("%.2lf %s is equal to %.2lf %s\n", value, from_unit, result, to_unit);
    } else {
        printf("Error: Invalid units.\n");
    }
}

int main() {
    UnitConverter converters[] = {{"miles", 1609.34}, {"kilometers", 0.621371}, {"pounds", 0.453592}, {"kilograms", 2.20462}, {"degrees_Fahrenheit", 1.8}, {"degrees_Celsius", 1}, {"liters", 0.035274}, {"gallons", 3.78541}, {"volts", 1}, {"amps", 1}, {"watts", 1}, {"joules", 1}};

    char input1[15], input2[15];
    double value;

    printf("Welcome, Cyberpunk! Enter the value, unit1 and unit2 for conversion: \n");
    scanf("%s%s%lf", input1, input2, &value);

    convert(converters, input1, input2, value, sizeof(converters) / sizeof(UnitConverter));

    return 0;
}