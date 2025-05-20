//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Function to return maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int *values = (int*)malloc(n * sizeof(int));
    int *weights = (int*)malloc(n * sizeof(int));
    float *ratios = (float*)malloc(n * sizeof(float));

    printf("Enter the values and weights of %d items:\n", n);
    for(int i = 0; i < n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &values[i], &weights[i]);
        // Calculate the ratio of value to weight for each item
        ratios[i] = (float)values[i] / weights[i];
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort the items based on their value to weight ratio in descending order
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(ratios[i] < ratios[j]) {
                // swap values
                int tempValue = values[i];
                values[i] = values[j];
                values[j] = tempValue;
                // swap weights
                int tempWeight = weights[i];
                weights[i] = weights[j];
                weights[j] = tempWeight;
                // swap ratios
                float tempRatio = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = tempRatio;
            }
        }
    }

    // Calculate the maximum value that can be obtained using greedy algorithm
    int currentWeight = 0, maxValue = 0;
    for(int i = 0; i < n; i++) {
        if(currentWeight + weights[i] <= capacity) {
            currentWeight += weights[i];
            maxValue += values[i];
        }
        else {
            int remainingWeight = capacity - currentWeight;
            maxValue += remainingWeight * ratios[i];
            break;
        }
    }

    printf("Maximum value that can be obtained: %d\n", maxValue);

    free(values);
    free(weights);
    free(ratios);

    return 0;
}