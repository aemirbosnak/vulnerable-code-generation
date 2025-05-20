//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

int main()
{
    float number;
    char unit;
    float converted_number;

    printf("Enter a number: ");
    scanf("%f", &number);

    printf("Enter a unit: ");
    scanf(" %c", &unit);

    switch (unit)
    {
        case 'm':
            converted_number = number * 1000;
            printf("%f meters is equal to %f kilometers.\n", number, converted_number);
            break;
        case 'km':
            converted_number = number * 1000;
            printf("%f kilometers is equal to %f meters.\n", number, converted_number);
            break;
        case 'g':
            converted_number = number * 1000;
            printf("%f grams is equal to %f kilograms.\n", number, converted_number);
            break;
        case 'kg':
            converted_number = number * 1000;
            printf("%f kilograms is equal to %f grams.\n", number, converted_number);
            break;
        case 'a':
            converted_number = number * PI;
            printf("%f angles is equal to %f radians.\n", number, converted_number);
            break;
        case 'r':
            converted_number = number * PI;
            printf("%f radians is equal to %f angles.\n", number, converted_number);
            break;
        default:
            printf("Invalid unit.\n");
    }

    return 0;
}