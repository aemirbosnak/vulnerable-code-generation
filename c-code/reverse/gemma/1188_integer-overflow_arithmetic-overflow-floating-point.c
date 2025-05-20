#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float distance;
    int unit_from, unit_to;

    printf("Enter the distance: ");
    scanf("%f", &distance);

    printf("Enter the unit you are converting from: ");
    scanf("%d", &unit_from);

    printf("Enter the unit you are converting to: ");
    scanf("%d", &unit_to);

    if (unit_from == 1 && unit_to == 2)
    {
        distance *= 1000;
    }
    else if (unit_from == 2 && unit_to == 1)
    {
        distance /= 1000;
    }
    else if (unit_from == 3 && unit_to == 1)
    {
        distance *= 1000;
    }
    else if (unit_from == 4 && unit_to == 1)
    {
        distance *= 1000;
    }
    else if (unit_from == 5 && unit_to == 1)
    {
        distance *= 1000;
    }
    else if (unit_from == 6 && unit_to == 1)
    {
        distance *= 3.28084;
    }
    else if (unit_from == 7 && unit_to == 1)
    {
        distance *= 3.28084;
    }

    printf("The converted distance is: %.2f", distance);

    return 0;
}
