//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

#define MAX 10

int main()
{
    int n, i, j, k, a[MAX], b[MAX], c[MAX], d[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the values of each item: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    for(i = 0; i < n; i++)
    {
        c[i] = a[i] * b[i];
    }

    k = 0;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(c[i] > c[j])
            {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    printf("The optimal solution: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }

    return 0;
}