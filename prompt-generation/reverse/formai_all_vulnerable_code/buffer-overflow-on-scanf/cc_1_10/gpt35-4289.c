//FormAI DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

/* Function to swap elements */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Function for bubble sort algorithm */
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/* Function for insertion sort algorithm */
void insertionSort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* Function for selection sort algorithm */
void selectionSort(int arr[], int size)
{
    int i, j, min_idx;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int size, choice;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size], arr_copy[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        arr_copy[i] = arr[i];
    }

    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        bubbleSort(arr, size);
        printf("Array sorted using Bubble Sort: \n");
        break;
    case 2:
        insertionSort(arr, size);
        printf("Array sorted using Insertion Sort: \n");
        break;
    case 3:
        selectionSort(arr, size);
        printf("Array sorted using Selection Sort: \n");
        break;
    default:
        printf("Invalid choice.\n");
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nOriginal array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr_copy[i]);
    }

    return 0;
}