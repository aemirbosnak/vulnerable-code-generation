//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#define MAX_N 100 // maximum number of items

int main(void) {
    // declaring variables
    int n, w, i, j, maxprofit = 0;
    int weight[MAX_N], profit[MAX_N], selected[MAX_N];

    // getting input from user
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &w);
    printf("Enter the weight and profit of each item:\n");

    // loop for reading inputs
    for(i = 0; i < n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &weight[i], &profit[i]);
    }

    // initializing selected array with zeros
    for(i = 0; i < n; i++) {
        selected[i] = 0;
    }

    // greedy algorithm for the knapsack problem
    for(i = 1; i <= n; i++) {
        int maxindex = -1;
        double maxratio = -1.0;
        for(j = 0; j < n; j++) {
            if(selected[j] == 0) {
                double ratio = (double)profit[j] / weight[j];
                if(ratio > maxratio) {
                    maxratio = ratio;
                    maxindex = j;
                }
            }
        }
        selected[maxindex] = 1;
        if(weight[maxindex] <= w) {
            maxprofit += profit[maxindex];
            w -= weight[maxindex];
        } else {
            maxprofit += (int)(maxratio * w);
            break;
        }
    }

    // printing results
    printf("Selected items:\n");
    for(i = 0; i < n; i++) {
        if(selected[i]) {
            printf("Item %d - weight: %d, profit: %d\n", i+1, weight[i], profit[i]);
        }
    }
    printf("Maximum profit: %d\n", maxprofit);

    return 0;
}