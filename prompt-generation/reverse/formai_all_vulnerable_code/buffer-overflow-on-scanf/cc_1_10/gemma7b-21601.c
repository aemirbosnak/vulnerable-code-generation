//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void mergeSort(int arr[], int n);
void quickSort(int arr[], int low, int high);

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, n);
    quickSort(arr, 0, n - 1);

    printf("Sorted array:");
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

    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < mid)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n - mid)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}