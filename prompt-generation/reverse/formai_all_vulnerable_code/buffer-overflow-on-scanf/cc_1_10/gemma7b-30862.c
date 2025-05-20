//Gemma-7B DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, i, j, k, arr[MAX], love[MAX];
    printf("Enter the number of hearts: ");
    scanf("%d", &n);

    printf("Enter the names of the hearts: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr);
    }

    printf("Enter the strengths of the hearts: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", love);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (love[i] > love[j])
            {
                swap(&arr[i], &arr[j]);
                swap(&love[i], &love[j]);
            }
        }
    }

    printf("The rearranged hearts are: ");
    for (i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }

    printf("\nThe rearranged strengths are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", love[i]);
    }

    return 0;
}