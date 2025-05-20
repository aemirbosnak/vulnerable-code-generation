//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
};

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    double ratio1 = ((struct Item*)a)->value / (double)((struct Item*)a)->weight;
    double ratio2 = ((struct Item*)b)->value / (double)((struct Item*)b)->weight;
    
    if (ratio1 < ratio2) return 1;
    else if (ratio1 > ratio2) return -1;
    else return 0;
}

// Function to perform the greedy algorithm for the 0/1 knapsack problem
void knapsack(struct Item items[], int n, int capacity) {
    // Sort items based on value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare);
    
    int totalValue = 0; // Maximum value of knapsack
    int currentWeight = 0; // Current weight of knapsack

    printf("Selected items for the knapsack:\n");
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // If the item can be added to the knapsack
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
        }
    }

    printf("Total weight in knapsack: %d\n", currentWeight);
    printf("Total value obtained: %d\n", totalValue);
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item *items = (struct Item*) malloc(n * sizeof(struct Item));

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    knapsack(items, n, capacity);

    free(items);
    return 0;
}