#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char fromUnit, toUnit;
    double value;

    printf("Enter the value: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from (kg, g, lb, oz, ml, L, km, mi): ");
    scanf(" %c", &fromUnit);

    printf("Enter the unit to convert to (kg, g, lb, oz, ml, L, km, mi): ");
    scanf(" %c", &toUnit);

    switch(fromUnit) {
        case 'k':
            switch(toUnit) {
                case 'g': value *= 1000; break;
                case 'l': value /= 1000; break;
                case 'm': value /= 1.60934; break;
                default: printf("Invalid conversion\n"); return 1;
            }
            break;
        case 'g':
            switch(toUnit) {
                case 'k': value /= 1000; break;
                case 'l': value /= 1000000; break;
                case 'm': value /= 160934; break;
                default: printf("Invalid conversion\n"); return 1;
            }
            break;
        case 'l':
            switch(toUnit) {
                case 'k': value *= 0.001; break;
                case 'g': value *= 1000000; break;
                case 'm': value /= 160934; break;
                default: printf("Invalid conversion\n"); return 1;
            }
            break;
        case 'm':
            switch(toUnit) {
                case 'k': value *= 1.60934; break;
                case 'g': value *= 160934000; break;
                case 'l': value *= 160934; break;
                default: printf("Invalid conversion\n"); return 1;
            }
            break;
        default: printf("Invalid unit\n"); return 1;
    }

    printf("%.2f %c is %.2f %c\n", value, fromUnit, value, toUnit);

    return 0;
}
