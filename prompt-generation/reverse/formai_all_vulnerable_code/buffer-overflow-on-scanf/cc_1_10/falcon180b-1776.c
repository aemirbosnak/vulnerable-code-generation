//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONVERSIONS 1000
#define MAX_CONVERTERS 1000

typedef struct {
    char *name;
    double (*convert)(double);
} Converter;

Converter converters[MAX_CONVERTERS];
int num_converters;

double convert_length(double value) {
    return value;
}

double convert_volume(double value) {
    return value;
}

double convert_weight(double value) {
    return value;
}

double convert_temperature(double value) {
    return value;
}

void add_converter(char *name, double (*convert)(double)) {
    if (num_converters >= MAX_CONVERTERS) {
        printf("Error: Maximum number of converters reached.\n");
        exit(EXIT_FAILURE);
    }
    converters[num_converters].name = strdup(name);
    converters[num_converters].convert = convert;
    num_converters++;
}

bool is_converter(char *name) {
    for (int i = 0; i < num_converters; i++) {
        if (strcmp(name, converters[i].name) == 0) {
            return true;
        }
    }
    return false;
}

double convert_value(char *unit, double value) {
    if (isdigit(unit[0])) {
        printf("Error: Unit must start with a letter.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_converters; i++) {
        if (strcmp(unit, converters[i].name) == 0) {
            return converters[i].convert(value);
        }
    }
    printf("Error: Unknown unit.\n");
    exit(EXIT_FAILURE);
}

int main() {
    add_converter("meters", convert_length);
    add_converter("centimeters", convert_length);
    add_converter("kilograms", convert_weight);
    add_converter("grams", convert_weight);
    add_converter("liters", convert_volume);
    add_converter("milliliters", convert_volume);
    add_converter("celsius", convert_temperature);
    add_converter("fahrenheit", convert_temperature);

    char unit[MAX_CONVERSIONS];
    double value;

    printf("Enter a unit and value to convert:\n");
    scanf("%s %lf", unit, &value);

    double result = convert_value(unit, value);

    printf("Result: %lf\n", result);

    return 0;
}