//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, a, b, c, d, e, f, g, h, k, l, m, n1, n2;
    char str1[100], str2[100], str3[100], str4[100], str5[100], str6[100], str7[100], str8[100], str9[100], str10[100], op;

    printf("Enter the number of conversions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the conversion type (e.g. km, kg, etc.): ");
        scanf("%s", str1);

        printf("Enter the first value: ");
        scanf("%d", &a);

        printf("Enter the second value: ");
        scanf("%d", &b);

        c = (a * b) / 1000;
        d = (a * b) % 1000;

        printf("The conversion result is: ");

        switch (str1[0])
        {
            case 'k':
                printf("%d km = %d m", c, d);
                break;
            case 'm':
                printf("%d m = %d km", c, d);
                break;
            case 'kg':
                printf("%d kg = %d g", c, d);
                break;
            case 'g':
                printf("%d g = %d kg", c, d);
                break;
            default:
                printf("Invalid conversion type");
                break;
        }

        printf("\n");
    }

    return 0;
}