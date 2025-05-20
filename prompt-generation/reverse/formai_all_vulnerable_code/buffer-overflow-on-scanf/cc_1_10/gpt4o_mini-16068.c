//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    double ratio; // value-to-weight ratio for comparing items
} Item;

void calculateRatio(Item* items, int n) {
    for (int i = 0; i < n; i++) {
        if (items[i].weight != 0) {
            items[i].ratio = (double)items[i].value / items[i].weight;
        } else {
            items[i].ratio = 0; // Avoid division by zero
        }
    }
}

int compare(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1; // Descending order
}

double greedyKnapsack(int capacity, Item* items, int n) {
    qsort(items, n, sizeof(Item), compare); // Sort items by the value-to-weight ratio
    double totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break; // Stop if there's no capacity left
        }

        if (items[i].weight <= capacity) {
            // If the item can fit completely into the knapsack
            totalValue += items[i].value;
            capacity -= items[i].weight;
            printf("Taking full item: value = %d, weight = %d\n", items[i].value, items[i].weight);
        } else {
            // Take the fraction of the last item that fits
            totalValue += items[i].ratio * capacity;
            printf("Taking fraction of item: value = %d, weight = %d, taking %.2f\n", items[i].value, items[i].weight, (double)capacity * items[i].ratio);
            capacity = 0; // Now the knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);
    
    Item* items = malloc(n * sizeof(Item));
    if (!items) {
        printf("Memory allocation failed!\n");
        return 1; // Return with an error code
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    calculateRatio(items, n);
    double maxValue = greedyKnapsack(capacity, items, n);

    printf("Maximum value we can obtain: %.2f\n", maxValue);

    free(items); // Don't forget to free allocated memory
    return 0;
}