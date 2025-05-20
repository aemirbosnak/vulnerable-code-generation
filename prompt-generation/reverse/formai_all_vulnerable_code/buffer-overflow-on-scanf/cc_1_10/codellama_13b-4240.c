//Code Llama-13B DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
/*
 * A unique C Greedy Algorithms example program in an innovative style
 *
 * This program solves the "Maximum Sum of Non-Overlapping Subarrays" problem using a Greedy Algorithm.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m; // number of elements in the array and number of non-overlapping subarrays
    int a[n]; // input array
    int max_sum = 0; // maximum sum of non-overlapping subarrays
    int start_idx = 0; // starting index of the current subarray
    int end_idx = 0; // ending index of the current subarray
    int current_sum = 0; // sum of the current subarray

    // read input array
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // read number of non-overlapping subarrays
    scanf("%d", &m);

    // sort the input array in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // compute the sum of each non-overlapping subarray
    for (int i = 0; i < m; i++) {
        current_sum = 0;
        for (int j = start_idx; j <= end_idx; j++) {
            current_sum += a[j];
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
        start_idx++;
        end_idx++;
    }

    // print the maximum sum
    printf("%d\n", max_sum);

    return 0;
}