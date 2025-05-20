//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void main()
{
    char unit1[20], unit2[20], choice;
    float num1, num2, result;
    int i, j, k;

    printf("Enter the unit you want to convert from: ");
    scanf("%s", unit1);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", unit2);

    printf("Enter the value you want to convert: ");
    scanf("%f", &num1);

    printf("Enter the unit of the value you entered: ");
    scanf(" %c", &choice);

    switch(choice)
    {
        case'm':
            num1 = num1 * 100;
            printf("%.2f %c = %.2f %c", num1, unit1[0], num1/100, unit2[0]);
            break;

        case 'M':
            num1 = num1 * 1000;
            printf("%.2f %c = %.2f %c", num1, unit1[0], num1/1000, unit2[0]);
            break;

        case 'k':
            num1 = num1 * 1000;
            printf("%.2f %c = %.2f %c", num1, unit1[0], num1/1000, unit2[0]);
            break;

        case 'K':
            num1 = num1 * 1000000;
            printf("%.2f %c = %.2f %c", num1, unit1[0], num1/1000000, unit2[0]);
            break;

        case 'g':
            num1 = num1 * 1000000000;
            printf("%.2f %c = %.2f %c", num1, unit1[0], num1/1000000000, unit2[0]);
            break;

        case 'G':
            num1 = num1 * 1000000000000;
            printf("%.2f %c = %.2f %c", num1, unit1[0], num1/1000000000000, unit2[0]);
            break;

        case's':
            num1 = num1 * 1000;
            printf("%.2f %c = %.2f %c", num1, unit1[0], num1/1000, unit2[0]);
            break;

        default:
            printf("Invalid unit entered!");
            break;
    }

}