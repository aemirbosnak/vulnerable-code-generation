//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

// Structure to represent items
struct Item {
    int value;
    int weight;
};

// Function to compare two items based on their value-to-weight ratio
int compare_items(const void* a, const void* b) {
    double ratio_a = ((struct Item*)a)->value / (double)((struct Item*)a)->weight;
    double ratio_b = ((struct Item*)b)->value / (double)((struct Item*)b)->weight;
    return ratio_b > ratio_a ? 1 : -1;
}

int main() {
    struct Item items[MAX_ITEMS];
    int n, capacity, i;
    
    // Get the number of items and the capacity of the knapsack from the user
    printf("Enter the number of items and the capacity of the knapsack: ");
    scanf("%d %d", &n, &capacity);
    
    // Get the value and weight of each item from the user
    for (i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Sort the items in decreasing order of their value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare_items);

    // Fill the knapsack with the items in the sorted order
    int current_weight = 0;
    double total_value = 0.0;
    for (i = 0; i < n && current_weight < capacity; i++) {
        int remaining_capacity = capacity - current_weight;
        int weight = items[i].weight > remaining_capacity ? remaining_capacity : items[i].weight; // Take as much as possible of item i
        current_weight += weight;
        total_value += weight * (items[i].value / (double)items[i].weight); // Add the value of the taken part of item i
    }

    // Print the total value of the items in the knapsack
    printf("The maximum total value of the items in the knapsack is: %.2f\n", total_value);

    return 0;
}