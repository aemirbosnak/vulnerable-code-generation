//Falcon-180B DATASET v1.0 Category: Sorting ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, i;

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Initialize the array with random values
    int arr[n];
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, n);

    // Perform bubble sort
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}