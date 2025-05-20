#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define CM_TO_M 0.01
#define M_TO_KM 0.001
#define IN_TO_CM 2.54
#define FT_TO_IN 12
#define MI_TO_KM 1.60934

double convert(double value, char from_unit, char to_unit) {
    switch (from_unit) {
        case 'C': return value * CM_TO_M;
        case 'M': return value * M_TO_KM;
        case 'K': return value;
        case 'I': return value * IN_TO_CM / CM_TO_M;
        case 'F': return value * FT_TO_IN * IN_TO_CM / CM_TO_M;
        case 'X': return value * MI_TO_KM;
        default: return -1; // Error
    }
}

int main() {
    double value;
    char from_unit, to_unit;

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (C, M, K, I, F, X): ");
    scanf(" %c", &from_unit);

    printf("Enter the unit to convert to (C, M, K, I, F, X): ");
    scanf(" %c", &to_unit);

    double result = convert(value, from_unit, to_unit);
    if (result == -1) {
        printf("Invalid unit.\n");
    } else {
        printf("%.2f %c is %.2f %c\n", value, from_unit, result, to_unit);
    }

    return 0;
}
