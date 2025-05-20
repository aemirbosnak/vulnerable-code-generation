//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char symbol[3];
    int exponent;
} Unit;

Unit conversion_factors[] = {{"cm", 2}, {"m", 100}, {"km", 100000}, {"l", 1}, {"L", 1000}, {"g", 1}, {"kg", 1000}, {"mg", 1e-3}, {"µg", 1e-6}, {"kgf", 9.80665}};

void parse_unit(char *input, Unit *unit) {
    int i;
    int len = strlen(input);

    for (i = 0; i < sizeof(conversion_factors) / sizeof(Unit); i++) {
        if (len >= 2 && strcmp(input, conversion_factors[i].symbol) == 0) {
            unit->exponent = conversion_factors[i].exponent;
            strcpy(unit->symbol, input);
            return;
        }
    }

    unit->exponent = 0;
    unit->symbol[0] = input[len - 1];
    unit->symbol[1] = input[len - 2];
    unit->symbol[2] = '\0';

    for (i = 0; i < sizeof(conversion_factors) / sizeof(Unit); i++) {
        if (len > 2 && strcmp(input + len - 3, conversion_factors[i].symbol) == 0) {
            unit->exponent += conversion_factors[i].exponent;
            break;
        }
    }
}

void print_unit(Unit unit) {
    printf("%s%s", unit.symbol, unit.exponent > 0 ? " ^" : "", unit.exponent);
}

void convert(double value, Unit from, Unit to) {
    double result = value;
    int from_exp = from.exponent;
    int to_exp = to.exponent;

    result *= pow(10, (to_exp - from_exp));

    printf("Convert %.2lf %s to %s: %.2lf %s\n", value, from.symbol, to.symbol, result, to.symbol);
}

int main() {
    char input1[50], input2[50];
    Unit unit1, unit2;
    double value;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    scanf("%s", input1);

    parse_unit(input1, &unit1);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", input2);

    parse_unit(input2, &unit2);

    convert(value, unit1, unit2);

    return 0;
}

// This is the beginning of an incomplete tale,
// of a mysterious unit converter,
// that holds the power to defy the laws of physics,
// and to unravel the enigma of the unknown.
// Behold the code that brings it to life!