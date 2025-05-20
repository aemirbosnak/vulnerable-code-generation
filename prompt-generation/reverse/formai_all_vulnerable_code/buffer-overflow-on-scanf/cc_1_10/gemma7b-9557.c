//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void mergeSort(int arr[], int n);
void merge(int arr[], int l, int r);

int main()
{
    int n;
    scanf("Enter the number of elements: ", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }

    mergeSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void mergeSort(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int mid = n / 2;
    int leftArr[mid];
    int rightArr[n - mid];

    for (int i = 0; i < mid; i++)
    {
        leftArr[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        rightArr[i - mid] = arr[i];
    }

    mergeSort(leftArr, mid);
    mergeSort(rightArr, n - mid);

    merge(arr, 0, n - 1);
}

void merge(int arr[], int l, int r)
{
    int mid = (l + r) / 2;
    int i = l;
    int j = mid + 1;
    int k = 0;

    int leftArr[mid - l + 1];
    int rightArr[r - mid];

    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
        {
            leftArr[k] = arr[i];
            i++;
        }
        else
        {
            leftArr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        leftArr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        leftArr[k] = arr[j];
        j++;
        k++;
    }

    for (int i = l; i <= r; i++)
    {
        arr[i] = leftArr[i - l];
    }
}