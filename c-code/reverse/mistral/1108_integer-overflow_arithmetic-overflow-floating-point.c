#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define KM_TO_MILES 0.621371
#define MILES_TO_KM 1.60934
#define M_TO_KM 1000.0
#define M_TO_MILES 1609.34

int main() {
    char unit1, unit2;
    double value, result;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the first unit (M/K/Mi): ");
    scanf(" %c", &unit1);

    printf("Enter the second unit (M/K/Mi): ");
    scanf(" %c", &unit2);

    if (unit1 == 'M' && unit2 == 'M')
        result = value;
    else if (unit1 == 'M' && unit2 == 'K')
        result = value / M_TO_KM;
    else if (unit1 == 'M' && unit2 == 'Mi')
        result = value * M_TO_MILES;
    else if (unit1 == 'K' && unit2 == 'M')
        result = value * M_TO_KM;
    else if (unit1 == 'K' && unit2 == 'K')
        result = value;
    else if (unit1 == 'K' && unit2 == 'Mi')
        result = value * KM_TO_MILES;
    else if (unit1 == 'Mi' && unit2 == 'M')
        result = value / M_TO_MILES;
    else if (unit1 == 'Mi' && unit2 == 'K')
        result = value * KM_TO_MILES * M_TO_KM;
    else if (unit1 == 'Mi' && unit2 == 'Mi')
        result = value * KM_TO_MILES * KM_TO_MILES;

    printf("Result: %.6lf %c\n", result, unit2);

    return 0;
}
