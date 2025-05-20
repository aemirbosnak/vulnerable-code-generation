//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

typedef struct {
    int value;
    int weight;
} Item;

int main() {
    int n, i, j, k;
    Item items[MAX_ITEMS];
    int capacities[MAX_ITEMS];
    int max_capacity = 0;

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input the weight and value of each item
    for (i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        capacities[i] = items[i].weight;
        if (items[i].value > max_capacity) {
            max_capacity = items[i].value;
        }
    }

    // Sort the items by weight/value ratio
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (items[j].value / items[j].weight > items[i].value / items[i].weight) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
                capacities[i] = items[i].weight;
                capacities[j] = items[j].weight;
            }
        }
    }

    // Initialize the knapsack capacity
    int knapsack_capacity = max_capacity;

    // Greedy algorithm to fill the knapsack
    for (i = 0; i < n; i++) {
        if (knapsack_capacity >= items[i].weight) {
            knapsack_capacity -= items[i].weight;
            printf("Item %d added to knapsack\n", i+1);
        } else {
            break;
        }
    }

    // Print the items that were added to the knapsack
    printf("\nItems added to knapsack:\n");
    for (i = 0; i < n; i++) {
        if (capacities[i] == 0) {
            printf("Item %d\n", i+1);
        }
    }

    // Print the total value of items in the knapsack
    printf("\nTotal value of items in knapsack: %d\n", knapsack_capacity);

    return 0;
}