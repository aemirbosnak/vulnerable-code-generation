//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to find the optimal solution using a greedy algorithm
int* optimal_solution(int n, int m, int* profit, int* capacity) {
    int i, j;
    int* solution = (int*) malloc(n * sizeof(int));

    // Initialize solution array with 0s
    for (i = 0; i < n; i++) {
        solution[i] = 0;
    }

    // Sort the items in decreasing order of profit/weight ratio
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (profit[i] / capacity[i] < profit[j] / capacity[j]) {
                int temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
                int temp_cap = capacity[i];
                capacity[i] = capacity[j];
                capacity[j] = temp_cap;
            }
        }
    }

    // Find the optimal solution using a greedy algorithm
    for (i = 0; i < n; i++) {
        int max_capacity = capacity[i];
        int max_profit = profit[i];
        int max_index = i;
        for (j = i + 1; j < n; j++) {
            if (max_profit < profit[j]) {
                max_profit = profit[j];
                max_index = j;
            }
        }
        if (max_capacity > 0) {
            solution[i] = max_profit;
            capacity[max_index] -= max_capacity;
        }
    }

    return solution;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* profit = (int*) malloc(n * sizeof(int));
    int* capacity = (int*) malloc(n * sizeof(int));

    printf("Enter the profit and capacity of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &profit[i], &capacity[i]);
    }

    int* solution = optimal_solution(n, m, profit, capacity);

    printf("The optimal solution is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", solution[i]);
    }

    free(solution);
    free(profit);
    free(capacity);

    return 0;
}