//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void mergeSort(int arr[], int n);
void partition(int arr[], int low, int high);

int main()
{
    int n;
    scanf("Enter the number of elements: ", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
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
    int leftArray[mid];
    int rightArray[n - mid];

    for (int i = 0; i < mid; i++)
    {
        leftArray[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        rightArray[i - mid] = arr[i];
    }

    mergeSort(leftArray, mid);
    mergeSort(rightArray, n - mid);

    partition(arr, 0, n - 1);
}

void partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
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

    return;
}