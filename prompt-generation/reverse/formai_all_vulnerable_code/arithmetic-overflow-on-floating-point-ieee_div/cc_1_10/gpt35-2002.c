//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>

#define MAX 100

int main() {
    int n, weight[MAX], value[MAX], capacity, i, j, temp;
    float ratio[MAX], profit = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &weight[i], &value[i]);
        ratio[i] = (float)value[i] / weight[i];
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = value[j];
                value[j] = value[i];
                value[i] = temp;
            }
        }
    }

    printf("Items selected by Greedy Algorithm:\n");

    for (i = 0; i < n; i++) {
        if (weight[i] > capacity)
            break;

        printf("%d. Weight = %d, Value = %d\n", i+1, weight[i], value[i]);
        profit += value[i];
        capacity -= weight[i];
    }

    if (i < n) {
        profit += ratio[i] * capacity;
        printf("%d. Weight = %d, Value = %f\n", i+1, capacity, ratio[i]*capacity);
    }

    printf("Total profit: %f\n", profit);

    return 0;
}