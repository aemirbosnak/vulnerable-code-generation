//Gemma-7B DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, key, temp, flag = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
    }

    if (flag == 0)
    {
        printf("The array is already sorted in ascending order.\n");
    }
    else
    {
        printf("The array is sorted in ascending order.\n");
        printf("The sorted array is: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    // Free the memory allocated for the array
    free(arr);

    return 0;
}