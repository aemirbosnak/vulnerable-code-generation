//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double value, result;
    char unit_from, unit_to;

    // Ask user for input
    printf("Enter a value: ");
    scanf("%lf", &value);
    printf("Enter the unit of the value (e.g. kg, m, s): ");
    scanf(" %c", &unit_from);
    printf("Enter the unit you want to convert to (e.g. lb, ft, hr): ");
    scanf(" %c", &unit_to);

    // Convert the value based on the units
    switch(unit_from) {
        case'm':
            switch(unit_to) {
                case 'ft':
                    result = value * 3.28084;
                    printf("%.2lf meters is equal to %.2lf feet.\n", value, result);
                    break;
                case 'km':
                    result = value / 1000;
                    printf("%.2lf meters is equal to %.2lf kilometers.\n", value, result);
                    break;
                default:
                    printf("Invalid unit.\n");
                    break;
            }
            break;
        case's':
            switch(unit_to) {
                case 'hr':
                    result = value / 3600;
                    printf("%.2lf seconds is equal to %.2lf hours.\n", value, result);
                    break;
                case'min':
                    result = value / 60;
                    printf("%.2lf seconds is equal to %.2lf minutes.\n", value, result);
                    break;
                default:
                    printf("Invalid unit.\n");
                    break;
            }
            break;
        case 'kg':
            switch(unit_to) {
                case 'lb':
                    result = value * 2.20462;
                    printf("%.2lf kilograms is equal to %.2lf pounds.\n", value, result);
                    break;
                default:
                    printf("Invalid unit.\n");
                    break;
            }
            break;
        default:
            printf("Invalid unit.\n");
            break;
    }

    return 0;
}