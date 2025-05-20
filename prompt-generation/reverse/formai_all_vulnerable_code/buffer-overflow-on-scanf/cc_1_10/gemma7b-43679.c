//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char num[10];
    int i, oct, bin, n, a[10], count = 0;

    printf("Enter a number: ");
    scanf("%s", num);

    n = strlen(num);

    for (i = n - 1; i >= 0; i--)
    {
        a[count] = num[i] - 48;
        count++;
    }

    for (i = 0; i < count; i++)
    {
        bin = a[i] % 2;
        oct = (a[i] - bin) / 2;

        switch (bin)
        {
            case 0:
                printf("0");
                break;
            case 1:
                printf("1");
                break;
        }

        switch (oct)
        {
            case 0:
                printf("0");
                break;
            case 1:
                printf("1");
                break;
            case 2:
                printf("2");
                break;
            case 3:
                printf("3");
                break;
        }

        if (i > 0)
        {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}