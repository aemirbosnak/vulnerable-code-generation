//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

int main() {
    int n, i, j, k;
    int *values;
    int *selected;
    int sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    values = (int*)malloc(n * sizeof(int));
    selected = (int*)malloc(n * sizeof(int));

    // Fill the array with random values
    for (i = 0; i < n; i++) {
        values[i] = rand() % MAX_SIZE;
    }

    // Sort the array in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (values[i] < values[j]) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }

    // Initialize the selected array
    for (i = 0; i < n; i++) {
        selected[i] = 0;
    }

    // Greedy algorithm to find the maximum sum
    for (i = 0; i < n; i++) {
        int max_sum = 0;
        for (j = i; j < n; j++) {
            int sum_so_far = 0;
            for (k = i; k <= j; k++) {
                sum_so_far += values[k];
            }
            if (sum_so_far > max_sum) {
                max_sum = sum_so_far;
            }
        }
        sum += max_sum;
        selected[i] = 1;
    }

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", values[i]);
    }
    printf("\nSelected array: ");
    for (i = 0; i < n; i++) {
        if (selected[i]) {
            printf("%d ", values[i]);
        }
    }
    printf("\nMaximum sum: %d", sum);

    free(values);
    free(selected);

    return 0;
}