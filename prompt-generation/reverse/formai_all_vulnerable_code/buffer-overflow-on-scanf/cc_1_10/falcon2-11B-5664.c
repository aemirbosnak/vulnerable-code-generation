//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Bucket sort function
void bucketSort(int arr[], int n)
{
    // Create an array of buckets of size 10
    int buckets[10][10];

    // Iterate over the input array
    for (int i = 0; i < n; i++)
    {
        // Get the bucket index based on the value of the current element
        int bucketIndex = (arr[i] / 10) % 10;

        // Add the current element to the corresponding bucket
        buckets[bucketIndex][arr[i] % 10]++;
    }

    // Initialize variables
    int min = 0, max = 0;

    // Iterate over the buckets
    for (int i = 0; i < 10; i++)
    {
        // Get the minimum and maximum elements in the current bucket
        min = 0;
        max = 0;
        for (int j = 0; j < 10; j++)
        {
            // Update the minimum and maximum elements
            min = (min > buckets[i][j])? min : buckets[i][j];
            max = (max < buckets[i][j])? max : buckets[i][j];
        }

        // Merge the current bucket with the input array
        for (int j = 0; j < 10; j++)
        {
            // Add the elements from the current bucket to the input array
            arr[i * 10 + j] = max + j;
        }
    }
}

// Function to print the sorted array
void printArray(int arr[], int size)
{
    // Iterate over the input array
    for (int i = 0; i < size; i++)
    {
        // Print the current element
        printf("%d ", arr[i]);
    }

    // Print a new line
    printf("\n");
}

// Function to get user input
void getUserInput(int arr[], int n)
{
    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get the elements from the user
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Main function
int main()
{
    // Declare an array of integers
    int arr[100];

    // Get user input
    getUserInput(arr, 100);

    // Sort the array using bucket sort
    bucketSort(arr, 100);

    // Print the sorted array
    printArray(arr, 100);

    // Return 0 to indicate successful execution
    return 0;
}