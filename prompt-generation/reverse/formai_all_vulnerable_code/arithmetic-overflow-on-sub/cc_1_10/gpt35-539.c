//FormAI DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>

// Function to swap two elements in an array
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for(i = 0; i < n-1; i++)
    {
        // Last i elements are already in place
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for(i = 0; i < n-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to perform insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[10], n, i;
    printf("Enter the size of the array (maximum 10): ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nBubble sorted array: ");
    bubbleSort(arr, n);
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nSelection sorted array: ");
    selectionSort(arr, n);
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nInsertion sorted array: ");
    insertionSort(arr, n);
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}