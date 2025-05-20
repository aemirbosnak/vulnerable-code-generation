//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>
#include <math.h>

void main()
{
    float f_from, f_to, distance, conversion_factor;
    char unit_from, unit_to;

    printf("Enter the distance you want to convert:");
    scanf("%f", &distance);

    printf("Enter the unit you want to convert from:");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to:");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'm':
            conversion_factor = 1;
            break;
        case 'km':
            conversion_factor = 1000;
            break;
        case 'ft':
            conversion_factor = 3.28084;
            break;
        case 'yd':
            conversion_factor = 9.144;
            break;
    }

    switch (unit_to)
    {
        case 'm':
            f_to = distance * conversion_factor;
            printf("The converted distance is: %.2f meters.", f_to);
            break;
        case 'km':
            f_to = distance / conversion_factor;
            printf("The converted distance is: %.2f kilometers.", f_to);
            break;
        case 'ft':
            f_to = distance * conversion_factor * 3.28084;
            printf("The converted distance is: %.2f feet.", f_to);
            break;
        case 'yd':
            f_to = distance * conversion_factor * 9.144;
            printf("The converted distance is: %.2f yards.", f_to);
            break;
    }

    return;
}