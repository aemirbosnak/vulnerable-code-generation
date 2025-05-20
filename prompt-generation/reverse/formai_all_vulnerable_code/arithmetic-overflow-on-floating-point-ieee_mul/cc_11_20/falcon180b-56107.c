//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    char choice;
    double num, result = 0;

    printf("Welcome to the Unit Converter!\n");
    printf("Please choose a unit to convert:\n");
    printf("A) Length\nB) Weight\nC) Volume\n");
    scanf("%c", &choice);

    switch(choice)
    {
        case 'A':
            printf("Please enter the value to convert:\n");
            scanf("%lf", &num);
            printf("Please choose the unit you want to convert from:\n");
            printf("A) Meters\nB) Centimeters\nC) Millimeters\n");
            scanf("%c", &choice);

            switch(choice)
            {
                case 'A':
                    result = num * 1000;
                    printf("%lf meters is equal to %lf millimeters.\n", num, result);
                    break;
                case 'B':
                    result = num / 100;
                    printf("%lf meters is equal to %lf centimeters.\n", num, result);
                    break;
                case 'C':
                    result = num * 10;
                    printf("%lf meters is equal to %lf decimeters.\n", num, result);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
            break;
        case 'B':
            printf("Please enter the value to convert:\n");
            scanf("%lf", &num);
            printf("Please choose the unit you want to convert from:\n");
            printf("A) Kilograms\nB) Grams\nC) Milligrams\n");
            scanf("%c", &choice);

            switch(choice)
            {
                case 'A':
                    result = num * 1000;
                    printf("%lf kilograms is equal to %lf grams.\n", num, result);
                    break;
                case 'B':
                    result = num * 1000000;
                    printf("%lf kilograms is equal to %lf milligrams.\n", num, result);
                    break;
                case 'C':
                    result = num / 1000;
                    printf("%lf kilograms is equal to %lf decigrams.\n", num, result);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
            break;
        case 'C':
            printf("Please enter the value to convert:\n");
            scanf("%lf", &num);
            printf("Please choose the unit you want to convert from:\n");
            printf("A) Liters\nB) Milliliters\nC) Cubic Centimeters\n");
            scanf("%c", &choice);

            switch(choice)
            {
                case 'A':
                    result = num * 1000;
                    printf("%lf liters is equal to %lf cubic decimeters.\n", num, result);
                    break;
                case 'B':
                    result = num * 1000000;
                    printf("%lf liters is equal to %lf cubic centimeters.\n", num, result);
                    break;
                case 'C':
                    result = num / 1000;
                    printf("%lf liters is equal to %lf deciliters.\n", num, result);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}