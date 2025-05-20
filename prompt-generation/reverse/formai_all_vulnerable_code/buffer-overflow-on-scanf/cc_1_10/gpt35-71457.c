//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

int main () {
    int n = 0;

    printf("Welcome to my awesome Greedy Algorithm program!\n");
    printf("Please enter the number of items you wish to consider: ");
    scanf("%d", &n);
    int values[n];
    int weights[n];
    float ratios[n];
    int capacity = 0;

    printf("Great! Now, let's enter some values and weights for each of these items:\n");

    for (int i = 0; i < n; i++) {
        printf("Item %d:\nValue: ", i+1);
        scanf("%d", &values[i]);
        printf("Weight: ");
        scanf("%d", &weights[i]);
        ratios[i] = (float)values[i]/weights[i];
    }

    printf("Fantastic! Now, please enter the capacity of your knapsack: ");
    scanf("%d", &capacity);

    qsort(ratios, n, sizeof(float), compare);

    int index = 0;
    float max_profit = 0;

    while (capacity > 0 && index < n) {
        int i = 0;

        while (ratios[i] != ratios[index]) {
            i++;
        }

        float quantity = (float)capacity / weights[i];

        if (capacity < weights[i]) {
            quantity = 1;
        }

        max_profit += quantity * values[i];
        capacity -= quantity * weights[i];
        index++;
    }

    printf("Amazing! We've found the maximum possible profit for your knapsack, which is: %.2f\n", max_profit);
    printf("Thanks for using my program!\n");

    return 0;
}