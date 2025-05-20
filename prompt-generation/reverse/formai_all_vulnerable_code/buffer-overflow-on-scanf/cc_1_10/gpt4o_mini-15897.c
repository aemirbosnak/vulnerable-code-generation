//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;  // Value or profit of the item
    int weight; // Weight of the item
} Item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void* a, const void* b) {
    double r1 = ((Item*)a)->value / (double)((Item*)a)->weight;
    double r2 = ((Item*)b)->value / (double)((Item*)b)->weight;
    return (r1 < r2) - (r1 > r2); // Returns -1, 0, or 1
}

// Greedy function to maximize the value for a given weight capacity
void knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare); // Sort items by value/weight ratio

    double totalValue = 0.0;  // Total value accumulated
    int currentWeight = 0;     // Current weight in the knapsack

    printf("Items selected (value, weight):\n");
    for (int i = n - 1; i >= 0; i--) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;      // Add full item
            totalValue += items[i].value;          // Add full value
            printf("Item: (%d, %d)\n", items[i].value, items[i].weight);
        } else {
            int remainingWeight = capacity - currentWeight; // Remaining capacity
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight); // Add fraction
            printf("Item: (%d, %d) -> Added Fractional\n", items[i].value, remainingWeight);
            break; // Can't add more items after this
        }
    }

    printf("Total value in knapsack: %.2f\n", totalValue);
}

int main() {
    int n;
    int capacity;

    printf("Welcome to the Magical Knapsack Adventure!\n");
    printf("How many treasures (items) do you have? ");
    scanf("%d", &n);

    Item* items = (Item*)malloc(n * sizeof(Item)); // Dynamic allocation

    printf("Now, let’s enter the details of each treasure:\n");
    for (int i = 0; i < n; i++) {
        printf("Treasure %d - Enter its value and weight (e.g., 50 10): ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("What is the maximum carrying capacity of your magic knapsack? ");
    scanf("%d", &capacity);

    knapsack(items, n, capacity); // Run the greedy algorithm

    free(items); // Free allocated memory
    printf("Thank you for playing! May your adventures be plentiful!\n");
    return 0;
}