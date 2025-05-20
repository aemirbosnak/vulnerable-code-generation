//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    int size = 0;
    int *arr = NULL;
    int *result = NULL;
    int max_sum = 0;
    int curr_sum = 0;
    int i;

    // Read in the size of the array
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    // Read in the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Allocate memory for the result array
    result = (int *)malloc(size * sizeof(int));
    if (result == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    // Initialize the result array with all 0s
    for (i = 0; i < size; i++) {
        result[i] = 0;
    }

    // Initialize the current sum to the first element
    curr_sum = arr[0];
    result[0] = curr_sum;

    // Compute the maximum sum and its ending index
    for (i = 1; i < size; i++) {
        // Update the current sum
        if (curr_sum < 0) {
            curr_sum = arr[i];
        } else {
            curr_sum += arr[i];
        }

        // Update the maximum sum and its ending index
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            result[i] = curr_sum;
        }
    }

    // Print out the result array
    printf("Result array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the memory for the arrays
    free(arr);
    free(result);

    return 0;
}