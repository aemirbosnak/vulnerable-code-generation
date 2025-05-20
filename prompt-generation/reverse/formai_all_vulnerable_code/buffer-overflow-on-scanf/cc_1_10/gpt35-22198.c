//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100 // Maximum number of items that the knapsack can hold

// Structure to represent an item in the knapsack
struct Item {
    int value; // Value of the item
    int weight; // Weight of the item
};

// Function to read the input items from the user
void read_items(struct Item *items, int *num_items, int *knapsack_capacity) {
    printf("Enter the number of items: ");
    scanf("%d", num_items);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", knapsack_capacity);

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < *num_items; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
}

// Function to swap two items in the array
void swap(struct Item *items, int i, int j) {
    int temp_value = items[i].value;
    int temp_weight = items[i].weight;
    items[i].value = items[j].value;
    items[i].weight = items[j].weight;
    items[j].value = temp_value;
    items[j].weight = temp_weight;
}

// Function to sort the items in non-increasing order of value per unit weight
void sort_items(struct Item *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        int max_index = i;
        for (int j = i + 1; j < num_items; j++) {
            if ((double) items[j].value / items[j].weight > (double) items[max_index].value / items[max_index].weight) {
                max_index = j;
            }
        }
        swap(items, i, max_index);
    }
}

// Function to compute the optimal solution using a greedy approach
int knapsack(struct Item *items, int num_items, int knapsack_capacity) {
    sort_items(items, num_items);
    int knapsack_weight = 0;
    int knapsack_value = 0;
    for (int i = 0; i < num_items; i++) {
        if (knapsack_weight + items[i].weight <= knapsack_capacity) {
            knapsack_weight += items[i].weight;
            knapsack_value += items[i].value;
        } else {
            int remaining_capacity = knapsack_capacity - knapsack_weight;
            knapsack_value += (int) ((double) items[i].value / items[i].weight * remaining_capacity);
            break;
        }
    }
    return knapsack_value;
}

// Main function
int main() {
    struct Item items[MAX_ITEMS];
    int num_items, knapsack_capacity;
    read_items(items, &num_items, &knapsack_capacity);
    printf("Optimal solution: %d\n", knapsack(items, num_items, knapsack_capacity));
    return 0;
}