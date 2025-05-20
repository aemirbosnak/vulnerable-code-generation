//Gemma-7B DATASET v1.0 Category: Sorting ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[MAX_SIZE];
    int n, i, j, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (k = 0; k < n - 1; k++)
    {
        for (i = 0; i < n - k - 1; i++)
        {
            for (j = i + 1; j < n - k - 1; j++)
            {
                if (arr[i] > arr[j])
                {
                    swap(&arr[i], &arr[j]);
                }
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}