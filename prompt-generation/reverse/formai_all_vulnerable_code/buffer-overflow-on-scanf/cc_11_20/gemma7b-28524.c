//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    float num;
    int unit_from, unit_to;

    printf("Welcome to the Retro Unit Converter!\n");
    printf("Please enter the number you want to convert: ");
    scanf("%f", &num);

    printf("Please select the unit you want to convert from:\n");
    printf("1. Metric\n");
    printf("2. Imperial\n");
    printf("3. Nautical\n");

    printf("Please select the unit you want to convert to:\n");
    printf("1. Metric\n");
    printf("2. Imperial\n");
    printf("3. Nautical\n");

    scanf("%d", &unit_from);
    scanf("%d", &unit_to);

    switch (unit_from)
    {
        case 1:
            switch (unit_to)
            {
                case 1:
                    printf("The converted number is: %.2f", num);
                    break;
                case 2:
                    printf("The converted number is: %.2f", num * 1.613);
                    break;
                case 3:
                    printf("The converted number is: %.2f", num * 1.852);
                    break;
            }
            break;
        case 2:
            switch (unit_to)
            {
                case 1:
                    printf("The converted number is: %.2f", num * 0.625);
                    break;
                case 2:
                    printf("The converted number is: %.2f", num);
                    break;
                case 3:
                    printf("The converted number is: %.2f", num * 1.157);
                    break;
            }
            break;
        case 3:
            switch (unit_to)
            {
                case 1:
                    printf("The converted number is: %.2f", num * 0.54);
                    break;
                case 2:
                    printf("The converted number is: %.2f", num * 0.861);
                    break;
                case 3:
                    printf("The converted number is: %.2f", num);
                    break;
            }
            break;
    }

    return 0;
}