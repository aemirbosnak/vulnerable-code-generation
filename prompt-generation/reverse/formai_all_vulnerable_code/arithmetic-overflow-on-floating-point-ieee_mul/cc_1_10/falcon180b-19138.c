//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Define variables
    char fromUnit, toUnit;
    double value;

    // Prompt user for input
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from: ");
    scanf(" %c", &fromUnit);
    printf("Enter the unit to convert to: ");
    scanf(" %c", &toUnit);

    // Convert the value
    switch (fromUnit) {
        case'm':
            switch (toUnit) {
                case 'k':
                    value *= 1000;
                    printf("%.2lf meters is equal to %.2lf kilometers.\n", value, value);
                    break;
                case 'c':
                    value /= 100;
                    printf("%.2lf meters is equal to %.2lf centimeters.\n", value, value);
                    break;
                default:
                    printf("Invalid conversion.\n");
                    break;
            }
            break;
        case 'k':
            switch (toUnit) {
                case'm':
                    value /= 1000;
                    printf("%.2lf kilometers is equal to %.2lf meters.\n", value, value);
                    break;
                case 'c':
                    value *= 100;
                    printf("%.2lf kilometers is equal to %.2lf centimeters.\n", value, value);
                    break;
                default:
                    printf("Invalid conversion.\n");
                    break;
            }
            break;
        case 'c':
            switch (toUnit) {
                case'm':
                    value /= 100;
                    printf("%.2lf centimeters is equal to %.2lf meters.\n", value, value);
                    break;
                case 'k':
                    value /= 100000;
                    printf("%.2lf centimeters is equal to %.2lf kilometers.\n", value, value);
                    break;
                default:
                    printf("Invalid conversion.\n");
                    break;
            }
            break;
        default:
            printf("Invalid unit.\n");
            break;
    }

    return 0;
}