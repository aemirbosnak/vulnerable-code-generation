//Falcon-180B DATASET v1.0 Category: Sorting ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    else
        return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellSort(int arr[], int n)
{
    int gap, i, j;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && compare(&temp, &arr[j - gap]) < 0)
            {
                swap(&arr[j], &arr[j - gap]);
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[MAX_SIZE], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    shellSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}