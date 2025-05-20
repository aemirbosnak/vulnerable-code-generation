//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>

/**
 * The main method where the program starts executing
 */
int main() {

    /**
     * Read the size of the array from the user
     */
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    /**
     * Declare the array
     */
    int array[size];

    /**
     * Read the elements of the array from the user
     */
    printf("Enter the %d elements of the array: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    /**
     * Sort the array using bubble sort
     */
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    /**
     * Calculate the maximum sum of consecutive subarray
     */
    int maxSum = array[0];
    int currentSum = array[0];
    for (int i = 1; i < size; i++) {
        currentSum = currentSum + array[i];
        if (array[i] > currentSum) {
            currentSum = array[i];
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    /**
     * Display the result to the user
     */
    printf("The maximum sum of consecutive subarray is: %d", maxSum);

    return 0;
}