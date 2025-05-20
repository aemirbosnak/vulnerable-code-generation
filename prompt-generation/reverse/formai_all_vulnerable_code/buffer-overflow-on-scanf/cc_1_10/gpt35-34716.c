//FormAI DATASET v1.0 Category: Sorting ; Style: content
#include <stdio.h>

#define MAX_SIZE 10

void bubbleSort(int array[], int size);

int main()
{
    int arr[MAX_SIZE];
    int n, i;

    printf("Enter the number of elements to be sorted: \n");
    scanf("%d", &n);

    if (n > MAX_SIZE)
    {
        printf("Error: Maximum array size is %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements to be sorted: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bubbleSort(arr, n);

    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

void bubbleSort(int array[], int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}