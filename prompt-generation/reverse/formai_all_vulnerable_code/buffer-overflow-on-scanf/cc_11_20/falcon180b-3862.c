//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char choice;
    double input, result;
    printf("Welcome to the Unit Converter!\n");
    printf("Enter the unit you want to convert from (L for length, W for weight, T for temperature): ");
    scanf("%c", &choice);

    switch(choice) {
        case 'L':
            printf("Enter the length you want to convert: ");
            scanf("%lf", &input);
            printf("Enter the unit of input length (M for meters, CM for centimeters, MM for millimeters): ");
            scanf("%c", &choice);
            switch(choice) {
                case 'M':
                    result = input * 1;
                    printf("%lf meters is equal to %lf feet.\n", input, result);
                    break;
                case 'CM':
                    result = input * 0.01;
                    printf("%lf meters is equal to %lf feet.\n", input, result);
                    break;
                case 'MM':
                    result = input * 0.001;
                    printf("%lf meters is equal to %lf feet.\n", input, result);
                    break;
                default:
                    printf("Invalid unit of input length.\n");
                    break;
            }
            break;
        case 'W':
            printf("Enter the weight you want to convert: ");
            scanf("%lf", &input);
            printf("Enter the unit of input weight (KG for kilograms, LB for pounds): ");
            scanf("%c", &choice);
            switch(choice) {
                case 'KG':
                    result = input * 2.20462;
                    printf("%lf kilograms is equal to %lf pounds.\n", input, result);
                    break;
                case 'LB':
                    result = input * 0.453592;
                    printf("%lf pounds is equal to %lf kilograms.\n", input, result);
                    break;
                default:
                    printf("Invalid unit of input weight.\n");
                    break;
            }
            break;
        case 'T':
            printf("Enter the temperature you want to convert: ");
            scanf("%lf", &input);
            printf("Enter the unit of input temperature (C for Celsius, F for Fahrenheit): ");
            scanf("%c", &choice);
            switch(choice) {
                case 'C':
                    result = input * 1.8 + 32;
                    printf("%lf Celsius is equal to %lf Fahrenheit.\n", input, result);
                    break;
                case 'F':
                    result = (input - 32) / 1.8;
                    printf("%lf Fahrenheit is equal to %lf Celsius.\n", input, result);
                    break;
                default:
                    printf("Invalid unit of input temperature.\n");
                    break;
            }
            break;
        default:
            printf("Invalid unit of conversion.\n");
            break;
    }

    return 0;
}