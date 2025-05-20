//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_SIZE 10000

int max_sum_subarray(int arr[], int size) {
    int start = 0, end = 0, sum = arr[0], max_sum = arr[0];
    int temp_sum = 0;

    while (end < size) {
        // Add the next element to the subarray
        temp_sum += arr[end];
        end++;

        // If the sum becomes negative, we need to subtract the elements of the current window
        while (sum < temp_sum) {
            sum += arr[start];
            start++;
        }

        // Update the maximum sum if required
        max_sum = (sum > max_sum) ? sum : max_sum;
    }

    int i = start, j = start;
    // Move the starting index to get the longest subarray with the maximum sum
    while (i < end) {
        if (sum - arr[i] >= sum) {
            j = i;
            sum += arr[i];
            i++;
        } else {
            i++;
        }
    }

    // Initialize an array to store the subarray elements
    int subarray[MAX_SIZE / 2 + 1];
    int index = 0;

    // Fill the subarray with elements from the current window
    while (j > i) {
        subarray[index++] = arr[i];
        i++;
    }

    // Print the subarray with the maximum sum
    printf("Subarray with the maximum sum: [");
    for (int k = 0; k < index; k++) {
        if (k != 0) {
            printf(", ");
        }
        printf("%d", subarray[k]);
    }
    printf("]\nSum: %d\n", max_sum);

    return max_sum;
}

int main() {
    int arr[10] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = max_sum_subarray(arr, size);

    return 0;
}