//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 100

typedef struct {
    char *name;
    double factor;
} Unit;

typedef struct {
    char *input_unit;
    char *output_unit;
    double value;
} Conversion;

Unit units[MAX_UNITS] = {{"m", 1.0}, {"cm", 0.01}, {"mm", 0.001}, {"km", 1000.0}, {"in", 0.0254}, {"ft", 0.3048}, {"yd", 0.9144}, {"mi", 160934.4}, {"l", 1.0}, {"ml", 0.001}, {"fl oz", 0.0295735}, {"gal", 3.78541}};
Conversion conversions[MAX_CONVERSIONS];
int num_conversions = 0;

void add_conversion(char *input_unit, char *output_unit, double value) {
    if (num_conversions >= MAX_CONVERSIONS) {
        printf("Error: Maximum number of conversions reached.\n");
        exit(1);
    }
    conversions[num_conversions].input_unit = input_unit;
    conversions[num_conversions].output_unit = output_unit;
    conversions[num_conversions].value = value;
    num_conversions++;
}

int main() {
    char input_unit[20];
    char output_unit[20];
    double value;
    int i, j;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter the input unit: ");
    scanf("%s", input_unit);
    printf("Enter the output unit: ");
    scanf("%s", output_unit);
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    i = 0;
    while (i < MAX_UNITS && strcasecmp(units[i].name, input_unit)!= 0) {
        i++;
    }
    if (i == MAX_UNITS) {
        printf("Error: Invalid input unit.\n");
        exit(1);
    }

    j = 0;
    while (j < num_conversions && strcasecmp(conversions[j].input_unit, input_unit)!= 0) {
        j++;
    }
    if (j == num_conversions) {
        add_conversion(input_unit, output_unit, value * units[i].factor);
    }

    printf("Conversion factor: %lf\n", units[i].factor);
    printf("Result: %lf %s = %lf %s\n", value, input_unit, value * units[i].factor, output_unit);

    return 0;
}