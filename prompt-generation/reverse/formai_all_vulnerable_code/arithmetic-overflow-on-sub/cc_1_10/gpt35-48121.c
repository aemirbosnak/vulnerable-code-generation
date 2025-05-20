//FormAI DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *arr, int size)
{
    int temp;
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                // Swapping elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    // Taking input size
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamic array allocation
    int *arr = (int *)malloc(size * sizeof(int));

    // Taking array input from user
    printf("Enter the array elements: ");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sorting the array using bubble sort
    bubble_sort(arr, size);

    // Displaying sorted array
    printf("The sorted array is: ");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    // Freeing up the memory
    free(arr);

    return 0;    
}