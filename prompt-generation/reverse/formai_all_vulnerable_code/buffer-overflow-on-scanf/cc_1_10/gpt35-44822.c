//FormAI DATASET v1.0 Category: Sorting ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100

void selection_sort(int arr[], int size);
void bubble_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void display_sorted_array(int arr[], int size);

int main()
{
    int array[MAX_ARRAY_SIZE], size, choice;
    srand(time(NULL)); // seeding the random function with time

    printf("Enter the size of the array (must be between 1 and %d): ", MAX_ARRAY_SIZE);
    scanf("%d", &size);

    // filling the array with random integers between 1 and 100
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100 + 1;
    }

    printf("\nUnsorted Array: ");
    display_sorted_array(array, size);

    printf("\nChoose a sorting algorithm <1/2/3>: ");
    printf("\n1. Selection Sort\t2. Bubble Sort\t3. Insertion Sort\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        selection_sort(array, size);
        printf("\nArray after Selection Sort: ");
        display_sorted_array(array, size);
        break;

    case 2:
        bubble_sort(array, size);
        printf("\nArray after Bubble Sort: ");
        display_sorted_array(array, size);
        break;

    case 3:
        insertion_sort(array, size);
        printf("\nArray after Insertion Sort: ");
        display_sorted_array(array, size);
        break;

    default:
        printf("\nInvalid Choice!");
        break;
    }

    return 0;
}

// function to perform selection sort
void selection_sort(int arr[], int size)
{
    int min_index, temp;

    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        if (min_index != i)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

// function to perform bubble sort
void bubble_sort(int arr[], int size)
{
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// function to perform insertion sort
void insertion_sort(int arr[], int size)
{
    int key, j;

    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

// function to display the sorted array
void display_sorted_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}