//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// function to sort the items in decreasing order of their value/weight ratio
void sortItems(float* values, float* weights, int numItems) {
    int i, j;
    float temp;
    for (i = 0; i < numItems; i++) {
        for (j = i+1; j < numItems; j++) {
            if (values[i]/weights[i] < values[j]/weights[j]) {
                // swap items
                temp = values[i]; values[i] = values[j]; values[j] = temp;
                temp = weights[i]; weights[i] = weights[j]; weights[j] = temp;
            }
        }
    }
}

// function to calculate maximum value that can be obtained with the given capacity
float getMaxValue(float* values, float* weights, int capacity, int numItems) {
    float totalValue = 0, weight = 0;
    int i;
    
    // sort the items in decreasing order of their value/weight ratio
    sortItems(values, weights, numItems);
    
    // add items until the knapsack is full
    for (i = 0; i < numItems; i++) {
        if (weight + weights[i] <= capacity) {
            weight += weights[i];
            totalValue += values[i];
        }
        else {
            totalValue += (capacity - weight) * values[i] / weights[i];
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int numItems, capacity, i;
    float* values, *weights;
    
    // get input from user
    printf("Enter number of items: ");
    scanf("%d", &numItems);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    
    // allocate memory for values and weights arrays
    values = (float*) malloc(numItems * sizeof(float));
    weights = (float*) malloc(numItems * sizeof(float));
    
    // get values and weights from user
    for (i = 0; i < numItems; i++) {
        printf("Enter value and weight of item %d: ", i+1);
        scanf("%f %f", &values[i], &weights[i]);
    }
    
    // calculate maximum value that can be obtained with the given capacity
    float maxValue = getMaxValue(values, weights, capacity, numItems);
    
    // print the result
    printf("Maximum value that can be obtained is: %f\n", maxValue);
    
    // free memory
    free(values);
    free(weights);
    
    return 0;
}