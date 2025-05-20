//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Generate random integers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Greedy algorithm to find the maximum sum of non-adjacent elements
    int max_sum = 0;
    int curr_sum = 0;
    int last_index = -1;
    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            last_index = i;
        } else if (curr_sum < 0) {
            curr_sum = 0;
        }
    }

    // Print the maximum sum and the corresponding elements
    printf("The maximum sum of non-adjacent elements is: %d\n", max_sum);
    printf("The elements are: ");
    for (int i = last_index - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}