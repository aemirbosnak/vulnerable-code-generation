//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num, result;
    char unit1, unit2;
    printf("Enter a number: ");
    scanf("%lf", &num);
    printf("Enter the current unit (e.g. kg, m, s): ");
    scanf(" %c", &unit1);
    printf("Enter the desired unit (e.g. lb, ft, hr): ");
    scanf(" %c", &unit2);
    switch(unit1) {
        case'm':
            switch(unit2) {
                case 'ft':
                    result = num * 3.28084;
                    printf("%.2lf meters is equal to %.2lf feet.\n", num, result);
                    break;
                case 'kg':
                    result = num * 0.453592;
                    printf("%.2lf meters is equal to %.2lf kilograms.\n", num, result);
                    break;
                case's':
                    result = num * 0.3048;
                    printf("%.2lf meters is equal to %.2lf seconds.\n", num, result);
                    break;
                default:
                    printf("Invalid units.\n");
            }
            break;
        case 'kg':
            switch(unit2) {
                case 'lb':
                    result = num * 2.20462;
                    printf("%.2lf kilograms is equal to %.2lf pounds.\n", num, result);
                    break;
                case'm':
                    result = num * 0.001;
                    printf("%.2lf kilograms is equal to %.2lf meters.\n", num, result);
                    break;
                case's':
                    result = num * 0.453592;
                    printf("%.2lf kilograms is equal to %.2lf seconds.\n", num, result);
                    break;
                default:
                    printf("Invalid units.\n");
            }
            break;
        case's':
            switch(unit2) {
                case 'hr':
                    result = num * 0.00027778;
                    printf("%.2lf seconds is equal to %.2lf hours.\n", num, result);
                    break;
                case'm':
                    result = num * 0.01666667;
                    printf("%.2lf seconds is equal to %.2lf meters.\n", num, result);
                    break;
                case 'kg':
                    result = num * 0.005;
                    printf("%.2lf seconds is equal to %.2lf kilograms.\n", num, result);
                    break;
                default:
                    printf("Invalid units.\n");
            }
            break;
        default:
            printf("Invalid units.\n");
    }
    return 0;
}