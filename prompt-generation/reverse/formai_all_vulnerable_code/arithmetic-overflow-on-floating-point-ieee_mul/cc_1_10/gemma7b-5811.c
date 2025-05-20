//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    int choice, unit_from, unit_to;
    double value;

    printf("Enter 1 for conversion from meters to kilometers, 2 for conversion from liters to gallons, 3 for conversion from kilograms to pounds, or 4 for conversion from degrees Celsius to Fahrenheit:\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the value in meters:");
            scanf("%lf", &value);
            unit_from = 1;
            unit_to = 2;
            break;
        case 2:
            printf("Enter the value in liters:");
            scanf("%lf", &value);
            unit_from = 3;
            unit_to = 4;
            break;
        case 3:
            printf("Enter the value in kilograms:");
            scanf("%lf", &value);
            unit_from = 4;
            unit_to = 5;
            break;
        case 4:
            printf("Enter the value in degrees Celsius:");
            scanf("%lf", &value);
            unit_from = 5;
            unit_to = 6;
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    switch (unit_to)
    {
        case 2:
            value *= 1000;
            printf("The value in kilometers is: %.2lf\n", value);
            break;
        case 4:
            value *= 3.785;
            printf("The value in gallons is: %.2lf\n", value);
            break;
        case 5:
            value *= 2.204;
            printf("The value in pounds is: %.2lf\n", value);
            break;
        case 6:
            value = (value - 32) * 5 / 9;
            printf("The value in Fahrenheit is: %.2lf\n", value);
            break;
    }

    return 0;
}