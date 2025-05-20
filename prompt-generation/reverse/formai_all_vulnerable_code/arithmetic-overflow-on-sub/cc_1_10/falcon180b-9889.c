//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int weight;
} Item;

int main() {
    int n, capacity, i, j, max_value, total_value = 0;
    Item items[MAX_SIZE];

    // Read the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Read the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Read the items
    for (i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d:\n", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        total_value += items[i].value;
    }

    // Sort the items in decreasing order of value/weight ratio
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (items[i].value / items[i].weight < items[j].value / items[j].weight) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Initialize the maximum value and the knapsack capacity
    max_value = items[0].value;
    capacity = items[0].weight;

    // Apply the greedy algorithm
    for (i = 1; i < n; i++) {
        if (capacity >= items[i].weight && items[i].value / items[i].weight >= max_value) {
            max_value = items[i].value;
            capacity -= items[i].weight;
        }
    }

    // Print the result
    printf("The maximum value that can be obtained is %d.\n", max_value);

    return 0;
}