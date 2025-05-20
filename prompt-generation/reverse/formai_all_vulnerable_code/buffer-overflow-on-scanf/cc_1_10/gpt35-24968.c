//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

// Node definition
struct node {
    int id;
    int weight;
    int value;
} nodes[MAX_NODES];

// Function to sort nodes in non-increasing order of value to weight ratio
int cmp(const void *a, const void *b) {
    struct node *na = (struct node *) a;
    struct node *nb = (struct node *) b;
    double ratio_a = ((double) na->value) / na->weight;
    double ratio_b = ((double) nb->value) / nb->weight;
    if (ratio_a < ratio_b) {
        return 1;
    } else if (ratio_a > ratio_b) {
        return -1;
    } else {
        return 0;
    }
}

// Function to run the greedy algorithm
int run_greedy(int n, int m, int knapsack_capacity, int *knapsack_items) {
    // Sort the nodes by non-increasing ratio of value to weight
    qsort(nodes, n, sizeof(struct node), cmp);

    // Initialize the knapsack
    int current_capacity = 0;
    for (int i = 0; i < m; i++) {
        knapsack_items[i] = 0;
    }

    // Add items to the knapsack until it is full or all items have been added
    int item_index = 0;
    while (item_index < n && current_capacity < knapsack_capacity) {
        struct node *node = &nodes[item_index];
        if (node->weight <= knapsack_capacity - current_capacity) {
            knapsack_items[node->id] = 1;
            current_capacity += node->weight;
        }
        item_index++;
    }

    // Return the total value of the knapsack
    int total_value = 0;
    for (int i = 0; i < n; i++) {
        if (knapsack_items[nodes[i].id]) {
            total_value += nodes[i].value;
        }
    }
    return total_value;
}

// Main function
int main() {
    // Read input
    int n, m, knapsack_capacity;
    scanf("%d %d %d", &n, &m, &knapsack_capacity);
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        scanf("%d %d", &nodes[i].value, &nodes[i].weight);
    }

    // Run the greedy algorithm
    int knapsack_items[MAX_NODES];
    int max_value = run_greedy(n, m, knapsack_capacity, knapsack_items);

    // Print the result
    printf("%d\n", max_value);
    for (int i = 0; i < m; i++) {
        printf("%d ", knapsack_items[i]);
    }
    printf("\n");

    return 0;
}