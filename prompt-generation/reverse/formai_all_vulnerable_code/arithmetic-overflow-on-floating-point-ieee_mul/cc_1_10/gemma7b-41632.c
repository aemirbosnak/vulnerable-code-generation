//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

void UnitConverter(void)
{
    float number;
    char unit_from, unit_to;

    printf("Enter the number: ");
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
                    printf("The converted weight is: %.2f kg\n", number * 1000);
                    break;
                case 'g':
                    printf("The converted weight is: %.2f g\n", number * 1000);
                    break;
                case 't':
                    printf("The converted weight is: %.2f tons\n", number * 1000);
                    break;
            }
            break;
        case 'kg':
            switch (unit_to)
            {
                case 'm':
                    printf("The converted length is: %.2f m\n", number / 1000);
                    break;
                case 'g':
                    printf("The converted length is: %.2f g\n", number / 1000);
                    break;
                case 't':
                    printf("The converted length is: %.2f tons\n", number / 1000);
                    break;
            }
            break;
        case 'g':
            switch (unit_to)
            {
                case 'm':
                    printf("The converted length is: %.2f m\n", number / 1000);
                    break;
                case 'kg':
                    printf("The converted weight is: %.2f kg\n", number / 1000);
                    break;
                case 't':
                    printf("The converted length is: %.2f tons\n", number / 1000);
                    break;
            }
            break;
        case 't':
            switch (unit_to)
            {
                case 'm':
                    printf("The converted length is: %.2f m\n", number * 1000);
                    break;
                case 'kg':
                    printf("The converted weight is: %.2f kg\n", number * 1000);
                    break;
                case 'g':
                    printf("The converted weight is: %.2f g\n", number * 1000);
                    break;
            }
            break;
    }
}

int main()
{
    UnitConverter();

    return 0;
}