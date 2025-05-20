//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: immersive
#include <stdio.h>
#include <math.h>

int main()
{
    float number;
    char unit;
    char target_unit;

    printf("Enter the number: ");
    scanf("%f", &number);

    printf("Enter the unit: ");
    scanf(" %c", &unit);

    printf("Enter the target unit: ");
    scanf(" %c", &target_unit);

    switch (unit)
    {
        case 'm':
            switch (target_unit)
            {
                case 'kg':
                    printf("%f kg = %.2f tons", number * 1000, number * 1000 / 2000);
                    break;
                case 'g':
                    printf("%f g = %.2f mg", number, number * 1000);
                    break;
                case 't':
                    printf("%f t = %.2f tons", number, number * 1000);
                    break;
            }
            break;
        case 'kg':
            switch (target_unit)
            {
                case 'm':
                    printf("%f kg = %.2f m", number / 1000, number / 1000);
                    break;
                case 'g':
                    printf("%f kg = %.2f g", number * 1000, number * 1000);
                    break;
                case 't':
                    printf("%f kg = %.2f tons", number / 2000, number / 2000);
                    break;
            }
            break;
        case 'g':
            switch (target_unit)
            {
                case 'm':
                    printf("%f g = %.2f m", number / 1000, number / 1000);
                    break;
                case 'kg':
                    printf("%f g = %.2f kg", number / 1000, number / 1000);
                    break;
                case 't':
                    printf("%f g = %.2f tons", number / 2000, number / 2000);
                    break;
            }
            break;
        case 't':
            switch (target_unit)
            {
                case 'm':
                    printf("%f t = %.2f m", number * 1000, number * 1000);
                    break;
                case 'kg':
                    printf("%f t = %.2f kg", number * 1000, number * 1000);
                    break;
                case 'g':
                    printf("%f t = %.2f g", number * 2000, number * 2000);
                    break;
            }
            break;
    }

    return 0;
}