//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(int **a, int n)
{
    int i, j, k, l, count = 0, min, max, diff, b[MAX], flag = 0;

    for (i = 0; i < n; i++)
    {
        min = MAX;
        max = -MAX;
        diff = 0;

        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (a[i] < min)
                min = a[i];

            if (a[i] > max)
                max = a[i];

            diff += abs(a[i] - a[j]);
        }

        b[count] = min;
        b[count + 1] = max;
        b[count + 2] = diff;

        count += 3;

        if (diff > flag)
            flag = diff;
    }

    printf("Minimum: ");
    for (i = 0; i < count; i++)
        printf("%d ", b[i]);

    printf("\nMaximum: ");
    for (i = 0; i < count; i++)
        printf("%d ", b[i + count]);

    printf("\nTotal Difference: %d", flag);
}

int main()
{
    int n, **a;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    compress(a, n);

    return 0;
}