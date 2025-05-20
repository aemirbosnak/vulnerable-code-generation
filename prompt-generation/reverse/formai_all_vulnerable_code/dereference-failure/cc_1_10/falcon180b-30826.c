//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, max_sum = 0, curr_sum = 0, start_index = -1, end_index = -1;
    int *arr = NULL;

    // Take input from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for array
    arr = (int *)malloc(n * sizeof(int));

    // Take input elements from user
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize variables
    curr_sum = arr[0];
    start_index = 0;

    // Find maximum sum subarray
    for (i = 1; i < n; i++) {
        curr_sum += arr[i];
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            end_index = i;
        }
        if (curr_sum < 0) {
            curr_sum = arr[i];
            start_index = i;
        }
    }

    // Print the maximum sum subarray
    printf("The maximum sum subarray is: ");
    for (i = start_index; i <= end_index; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;
}