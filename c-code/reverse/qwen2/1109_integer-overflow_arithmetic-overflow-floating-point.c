#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define M_TO_KM 0.001
#define KM_TO_M 1000.0
#define M_TO_MI 0.000621371
#define MI_TO_M 1609.34

double convert_length(double value, char from_unit, char to_unit) {
    switch (from_unit) {
        case 'm':
            if (to_unit == 'km') return value * M_TO_KM;
            if (to_unit == 'mi') return value * M_TO_MI;
            break;
        case 'km':
            if (to_unit == 'm') return value * KM_TO_M;
            if (to_unit == 'mi') return value * KM_TO_M * M_TO_MI;
            break;
        case 'mi':
            if (to_unit == 'm') return value * MI_TO_M;
            if (to_unit == 'km') return value * MI_TO_M / KM_TO_M;
            break;
    }
    return -1; // Error: Invalid conversion
}

int main() {
    double value;
    char from_unit, to_unit;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the from unit (m, km, mi): ");
    scanf(" %c", &from_unit);

    printf("Enter the to unit (m, km, mi): ");
    scanf(" %c", &to_unit);

    double result = convert_length(value, from_unit, to_unit);
    if (result != -1) {
        printf("%.2f %c is %.2f %c\n", value, from_unit, result, to_unit);
    } else {
        printf("Invalid conversion.\n");
    }

    return 0;
}
