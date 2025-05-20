//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, i, j, k, sum, max_sum = 0;
    int *items, *weights, *values;

    /* Initialize random seed */
    srand(time(NULL));

    /* Get number of items from user */
    printf("Enter the number of items: ");
    scanf("%d", &n);

    /* Dynamically allocate memory for items, weights and values arrays */
    items = (int *)malloc(n * sizeof(int));
    weights = (int *)malloc(n * sizeof(int));
    values = (int *)malloc(n * sizeof(int));

    /* Get items and weights from user */
    printf("Enter %d items and their corresponding weights:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i], &weights[i]);
    }

    /* Initialize maximum sum to zero */
    max_sum = 0;

    /* Sort the items in decreasing order of their values/weights ratio */
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((double)values[i] / weights[i] > (double)values[j] / weights[j]) {
                int temp = items[i];
                items[i] = items[j];
                items[j] = temp;
                int temp2 = weights[i];
                weights[i] = weights[j];
                weights[j] = temp2;
                int temp3 = values[i];
                values[i] = values[j];
                values[j] = temp3;
            }
        }
    }

    /* Apply greedy algorithm to find the maximum sum of items */
    for (i = 0; i < n; i++) {
        if (weights[i] <= m) {
            m -= weights[i];
            sum += values[i];
        }
    }

    /* Display the maximum sum */
    printf("The maximum sum of items is: %d\n", sum);

    /* Free dynamically allocated memory */
    free(items);
    free(weights);
    free(values);

    return 0;
}