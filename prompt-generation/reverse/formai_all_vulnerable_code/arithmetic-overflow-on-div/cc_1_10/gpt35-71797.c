//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#define MAX 100

int main() {
    int n, i, j, temp;
    int weight[MAX], profit[MAX], ratio[MAX];
    float capacity, total_profit;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and profit of each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    total_profit = 0;
    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            total_profit += profit[i];
        } else {
            total_profit += (ratio[i] * capacity);
            capacity = 0;
            break;
        }
    }

    printf("Maximum possible profit = %.2f", total_profit);

    return 0;
}