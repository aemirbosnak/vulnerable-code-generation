//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100], f[100], g[100];

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of elements in the array: ");
        scanf("%d", &k);

        printf("Enter the elements of the array: ");
        for (j = 0; j < k; j++)
        {
            scanf("%d", &a[j]);
        }

        printf("Enter the operations to be performed: ");
        scanf("%d", &l);

        for (m = 0; m < l; m++)
        {
            scanf("%d", &c[m]);
        }

        for (j = 0; j < k; j++)
        {
            for (m = 0; m < l; m++)
            {
                switch (c[m])
                {
                    case 1:
                        b[j] = a[j] + 10;
                        break;
                    case 2:
                        b[j] = a[j] - 10;
                        break;
                    case 3:
                        b[j] = a[j] * 10;
                        break;
                    case 4:
                        b[j] = a[j] / 10;
                        break;
                }
            }
        }

        printf("The elements of the array after the operations are: ");
        for (j = 0; j < k; j++)
        {
            printf("%d ", b[j]);
        }

        printf("\n");
    }

    return 0;
}