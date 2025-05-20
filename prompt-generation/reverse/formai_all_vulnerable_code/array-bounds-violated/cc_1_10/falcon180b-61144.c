//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[SIZE];

    // Populating the array with random values
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;
    }

    // Sorting the array using bitonic sort
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        for (int j = SIZE - 2; j >= i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    // Printing the sorted array
    printf("Sorted array: ");
    printArray(arr, SIZE);

    // Reversing the array using bitwise operations
    for (int i = 0; i < SIZE / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[SIZE - i - 1];
        arr[SIZE - i - 1] = temp;
    }

    // Printing the reversed array
    printf("\nReversed array: ");
    printArray(arr, SIZE);

    return 0;
}