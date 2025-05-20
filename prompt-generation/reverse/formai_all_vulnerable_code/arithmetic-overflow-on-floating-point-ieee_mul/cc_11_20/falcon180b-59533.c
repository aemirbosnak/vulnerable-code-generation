//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char unit_from, unit_to;
    float value, result;

    printf("Unit Conversion Calculator\n");
    printf("Enter the unit you want to convert from: ");
    scanf("%c", &unit_from);
    printf("Enter the unit you want to convert to: ");
    scanf("%c", &unit_to);

    printf("Enter the value to be converted: ");
    scanf("%f", &value);

    switch(unit_from) {
        case'm':
        case 'M':
            switch(unit_to) {
                case 'k':
                case 'K':
                    result = value * 1000;
                    printf("%.2f %c = %.2f %c\n", value, unit_from, result, unit_to);
                    break;
                case 'c':
                case 'C':
                    result = value * 0.01;
                    printf("%.2f %c = %.2f %c\n", value, unit_from, result, unit_to);
                    break;
                default:
                    printf("Invalid conversion\n");
                    break;
            }
            break;
        case 'k':
        case 'K':
            switch(unit_to) {
                case'm':
                case 'M':
                    result = value / 1000;
                    printf("%.2f %c = %.2f %c\n", value, unit_from, result, unit_to);
                    break;
                case 'c':
                case 'C':
                    result = value * 100;
                    printf("%.2f %c = %.2f %c\n", value, unit_from, result, unit_to);
                    break;
                default:
                    printf("Invalid conversion\n");
                    break;
            }
            break;
        case 'c':
        case 'C':
            switch(unit_to) {
                case'm':
                case 'M':
                    result = value / 0.01;
                    printf("%.2f %c = %.2f %c\n", value, unit_from, result, unit_to);
                    break;
                case 'k':
                case 'K':
                    result = value / 100;
                    printf("%.2f %c = %.2f %c\n", value, unit_from, result, unit_to);
                    break;
                default:
                    printf("Invalid conversion\n");
                    break;
            }
            break;
        default:
            printf("Invalid conversion\n");
            break;
    }

    return 0;
}