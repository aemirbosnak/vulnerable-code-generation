//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num, result;
    char choice;

    do {
        printf("Enter a number to convert:\n");
        if (scanf("%lf", &num)!= 1) {
            printf("Invalid input\n");
            exit(1);
        }

        printf("Enter the unit you want to convert from:\n");
        scanf(" %c", &choice);

        printf("Enter the unit you want to convert to:\n");
        scanf(" %c", &choice);

        switch (choice) {
            case'm':
                result = num * 100;
                printf("%.2lf meters is %.2lf centimeters\n", num, result);
                break;
            case 'c':
                result = num / 100;
                printf("%.2lf centimeters is %.2lf meters\n", num, result);
                break;
            case 'k':
                result = num * 1000;
                printf("%.2lf meters is %.2lf kilometers\n", num, result);
                break;
            case 'K':
                result = num / 1000;
                printf("%.2lf kilometers is %.2lf meters\n", num, result);
                break;
            case 'g':
                result = num * 1000000;
                printf("%.2lf meters is %.2lf kilometers\n", num, result);
                break;
            case 'G':
                result = num / 1000000;
                printf("%.2lf kilometers is %.2lf meters\n", num, result);
                break;
            case 'l':
                result = num * 0.264172;
                printf("%.2lf liters is %.2lf gallons\n", num, result);
                break;
            case 'L':
                result = num / 0.264172;
                printf("%.2lf gallons is %.2lf liters\n", num, result);
                break;
            case 'o':
                result = num * 35.274;
                printf("%.2lf ounces is %.2lf milliliters\n", num, result);
                break;
            case 'O':
                result = num / 35.274;
                printf("%.2lf milliliters is %.2lf ounces\n", num, result);
                break;
            case 'p':
                result = num * 453.592;
                printf("%.2lf pounds is %.2lf kilograms\n", num, result);
                break;
            case 'P':
                result = num / 453.592;
                printf("%.2lf kilograms is %.2lf pounds\n", num, result);
                break;
            default:
                printf("Invalid unit\n");
        }
    } while (choice!= 'q');

    return 0;
}