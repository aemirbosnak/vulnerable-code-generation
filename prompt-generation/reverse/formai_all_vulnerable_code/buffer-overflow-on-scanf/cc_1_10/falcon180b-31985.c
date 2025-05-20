//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 100

int main() {
    int n, i, j, index, max_sum = 0, sum = 0, value, choice;
    int *arr;

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter your choice:\n1. Maximum Subarray\n2. Fractional Knapsack\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            max_sum = arr[0];
            for (i = 1; i < n; i++) {
                sum += arr[i];
                if (sum > max_sum) {
                    max_sum = sum;
                }
                if (sum < 0) {
                    sum = 0;
                }
            }
            printf("Maximum Subarray sum is: %d\n", max_sum);
            break;
        case 2:
            printf("Enter the capacity of the knapsack: ");
            scanf("%d", &value);

            max_sum = 0;
            for (i = 0; i < n; i++) {
                if (arr[i] <= value) {
                    max_sum += arr[i];
                }
            }

            printf("Maximum value that can be obtained is: %d\n", max_sum);
            break;
        default:
            printf("Invalid choice\n");
    }

    free(arr);

    return 0;
}