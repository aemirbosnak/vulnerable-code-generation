//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <math.h>

int main()
{
    float number;
    char unit_from, unit_to;

    printf("Enter a number: ");
    scanf("%f", &number);

    printf("Enter the unit you want to convert from: ");
    scanf(" %c", &unit_from);

    printf("Enter the unit you want to convert to: ");
    scanf(" %c", &unit_to);

    switch (unit_from)
    {
        case 'm':
            switch (unit_to)
            {
                case 'kg':
                    printf("The conversion is: %.2f kg", number * 1000);
                    break;
                case 'g':
                    printf("The conversion is: %.2f g", number * 1000);
                    break;
                case 't':
                    printf("The conversion is: %.2f t", number * 1000000);
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    printf("The conversion is: %.2f m", number * 0.001);
                    break;
                case 'g':
                    printf("The conversion is: %.2f g", number * 1000);
                    break;
                case 't':
                    printf("The conversion is: %.2f t", number * 1000000);
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    printf("The conversion is: %.2f m", number * 0.001);
                    break;
                case 'kg':
                    printf("The conversion is: %.2f kg", number * 0.001);
                    break;
                case 't':
                    printf("The conversion is: %.2f t", number * 1000000);
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    printf("The conversion is: %.2f m", number * 0.001);
                    break;
                case 'kg':
                    printf("The conversion is: %.2f kg", number * 0.001);
                    break;
                case 'g':
                    printf("The conversion is: %.2f g", number * 1000);
                    break;
            }
            break;
    }

    return 0;
}