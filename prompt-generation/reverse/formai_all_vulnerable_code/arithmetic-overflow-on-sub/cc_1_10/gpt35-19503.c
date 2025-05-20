//FormAI DATASET v1.0 Category: Sorting ; Style: protected
#include <stdio.h>
#include <stdlib.h>

/*
 * This program sorts an array of integers using bubble sort algorithm.
 * The program prompts the user to enter the number of integers to be sorted
 * and the integers themselves.
 * The program then sorts the integers in ascending order and prints them out.
 */

#define MAX_INTS 100

void bubbleSort(int* arr, int size);
void swap(int* a, int* b);

int main()
{
    int arr[MAX_INTS];
    int size;
    int i;

    printf("Enter the number of integers to be sorted: ");
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, size);

    printf("Sorted integers:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*
 * Sorts an array of integers using bubble sort algorithm.
 * The function takes in an array of integers and its size.
 * It modifies the original array.
 */
void bubbleSort(int* arr, int size)
{
    int i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/*
 * Swaps two integers.
 */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}