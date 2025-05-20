#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    double value;
    char fromUnit, toUnit;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the from unit (m, cm, in): ");
    scanf(" %c", &fromUnit);

    printf("Enter the to unit (m, cm, in): ");
    scanf(" %c", &toUnit);

    switch(fromUnit) {
        case 'm':
            switch(toUnit) {
                case 'cm': value *= 100; break;
                case 'in': value *= 39.37; break;
                default: printf("Invalid conversion\n"); return 1;
            }
            break;
        case 'cm':
            switch(toUnit) {
                case 'm': value /= 100; break;
                case 'in': value /= 2.54; break;
                default: printf("Invalid conversion\n"); return 1;
            }
            break;
        case 'in':
            switch(toUnit) {
                case 'm': value /= 39.37; break;
                case 'cm': value *= 2.54; break;
                default: printf("Invalid conversion\n"); return 1;
            }
            break;
        default: printf("Invalid unit\n"); return 1;
    }

    printf("%.2f\n", value);
    return 0;
}
