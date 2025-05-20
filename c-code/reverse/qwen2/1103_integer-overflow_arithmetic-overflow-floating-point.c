#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define M_TO_KM 0.001
#define KM_TO_M 1000.0
#define M_TO_MI 0.000621371
#define MI_TO_M 1.60934

void convertLength(double value, char fromUnit, char toUnit) {
    double result;
    if (fromUnit == 'm' && toUnit == 'km') {
        result = value * M_TO_KM;
    } else if (fromUnit == 'km' && toUnit == 'm') {
        result = value * KM_TO_M;
    } else if (fromUnit == 'm' && toUnit == 'mi') {
        result = value * M_TO_MI;
    } else if (fromUnit == 'mi' && toUnit == 'm') {
        result = value * MI_TO_M;
    } else {
        printf("Unsupported conversion\n");
        return;
    }
    printf("%.2f %c is %.2f %c\n", value, fromUnit, result, toUnit);
}

int main() {
    double value;
    char fromUnit, toUnit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit (m/km/mi): ");
    scanf(" %c", &fromUnit);

    printf("Enter the to unit (m/km/mi): ");
    scanf(" %c", &toUnit);

    convertLength(value, fromUnit, toUnit);

    return 0;
}
