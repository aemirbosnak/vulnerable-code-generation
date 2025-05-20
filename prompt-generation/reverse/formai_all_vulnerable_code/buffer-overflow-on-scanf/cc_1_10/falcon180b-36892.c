//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 100000

int main() {
    int n, i, j;
    int *arr;
    int sum = 0;
    int max_sum = 0;
    int start = 0;
    int end = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > max_sum) {
            max_sum = sum;
            start = i;
        }
        if (sum < 0) {
            sum = 0;
            end = i + 1;
        }
    }

    if (max_sum == 0) {
        printf("No subarray found\n");
    } else {
        printf("Maximum sum subarray is: ");
        for (i = start; i <= end - 1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nMaximum sum: %d\n", max_sum);
    }

    free(arr);

    return 0;
}