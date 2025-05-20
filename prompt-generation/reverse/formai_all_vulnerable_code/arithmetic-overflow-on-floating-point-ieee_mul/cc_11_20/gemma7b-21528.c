//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    float f;
    int c;
    char s[20];

    printf("Enter the number of conversions: ");
    scanf("%d", &c);

    for (int i = 0; i < c; i++)
    {
        printf("Enter the conversion factor: ");
        scanf("%f", &f);

        printf("Enter the unit you want to convert from: ");
        scanf("%s", s);

        printf("Enter the unit you want to convert to: ");
        scanf("%s", s);

        switch (s[0])
        {
            case 'M':
                switch (s[1])
                {
                    case 'K':
                        f *= 1000;
                        break;
                    case 'H':
                        f *= 1000000;
                        break;
                    case 'G':
                        f *= 1000000000;
                        break;
                }
                break;
            case 'L':
                switch (s[1])
                {
                    case 'M':
                        f *= 1000;
                        break;
                    case 'F':
                        f *= 16.09;
                        break;
                    case 'Y':
                        f *= 9.80665;
                        break;
                }
                break;
            case 'T':
                switch (s[1])
                {
                    case 'S':
                        f *= 60;
                        break;
                    case 'M':
                        f *= 60 * 60;
                        break;
                    case 'H':
                        f *= 60 * 60 * 24;
                        break;
                }
                break;
            default:
                printf("Invalid unit.\n");
                break;
        }

        printf("The converted value is: %.2f %s.\n", f, s);
    }

    return 0;
}