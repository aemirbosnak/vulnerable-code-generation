//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to find the maximum value in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to implement the greedy algorithm for the fractional knapsack problem
void fractionalKnapsack(int values[], int weights[], int capacity, int size) {
    int i, j, maxIndex = 0;
    float maxValue = values[0];
    float maxWeight = weights[0];

    // Iterate through the array to find the maximum value/weight ratio
    for (i = 1; i < size; i++) {
        if ((float)values[i] / weights[i] > maxValue / maxWeight) {
            maxValue = values[i];
            maxIndex = i;
        }
    }

    // Add the item with the maximum value/weight ratio to the knapsack
    if (weights[maxIndex] <= capacity) {
        capacity -= weights[maxIndex];
        printf("Item %d added to knapsack\n", maxIndex + 1);
    } else {
        printf("Item %d too heavy to add to knapsack\n", maxIndex + 1);
    }

    // Recursively add items until the knapsack is full
    if (capacity > 0) {
        for (i = 0; i < size; i++) {
            if (weights[i] <= capacity) {
                values[i] = (int)((float)values[i] / weights[i] * capacity);
                weights[i] = capacity;
                printf("Item %d added to knapsack\n", i + 1);
                capacity = 0;
                break;
            }
        }
    }
}

int main() {
    int values[MAX], weights[MAX], size;
    int capacity;

    // Prompt the user to enter the number of items
    printf("Enter the number of items: ");
    scanf("%d", &size);

    // Prompt the user to enter the values and weights of each item
    printf("Enter the values and weights of each item:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &values[i], &weights[i]);
    }

    // Prompt the user to enter the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Call the fractionalKnapsack function to implement the greedy algorithm
    fractionalKnapsack(values, weights, capacity, size);

    return 0;
}