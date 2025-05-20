//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    double number, unit, converted_number;
    char unit_from, unit_to;

    printf("Enter a number: ");
    scanf("%lf", &number);

    printf("Enter the unit you want to convert from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'm':
            switch (unit_to)
            {
                case 'km':
                    converted_number = number * 1000;
                    break;
                case 'cm':
                    converted_number = number * 100;
                    break;
                case 'dm':
                    converted_number = number * 10;
                    break;
                case 'g':
                    converted_number = number * 1000000;
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    converted_number = number * 0.001;
                    break;
                case 'cm':
                    converted_number = number * 0.01;
                    break;
                case 'dm':
                    converted_number = number * 0.1;
                    break;
                case 'g':
                    converted_number = number * 1000;
                    break;
            }
            break;
        case 'L':
            switch (unit_to)
            {
                case 'ml':
                    converted_number = number * 1000;
                    break;
                case 'cl':
                    converted_number = number * 1000;
                    break;
                case 'dl':
                    converted_number = number * 10;
                    break;
            }
            break;
    }

    converted_number = round(converted_number * 10000) / 10000;

    printf("The converted number is: %.4lf %s", converted_number, unit_to);

    return 0;
}