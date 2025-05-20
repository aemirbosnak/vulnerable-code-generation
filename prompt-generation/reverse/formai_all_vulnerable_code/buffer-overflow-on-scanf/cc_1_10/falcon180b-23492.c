//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: artistic
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

Unit units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"gram", 1.0},
    {"kilogram", 1000.0},
    {"liter", 1.0},
    {"milliliter", 0.001},
    {"second", 1.0},
    {"minute", 60.0},
    {"hour", 3600.0},
    {"day", 86400.0}
};

Conversion conversions[MAX_CONVERSIONS];
int num_conversions = 0;

void add_conversion(char *input_unit, char *output_unit, double value) {
    if (num_conversions >= MAX_CONVERSIONS) {
        printf("Error: Too many conversions.\n");
        return;
    }
    conversions[num_conversions].input_unit = input_unit;
    conversions[num_conversions].output_unit = output_unit;
    conversions[num_conversions].value = value;
    num_conversions++;
}

int main() {
    char input[100];
    char input_unit[20];
    char output_unit[20];
    double value;
    int i, j;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter a value and its unit to convert:\n");
    scanf("%s %s", input, input_unit);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            value = atof(input);
            break;
        }
    }

    if (i == MAX_UNITS) {
        printf("Error: Invalid input unit.\n");
        return 1;
    }

    printf("Enter the output unit:\n");
    scanf("%s", output_unit);

    for (j = 0; j < num_conversions; j++) {
        if (strcmp(output_unit, conversions[j].output_unit) == 0) {
            value *= conversions[j].value;
            printf("%s = %.2f %s\n", input, value, conversions[j].output_unit);
            return 0;
        }
    }

    printf("Error: Invalid output unit.\n");
    return 1;
}