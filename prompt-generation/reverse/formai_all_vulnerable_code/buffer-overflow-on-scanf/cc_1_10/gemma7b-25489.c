//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void mergeSort(int arr[], int n)
{
    if (n <= 1)
        return;

    int mid = n / 2;
    int leftArr[mid];
    int rightArr[n - mid];

    for (int i = 0; i < mid; i++)
        leftArr[i] = arr[i];

    for (int i = mid; i < n; i++)
        rightArr[i - mid] = arr[i];

    mergeSort(leftArr, mid);
    mergeSort(rightArr, n - mid);

    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid)
    {
        if (leftArr[i] <= rightArr[j])
            arr[k] = leftArr[i++];
        else
            arr[k] = rightArr[j++];

        k++;
    }

    while (i < mid)
        arr[k++] = leftArr[i++];

    while (j < n - mid)
        arr[k++] = rightArr[j++];
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}