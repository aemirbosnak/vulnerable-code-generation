//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double value, result;
    char unit_from, unit_to;

    printf("Welcome to the Ultimate Unit Converter!\n");

    // Get the input value and units
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the current unit (e.g. kg, m, s): ");
    scanf(" %c", &unit_from);

    // Get the desired output unit
    printf("Enter the desired output unit (e.g. lb, ft, hr): ");
    scanf(" %c", &unit_to);

    // Convert the value
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
                    printf("Invalid conversion requested.\n");
                    exit(1);
            }
            break;
        case 'kg':
            switch(unit_to) {
                case 'lb':
                    result = value * 2.20462;
                    printf("%.2lf kilograms is equal to %.2lf pounds.\n", value, result);
                    break;
                default:
                    printf("Invalid conversion requested.\n");
                    exit(1);
            }
            break;
        case's':
            switch(unit_to) {
                case 'hr':
                    result = value / 3600;
                    printf("%.2lf seconds is equal to %.2lf hours.\n", value, result);
                    break;
                default:
                    printf("Invalid conversion requested.\n");
                    exit(1);
            }
            break;
        default:
            printf("Invalid input unit requested.\n");
            exit(1);
    }

    return 0;
}