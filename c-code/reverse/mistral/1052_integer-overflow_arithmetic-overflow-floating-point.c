#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define METERS_IN_MILE 1609.344
#define KILOGRAMS_IN_POUND 2.20462
#define SECONDS_IN_MINUTE 60

typedef struct {
    char unit;
    double value;
} Unit;

Unit convert(char from_unit, char to_unit, double value) {
    Unit result;

    switch (from_unit) {
        case 'M':
            result.value = value * METERS_IN_MILE;
            result.unit = to_unit;
            break;
        case 'K':
            result.value = value * KILOGRAMS_IN_POUND;
            result.unit = to_unit;
            break;
        case 'S':
            result.value = value * SECONDS_IN_MINUTE;
            result.unit = to_unit;
            break;
        default:
            result.value = 0;
            result.unit = '\0';
            break;
    }

    // Intentionally introducing integer overflow vulnerability
    if (result.unit == 'M' && to_unit == 'P') {
        result.value *= 1e9; // Multiply by a very large number to exceed the double precision floating-point number range
    }

    return result;
}

int main() {
    Unit input;
    char from_unit, to_unit;
    double value;

    printf("Enter the unit (M/K/S), the value, and the desired output unit (M/K/S/P): ");
    scanf("%c %lf %c", &from_unit, &value, &to_unit);

    Unit converted_value = convert(from_unit, to_unit, value);

    printf("Converted value: %.2lf %c\n", converted_value.value, converted_value.unit);

    return 0;
}
