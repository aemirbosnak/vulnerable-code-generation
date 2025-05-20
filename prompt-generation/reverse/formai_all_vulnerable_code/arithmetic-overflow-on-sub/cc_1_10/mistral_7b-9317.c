//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_SIZE 10001

int max_subarray_sum(int arr[], int n, int k) {
    int i, j, sum_k, max_sum = INT_MIN;

    for (i = 0; i <= n - k; i++) {
        sum_k = 0;
        for (j = i; j < i + k; j++) {
            sum_k += arr[j];
        }
        if (sum_k > max_sum) {
            max_sum = sum_k;
        }
    }

    return max_sum;
}

int main() {
    int arr[MAX_SIZE], n, k, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the size of the subarray: ");
    scanf("%d", &k);

    int max_sum = max_subarray_sum(arr, n, k);

    printf("Maximum sum subarray of size %d is: ", k);
    for (i = 0; i < k; i++) {
        if (max_sum > (arr[i] + max_subarray_sum(arr + i + 1, n - i - 1, k - 1))) {
            int j;
            for (j = i; j < i + k; j++) {
                printf("%d ", arr[j]);
            }
            break;
        }
    }

    return 0;
}