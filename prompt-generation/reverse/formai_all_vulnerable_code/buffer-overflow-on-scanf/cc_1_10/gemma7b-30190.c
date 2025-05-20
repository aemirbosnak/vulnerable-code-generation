//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void insertionsort(int arr[], int n)
{
    int i, j, key, temp;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int n, i;
    int arr[MAX];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertionsort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}