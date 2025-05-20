//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int main()
{
    int n, i, j, k, l, h, count = 0, b[MAX], a[MAX], f[MAX];
    char ch;

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of characters: ");
        scanf("%d", &k);

        printf("Enter the characters: ");
        for (j = 0; j < k; j++)
        {
            scanf(" %c", &ch);
            a[j] = ch;
        }

        l = 0;
        for (j = 0; j < k; j++)
        {
            h = 0;
            for (k = 0; k < j; k++)
            {
                if (a[j] == a[k])
                    h++;
            }

            f[l] = h;
            l++;
        }

        count = 0;
        for (j = 0; j < l; j++)
        {
            if (f[j] > count)
                count = f[j];
        }

        printf("The maximum number of repeated characters is: %d\n", count);
    }

    return 0;
}