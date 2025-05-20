//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i, j, k;
    bool isGreedy[MAX_SIZE];
    int sum = 0;
    int maxSum = 0;
    int index = 0;
    int start = 0;
    int end = 0;
    int current = 0;

    // Input array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize the isGreedy array
    for (i = 0; i < n; i++) {
        isGreedy[i] = false;
    }

    // Initialize the sum and maxSum
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    maxSum = sum;

    // Initialize the start and end indices
    start = 0;
    end = 0;

    // Greedy algorithm
    while (end < n) {
        if (isGreedy[end]) {
            end++;
        } else {
            for (j = start; j <= end; j++) {
                if (!isGreedy[j] && arr[j] > arr[end]) {
                    current = j;
                }
            }

            if (current!= 0) {
                isGreedy[current] = true;
                isGreedy[end] = true;
                sum -= arr[current];
                sum += arr[end];
                if (sum > maxSum) {
                    maxSum = sum;
                    index = end;
                }
                end++;
            } else {
                end++;
            }
        }
    }

    // Print the results
    printf("The maximum sum is %d and the elements are:", maxSum);
    for (i = start; i <= index; i++) {
        printf(" %d", arr[i]);
    }

    return 0;
}