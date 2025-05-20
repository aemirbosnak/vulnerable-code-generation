//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Function to find the optimal solution
int findOptimalSolution(int arr[], int n, int k, int sum)
{
    int i, j, max = 0;

    // Initialize the first element of the array as the maximum element
    arr[0] = max;

    // Initialize the first k elements of the array as the maximum element
    for (i = 0; i < k; i++)
        arr[i] = max;

    // Find the optimal solution
    for (i = k; i < n; i++)
    {
        // Initialize the maximum element for the current element
        max = 0;

        // Find the maximum element from the previous elements
        for (j = 0; j < k; j++)
        {
            if (arr[j] > max)
                max = arr[j];
        }

        // Update the current element with the maximum element
        arr[i] = max + arr[i - k];

        // Update the maximum element for the next elements
        if (arr[i] > max)
            max = arr[i];
    }

    // Find the sum of the array
    for (i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

// Function to generate a random array
void generateArray(int arr[], int n)
{
    int i;

    // Initialize the array with random elements
    for (i = 0; i < n; i++)
        arr[i] = rand() % MAX + 1;
}

// Function to print the array
void printArray(int arr[], int n)
{
    int i;

    // Print the array
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Function to run the program
int main()
{
    int n, k, sum;
    int arr[MAX];

    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Generate a random array
    generateArray(arr, n);

    // Print the original array
    printf("Original array:\n");
    printArray(arr, n);

    // Get the number of elements to be removed
    printf("Enter the number of elements to be removed: ");
    scanf("%d", &k);

    // Remove the k elements from the array
    sum = findOptimalSolution(arr, n, k, sum);

    // Print the modified array
    printf("Modified array:\n");
    printArray(arr, n);

    // Print the sum of the modified array
    printf("Sum of the modified array: %d\n", sum);

    return 0;
}