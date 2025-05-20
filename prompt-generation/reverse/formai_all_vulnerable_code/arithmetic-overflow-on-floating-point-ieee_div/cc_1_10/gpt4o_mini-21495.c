//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item with value and weight
typedef struct Item {
    int id;
    int value;
    int weight;
    float ratio;  // Value-to-weight ratio
} Item;

// Comparison function for sorting items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->ratio > item1->ratio) - (item2->ratio < item1->ratio);
}

// Function to calculate maximum value in the knapsack
float fractionalKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);  // Sort items by value-to-weight ratio

    float totalValue = 0.0;  // Accumulate total value
    printf("Entering the mystical realm of treasures...\n");

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            // If the entire item can be taken
            capacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Item %d taken completely: Value = %d, Weight = %d\n", 
                   items[i].id, items[i].value, items[i].weight);
        } else {
            // Take the fraction of the item
            float fraction = (float)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Item %d taken partially: Value = %d, Weight = %d, Fraction = %.2f\n", 
                   items[i].id, items[i].value, items[i].weight, fraction);
            break;  // The knapsack is full
        }
    }

    printf("Total value of treasures collected: %.2f\n", totalValue);
    return totalValue;
}

int main() {
    // Journey setup: Number of treasures (items) and the mystical weight limit (capacity)
    int n, capacity;

    printf("Welcome, brave adventurer!\n");
    printf("Enter the number of treasures: ");
    scanf("%d", &n);
    printf("Enter the weight capacity of your magical knapsack: ");
    scanf("%d", &capacity);

    Item *items = malloc(n * sizeof(Item));  // Allocate memory for items

    // Initialize the treasures
    printf("Gathering treasures...\n");
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Enter value and weight for treasure %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;  // Calculate value-to-weight ratio
    }

    // Unfold the magic of the fractional knapsack algorithm
    fractionalKnapsack(items, n, capacity);

    // Free the allocated memory
    free(items);
    printf("Thank you for your adventure! Until we meet again...\n");
    return 0;
}