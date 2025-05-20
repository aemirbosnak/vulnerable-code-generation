//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    int choice;
    float num;
    char unit_from, unit_to;

    printf("Enter 1 for metric, 2 for imperial, 3 for nautical:\n");
    scanf("%d", &choice);

    printf("Enter the number: ");
    scanf("%f", &num);

    printf("Enter the unit you want to convert from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    switch (choice)
    {
        case 1:
            switch (unit_from)
            {
                case 'm':
                    switch (unit_to)
                    {
                        case 'km':
                            num *= 1000;
                            break;
                        case 'hm':
                            num *= 100;
                            break;
                        case 'dm':
                            num *= 10;
                            break;
                        case 'cm':
                            num *= 100;
                            break;
                        case 'mm':
                            num *= 1000;
                            break;
                    }
                    break;
                case 'kg':
                    switch (unit_to)
                    {
                        case 'g':
                            num *= 1000;
                            break;
                        case 't':
                            num *= 1000;
                            break;
                        case 'lb':
                            num *= 2.20462;
                            break;
                        case 'oz':
                            num *= 2.20462;
                            break;
                    }
                    break;
                case 'l':
                    switch (unit_to)
                    {
                        case 'ml':
                            num *= 1000;
                            break;
                        case 'dl':
                            num *= 1000;
                            break;
                        case 'gal':
                            num *= 3.78541;
                            break;
                        case 'qt':
                            num *= 3.78541;
                            break;
                    }
                    break;
            }
            break;
        case 2:
            switch (unit_from)
            {
                case 'in':
                    switch (unit_to)
                    {
                        case 'cm':
                            num *= 2.54;
                            break;
                        case 'mm':
                            num *= 2.54;
                            break;
                        case 'ft':
                            num *= 12;
                            break;
                        case 'yd':
                            num *= 9.4488;
                            break;
                    }
                    break;
                case 'lb':
                    switch (unit_to)
                    {
                        case 'kg':
                            num *= 0.45359;
                            break;
                        case 't':
                            num *= 0.45359;
                            break;
                        case 'oz':
                            num *= 0.45359;
                            break;
                        case 'g':
                            num *= 0.45359;
                            break;
                    }
                    break;
                case 'gal':
                    switch (unit_to)
                    {
                        case 'l':
                            num *= 3.78541;
                            break;
                        case 'ml':
                            num *= 3.78541;
                            break;
                        case 'dl':
                            num *= 3.78541;
                            break;
                        case 'qt':
                            num *= 3.78541;
                            break;
                    }
                    break;
            }
            break;
        case 3:
            switch (unit_from)
            {
                case 'n':
                    switch (unit_to)
                    {
                        case 'km':
                            num *= 1.852;
                            break;
                        case 'hm':
                            num *= 1.852;
                            break;
                        case 'dm':
                            num *= 0.01852;
                            break;
                        case 'cm':
                            num *= 0.01852;
                            break;
                        case 'ft':
                            num *= 0.01852;
                            break;
                        case 'yd':
                            num *= 0.01852;
                            break;
                    }
                    break;
                case 'kn':
                    switch (unit_to)
                    {
                        case 'km':
                            num *= 1.852;
                            break;
                        case 'hm':
                            num *= 1.852;
                            break;
                        case 'dm':
                            num *= 0.01852;
                            break;
                        case 'cm':
                            num *= 0.01852;
                            break;
                        case 'ft':
                            num *= 0.01852;
                            break;
                        case 'yd':
                            num *= 0.01852;
                            break;
                    }
                    break;
            }
            break;
    }

    printf("The converted number is: %.2f %s\n", num, unit_to);

    return 0;
}