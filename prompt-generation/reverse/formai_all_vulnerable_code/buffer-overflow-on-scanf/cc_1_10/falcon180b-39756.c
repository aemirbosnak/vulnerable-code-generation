//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 10000

int arr[MAX_SIZE];

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    int target = rand() % MAX_VALUE;
    int index = -1;

    printf("The target value is %d\n", target);

    int *result = (int *)malloc(sizeof(int));
    if (result == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    if (binary_search(arr, n, target, result)) {
        printf("The target value is found at index %d\n", *result);
    } else {
        printf("The target value is not found in the array\n");
    }

    free(result);
    return 0;
}

int binary_search(int arr[], int n, int target, int *result) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            *result = mid;
            return 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}