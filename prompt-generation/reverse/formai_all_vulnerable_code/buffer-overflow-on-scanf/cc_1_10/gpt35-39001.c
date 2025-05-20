//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int maxSum(int arr[], int size, int k)
{
    if (k > size)
        return -1; // Invalid input

    // Sort the array in descending order
    for (int i = 0; i < size - 1; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[max_index])
                max_index = j;
        }
        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }

    // Find the sum of first k elements
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];

    return sum;
}

int main()
{
    int arr[MAX_SIZE];
    int size, k;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE)
    {
        printf("Size of the array is too large!\n");
        exit(0);
    }

    printf("Enter %d elements of the array: ", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Array before rearrangement: ");
    printArray(arr, size);

    int max_sum = maxSum(arr, size, k);

    if (max_sum == -1)
        printf("Invalid input!\n");
    else
        printf("Maximum sum of first %d elements is: %d\n", k, max_sum);

    printf("Array after rearrangement: ");
    printArray(arr, size);

    return 0;
}