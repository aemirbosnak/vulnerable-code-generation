//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, unit, target_unit;
    float conversion_factor;

    printf("Welcome to the Funky Unit Converter!\n");
    printf("Please enter the number you want to convert:");
    scanf("%d", &num);

    printf("Please select the unit you want to convert from:");
    printf("1. Metric\n");
    printf("2. Imperial\n");
    printf("3. Binary\n");
    scanf("%d", &unit);

    printf("Please select the unit you want to convert to:");
    printf("1. Metric\n");
    printf("2. Imperial\n");
    printf("3. Binary\n");
    scanf("%d", &target_unit);

    switch (unit)
    {
        case 1:
            switch (target_unit)
            {
                case 1:
                    conversion_factor = 1;
                    break;
                case 2:
                    conversion_factor = 1000;
                    break;
                case 3:
                    conversion_factor = 1000000;
                    break;
            }
            break;
        case 2:
            switch (target_unit)
            {
                case 1:
                    conversion_factor = 0.001;
                    break;
                case 2:
                    conversion_factor = 1;
                    break;
                case 3:
                    conversion_factor = 1609.34;
                    break;
            }
            break;
        case 3:
            switch (target_unit)
            {
                case 1:
                    conversion_factor = 0.000001;
                    break;
                case 2:
                    conversion_factor = 0.000001024;
                    break;
                case 3:
                    conversion_factor = 1;
                    break;
            }
            break;
    }

    conversion_factor = num * conversion_factor;

    printf("The converted number is:");
    printf(" %.2f", conversion_factor);

    printf("Thank you for using the Funky Unit Converter!\n");

    return 0;
}