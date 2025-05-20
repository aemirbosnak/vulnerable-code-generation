//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>

#define MAX_ITEMS 100 // Maximum number of items
#define MAX_WEIGHT 1000 // Maximum weight of the knapsack

// Item structure
struct Item {
    int weight;
    int value;
};

// Function to compare items by value per weight ratio
int compare(const void* a, const void* b) {
    double ratio1 = ((struct Item *)a)->value / (double)((struct Item *)a)->weight;
    double ratio2 = ((struct Item *)b)->value / (double)((struct Item *)b)->weight;
    if (ratio1 < ratio2) return 1;
    if (ratio1 > ratio2) return -1;
    return 0;
}

// Greedy algorithm for the fractional knapsack problem
double fractional_knapsack(int n, struct Item *items, int capacity) {
    int i;
    double total_value = 0;
    qsort(items, n, sizeof(struct Item), compare); // Sort items in decreasing order of value per weight ratio
    for (i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) { // Take the whole item if it fits in the knapsack
            total_value += items[i].value;
            capacity -= items[i].weight;
        } else { // Take a fraction of the item otherwise
            total_value += capacity * (items[i].value / (double)items[i].weight);
            capacity = 0;
        }
    }
    return total_value;
}

// Main function
int main() {
    int n, i, capacity;
    struct Item items[MAX_ITEMS];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    double total_value = fractional_knapsack(n, items, capacity);
    printf("The maximum value that can be obtained is %.2f\n", total_value);
    return 0;
}