#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define M_TO_KM 0.001
#define KM_TO_M 1000.0
#define M_TO_MI 0.000621371
#define MI_TO_M 1609.34

double convert_length(double value, char from_unit, char to_unit) {
    switch(from_unit) {
        case 'm':
            if(to_unit == 'km') return value * M_TO_KM;
            else if(to_unit == 'mi') return value * M_TO_MI;
            break;
        case 'km':
            if(to_unit == 'm') return value * KM_TO_M;
            else if(to_unit == 'mi') return value * KM_TO_M * M_TO_MI;
            break;
        case 'mi':
            if(to_unit == 'm') return value * MI_TO_M;
            else if(to_unit == 'km') return value * MI_TO_M / KM_TO_M;
            break;
        default:
            fprintf(stderr, "Invalid unit\n");
            exit(1);
    }
    fprintf(stderr, "Conversion not supported\n");
    exit(1);
}

int main() {
    double value;
    char from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit (m/km/mi): ");
    scanf(" %c", &from_unit);

    printf("Enter the to unit (m/km/mi): ");
    scanf(" %c", &to_unit);

    double result = convert_length(value, from_unit, to_unit);
    printf("%.2f %c is %.2f %c\n", value, from_unit, result, to_unit);

    return 0;
}
