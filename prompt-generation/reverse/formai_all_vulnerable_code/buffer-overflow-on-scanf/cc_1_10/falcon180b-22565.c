//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i, j;
    int sum = 0;
    int max_sum = 0;
    int start = 0;
    int end = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    max_sum = sum;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (i == j) {
                continue;
            }

            int new_sum = sum - arr[i] - arr[j];
            if (new_sum > max_sum) {
                max_sum = new_sum;
                start = i;
                end = j;
            }
        }
    }

    printf("The maximum sum of non-adjacent elements is %d\n", max_sum);
    printf("The subarray with non-adjacent elements is [");
    for (i = start; i <= end; i++) {
        if (i!= start) {
            printf(", ");
        }
        printf("%d", arr[i]);
    }
    printf("]\n");

    return 0;
}