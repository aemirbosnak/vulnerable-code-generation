//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>

// Function to sort an array in ascending order
void sortArray(int arr[], int n)
{
    // Loop through the array
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in the remaining unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to take input from the user
void takeInput(int arr[], int n)
{
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

// Main function
int main()
{
    int arr[100], n;

    // Take input from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Take input from the user
    takeInput(arr, n);

    // Sort the array
    sortArray(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}