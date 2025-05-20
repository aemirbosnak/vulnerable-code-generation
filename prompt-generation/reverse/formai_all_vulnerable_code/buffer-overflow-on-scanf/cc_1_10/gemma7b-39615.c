//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void merge(int *arr, int n)
{
    int i = 0, j = n - 1, mid = (n - 1) / 2;
    int l_arr[mid], r_arr[mid + 1];

    for (int i = 0; i < mid; i++)
    {
        l_arr[i] = arr[i];
    }

    for (int j = mid; j < n; j++)
    {
        r_arr[j - mid] = arr[j];
    }

    int k = 0;
    while (i < mid && j >= 0)
    {
        if (l_arr[i] < r_arr[j])
        {
            arr[k] = l_arr[i];
            i++;
        }
        else
        {
            arr[k] = r_arr[j];
            j--;
        }
        k++;
    }

    while (i < mid)
    {
        arr[k] = l_arr[i];
        i++;
        k++;
    }

    while (j >= 0)
    {
        arr[k] = r_arr[j];
        j--;
        k++;
    }
}

int main()
{
    int arr[MAX], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    merge(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}