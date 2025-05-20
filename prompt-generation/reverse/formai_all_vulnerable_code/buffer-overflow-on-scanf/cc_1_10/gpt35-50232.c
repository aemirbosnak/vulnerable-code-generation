//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: interoperable
#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > u) {
            break;
        } else {
            x[i] = 1.0;
            tp += profit[i];
            u -= weight[i];
        }
    }

    if (i < n) {
        x[i] = u / weight[i];
        tp += (x[i] * profit[i]);
    }

    printf("\nThe result vector is: ");
    for (i = 0; i < n; i++) {
        printf("%f\t", x[i]);
    }

    printf("\nMaximum profit is: %f\n", tp);
}

void main() {
    float weight[20], profit[20], capacity;
    int num, i, j;
    printf("Enter the number of objects: ");
    scanf("%d", &num);

    printf("Enter the weights of each object: ");
    for (i = 0; i < num; i++) {
        scanf("%f", &weight[i]);
    }

    printf("Enter the profits of each object: ");
    for (i = 0; i < num; i++) {
        scanf("%f", &profit[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            float wi = profit[i] / weight[i];
            float wj = profit[j] / weight[j];

            if (wi < wj) {
                float temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    knapsack(num, weight, profit, capacity);
}