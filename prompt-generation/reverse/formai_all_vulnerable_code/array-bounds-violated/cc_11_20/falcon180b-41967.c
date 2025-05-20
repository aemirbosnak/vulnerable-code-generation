//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

int main() {
    int n, i, j, k, max, pos, val;
    int arr[MAX];
    int count[MAX];
    int sum[MAX];
    int result[MAX];
    int min_diff = 9999;
    int start_pos = 0;
    int end_pos = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the maximum knapsack capacity: ");
    scanf("%d", &max);

    for (i = 0; i < n; i++) {
        count[i] = 1;
        sum[i] = arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                count[i] = count[j] + 1;
                sum[i] = sum[j] + arr[i];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (sum[j] > sum[j + 1]) {
                val = sum[j];
                sum[j] = sum[j + 1];
                sum[j + 1] = val;

                count[j] = count[j + 1];
                count[j + 1] = count[j] + 1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (sum[i] <= max) {
            if (count[i] > 0) {
                if (min_diff > max - sum[i]) {
                    min_diff = max - sum[i];
                    start_pos = 0;
                    end_pos = i;
                }
            }
        }
    }

    printf("The minimum difference is %d\n", min_diff);

    printf("The items selected are: ");
    for (i = start_pos; i <= end_pos; i++) {
        printf("%d ", arr[i]);
        result[k++] = arr[i];
    }

    return 0;
}