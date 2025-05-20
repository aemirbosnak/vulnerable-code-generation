//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include<stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity);

int main() {
    float weight[20], profit[20], capacity;
    int n, i;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the weights of objects: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &weight[i]);
    }

    printf("Enter the profits of objects: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &profit[i]);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    knapsack(n, weight, profit, capacity);

    return 0;
}

void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], total_profit = 0.0, mass = 0.0, temp;
    int i, j;

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (profit[i] / weight[i] < profit[j] / weight[j]) {
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (mass + weight[i] <= capacity) {
            x[i] = 1.0;
            mass += weight[i];
            total_profit += profit[i];
        } else {
            x[i] = (capacity - mass) / weight[i];
            total_profit += (profit[i] * x[i]);
            mass += (weight[i] * x[i]);
            break;
        }
    }

    printf("The total profit is: %.2f\n", total_profit);
    printf("The weights in knapsack is: ");

    for (i = 0; i < n; i++) {
        if (x[i] == 1.0) {
            printf("%.2f\t", weight[i]);
        } else if (x[i] > 0.0 && x[i] < 1.0) {
            printf("%.2f\t", (x[i] * weight[i]));
        }
    }
}