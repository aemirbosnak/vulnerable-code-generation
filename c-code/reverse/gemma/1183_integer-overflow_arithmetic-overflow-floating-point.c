#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float value;
    char from_unit, to_unit;

    printf("Enter the value: ");
    scanf("%f", &value);

    printf("Enter the unit you are converting from: ");
    scanf(" %c", &from_unit);

    printf("Enter the unit you are converting to: ");
    scanf(" %c", &to_unit);

    if (from_unit == 'm' && to_unit == 'k')
    {
        printf("%f meters is equal to %f kilometers.\n", value, value * 1000);
    }
    else if (from_unit == 'm' && to_unit == 'cm')
    {
        printf("%f meters is equal to %f centimeters.\n", value, value * 100);
    }
    else if (from_unit == 'm' && to_unit == 'mm')
    {
        printf("%f meters is equal to %f millimeters.\n", value, value * 1000);
    }
    else if (from_unit == 'f' && to_unit == 'm')
    {
        printf("%f feet is equal to %f meters.\n", value, value * 0.328);
    }
    else if (from_unit == 'f' && to_unit == 'in')
    {
        printf("%f feet is equal to %f inches.\n", value, value * 12);
    }
    else
    {
        printf("Invalid units.\n");
    }

    return 0;
}
