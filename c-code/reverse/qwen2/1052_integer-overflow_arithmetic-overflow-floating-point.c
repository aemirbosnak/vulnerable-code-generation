#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    float value;
    char from_unit, to_unit;

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    printf("Enter the unit to convert from (m/k/s): ");
    scanf(" %c", &from_unit);

    printf("Enter the unit to convert to (m/k/s): ");
    scanf(" %c", &to_unit);

    if ((from_unit == 'm' && to_unit == 'k') || (from_unit == 'k' && to_unit == 'm')) {
        value = value * 1.60934; // miles per kilometer
    } else if ((from_unit == 'm' && to_unit == 's') || (from_unit == 's' && to_unit == 'm')) {
        value = value * 60; // minutes per second
    } else if ((from_unit == 'k' && to_unit == 's') || (from_unit == 's' && to_unit == 'k')) {
        value = value * 2.20462; // pounds per kilogram
    }

    printf("%.2f\n", value);

    return 0;
}
