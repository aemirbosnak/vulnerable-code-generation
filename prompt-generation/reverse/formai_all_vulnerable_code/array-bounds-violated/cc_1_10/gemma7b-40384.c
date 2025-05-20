//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void merge(int *arr, int n)
{
    int i = 0, j = n - 1, mid = (n - 1) / 2;
    int L[mid], R[mid + 1];

    for (int i = 0; i < mid; i++)
    {
        L[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        R[i - mid] = arr[i];
    }

    i = 0;
    j = mid;

    while (i < j)
    {
        if (L[i] > R[j])
        {
            arr[i] = R[j];
            j--;
        }
        else
        {
            arr[i] = L[i];
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {4, 3, 8, 6, 2, 5, 9, 1, 7, 3};
    int n = sizeof(arr) / sizeof(int);

    merge(arr, n);

    return 0;
}