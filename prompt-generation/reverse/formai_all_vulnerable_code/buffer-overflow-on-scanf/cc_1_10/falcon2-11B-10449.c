//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: inquisitive
#include <stdio.h>

/* Bubble Sort Algorithm:
 * This algorithm repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
 * The pass through the list is repeated until no swaps are made, which indicates that the list is sorted.
 */
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/* Main Program */
int main()
{
    int n, i, j, temp;

    // Get the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for array
    int arr[n];

    // Get the array elements
    printf("Enter the elements of the array: ");
    for (i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call the bubbleSort function
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the number of swaps performed
    printf("Number of swaps performed: %d\n", n-1);

    return 0;
}