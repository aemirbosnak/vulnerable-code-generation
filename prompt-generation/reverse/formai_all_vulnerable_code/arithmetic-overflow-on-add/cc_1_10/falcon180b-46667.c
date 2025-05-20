//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int weight;
} Item;

int knapSack(Item items[], int n, int capacity) {
    int i, j, w, value = 0;
    int **dp = (int **)malloc(sizeof(int *) * (n + 1));
    for (i = 0; i <= n; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (capacity + 1));
        for (j = 0; j <= capacity; j++) {
            dp[i][j] = 0;
        }
    }
    for (i = 0; i <= n; i++) {
        if (items[i].weight <= capacity) {
            dp[i][items[i].weight] = items[i].value;
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= capacity; j++) {
            if (dp[i][j] > dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (i = n; i >= 0; i--) {
        if (dp[i][capacity] > value) {
            value = dp[i][capacity];
        }
    }
    for (i = n - 1, j = capacity; i >= 0 && j >= 0; i--, j--) {
        if (dp[i][j] == dp[i + 1][j]) {
            continue;
        } else if (dp[i][j] > dp[i + 1][j]) {
            break;
        } else {
            value += items[i].value;
            capacity -= items[i].weight;
        }
    }
    free(dp[0]);
    free(dp);
    return value;
}

int main() {
    int n, i, j, capacity;
    Item items[MAX_SIZE];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the items:\n");
    for (i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int totalValue = knapSack(items, n, capacity);

    printf("The maximum value that can be obtained is: %d\n", totalValue);

    return 0;
}