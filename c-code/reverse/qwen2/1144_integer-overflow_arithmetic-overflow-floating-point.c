#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    double value;
    int from_unit, to_unit;

    printf("Enter value: ");
    scanf("%lf", &value);
    printf("Enter from unit (1=km, 2=m, 3=cm): ");
    scanf("%d", &from_unit);
    printf("Enter to unit (1=km, 2=m, 3=cm): ");
    scanf("%d", &to_unit);

    if (from_unit == 1) {
        if (to_unit == 1) {
            // km to km
        } else if (to_unit == 2) {
            value *= 1000; // km to m
        } else if (to_unit == 3) {
            value *= 100000; // km to cm
        }
    } else if (from_unit == 2) {
        if (to_unit == 1) {
            value /= 1000; // m to km
        } else if (to_unit == 2) {
            // m to m
        } else if (to_unit == 3) {
            value *= 100; // m to cm
        }
    } else if (from_unit == 3) {
        if (to_unit == 1) {
            value /= 100000; // cm to km
        } else if (to_unit == 2) {
            value /= 100; // cm to m
        } else if (to_unit == 3) {
            // cm to cm
        }
    }

    printf("Converted value: %f\n", value);

    return 0;
}
