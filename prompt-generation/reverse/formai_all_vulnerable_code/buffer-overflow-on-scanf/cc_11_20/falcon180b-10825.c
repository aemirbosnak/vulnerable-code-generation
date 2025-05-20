//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n, i, j, count = 0;
    int *profit, *weight;
    int **include;
    int capacity = 50;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    profit = (int *)malloc(n * sizeof(int));
    weight = (int *)malloc(n * sizeof(int));
    include = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        printf("Enter the profit and weight of item %d: ", i+1);
        scanf("%d %d", &profit[i], &weight[i]);
    }

    for (i = 0; i < n; i++) {
        include[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
            include[i][j] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (weight[j] <= capacity - weight[i])
                include[i][j] = 1;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (include[i][j] == 1 && profit[j] > 0) {
                count++;
                break;
            }
        }
    }

    printf("The number of items in the knapsack is %d\n", count);

    for (i = 0; i < n; i++)
        free(include[i]);
    free(include);
    free(profit);
    free(weight);

    return 0;
}