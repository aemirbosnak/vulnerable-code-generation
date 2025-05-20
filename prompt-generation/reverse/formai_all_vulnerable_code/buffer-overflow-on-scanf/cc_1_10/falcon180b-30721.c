//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

int main() {
    int n, i, j, w[MAX_ITEMS], v[MAX_ITEMS], cw, cv, max_value, current_value;
    char input[50];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Read the weights and values of each item
    for (i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i+1);
        scanf("%d %d", &w[i], &v[i]);
    }

    // Sort the items in decreasing order of value-to-weight ratio
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if ((v[j]/w[j]) > (v[i]/w[i])) {
                cw = w[i];
                cv = v[i];
                w[i] = w[j];
                v[i] = v[j];
                w[j] = cw;
                v[j] = cv;
            }
        }
    }

    // Initialize the knapsack capacity and the current value
    cw = 0;
    cv = 0;

    // Fill the knapsack with items in decreasing order of value-to-weight ratio
    for (i = 0; i < n; i++) {
        if (cw + w[i] <= MAX_CAPACITY) {
            cw += w[i];
            cv += v[i];
        } else {
            break;
        }
    }

    // Print the maximum value that can be obtained from the knapsack
    max_value = cv;
    printf("\nThe maximum value that can be obtained from the knapsack is: %d\n", max_value);

    // Print the items that were selected for the knapsack
    printf("\nThe items that were selected for the knapsack are:\n");
    for (i = 0; i < n; i++) {
        if (cw + w[i] <= MAX_CAPACITY) {
            printf("Item %d with weight %d and value %d\n", i+1, w[i], v[i]);
            cw += w[i];
            cv += v[i];
        }
    }

    return 0;
}