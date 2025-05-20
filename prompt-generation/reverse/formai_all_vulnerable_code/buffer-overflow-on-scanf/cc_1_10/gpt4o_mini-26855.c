//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    float ratio; // value to weight ratio
} Item;

// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->ratio > item1->ratio) - (item2->ratio < item1->ratio);
}

// Function to get the maximum value that can be put in knapsack
float fractionalKnapsack(Item items[], int n, int capacity) {
    // Sort items by their value to weight ratio
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0.0; // To store the total value
    for (int i = 0; i < n; i++) {
        if (capacity <= 0) { // If the knapsack is full
            break;
        }
        // If the item can be fit in the knapsack
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
            printf("Taking full item of value %d and weight %d\n", items[i].value, items[i].weight);
        } else { // Fraction of the item can be taken
            float fraction = (float)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Taking fraction of item of value %d and weight %d: %.2f\n", items[i].value, items[i].weight, fraction);
            capacity = 0; // The knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int capacity; // Total capacity of knapsack
    int n;       // Number of items

    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item *items = malloc(n * sizeof(Item)); // Dynamic memory allocation for items

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Input items' values and weights
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d%d", &items[i].value, &items[i].weight);
    }

    // Calculate maximum value that can be put in knapsack
    float maxValue = fractionalKnapsack(items, n, capacity);

    // Display the result
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    free(items); // Deallocate memory
    return 0;
}