//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int n, i, j, temp;
    int prices[MAX_SIZE];
    int weights[MAX_SIZE];
    float ratios[MAX_SIZE];
    float knapsack_capacity, total_value = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the knapsack capacity: ");
    scanf("%f", &knapsack_capacity);

    for (i = 0; i < n; i++) {
        printf("Enter the weight and price of item %d: ", i+1);
        scanf("%d %d", &weights[i], &prices[i]);
        ratios[i] = prices[i] / (float)weights[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (ratios[i] < ratios[j]) {
                temp = ratios[j];
                ratios[j] = ratios[i];
                ratios[i] = temp;

                temp = weights[j];
                weights[j] = weights[i];
                weights[i] = temp;

                temp = prices[j];
                prices[j] = prices[i];
                prices[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (knapsack_capacity >= weights[i]) {
            knapsack_capacity -= weights[i];
            total_value += prices[i];
        }
        else {
            total_value += knapsack_capacity * ratios[i];
            break;
        }
    }

    printf("The maximum value for the given knapsack capacity is %.2f", total_value);

    return 0;
}