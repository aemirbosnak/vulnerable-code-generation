//FormAI DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements in an array
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    int isSwapped;

    for(i = 0; i < n-1; i++)
    {
        isSwapped = 0;
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                isSwapped = 1;
            }
        }

        if(isSwapped == 0)
            break;
    }
}

// Main function to test the above sorting functions
int main()
{
    int i, n;
    int *arr;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    // Dynamic memory allocation for array
    arr = (int*) malloc(n * sizeof(int));

    // User input for array elements
    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Function call for bubble sort
    bubbleSort(arr, n);

    // Display sorted array
    printf("\nSorted Array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Deallocating memory allocated for array
    free(arr);

    return 0;
}