//FormAI DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
// The Case of the Sorted List

#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
void quickSort(int *arr, int start, int end);

int main()
{
    printf("The Case of the Sorted List\n");
    printf("------------------------------\n\n");

    // Enter the number of items to sort
    int n = 0;
    printf("How many items do you want to sort? ");
    scanf("%d", &n);

    // Allocate memory for the list
    int *list = malloc(n * sizeof(int));

    // Enter the items to sort
    printf("\nEnter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }

    // Sort the list
    quickSort(list, 0, n-1);

    // Display the sorted list
    printf("\nSorted list:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", list[i]);
    }

    // Free allocated memory
    free(list);

    return 0;
}

/* Quick sort algorithm */
void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = arr[end];
        int i = start - 1;

        for (int j = start; j <= end - 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = temp;

        int partition = i+1;

        quickSort(arr, start, partition-1);
        quickSort(arr, partition+1, end);
    }
}