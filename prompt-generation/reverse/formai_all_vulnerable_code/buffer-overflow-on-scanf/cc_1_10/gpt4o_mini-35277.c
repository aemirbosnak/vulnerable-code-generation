//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio;  // value-to-weight ratio
} Item;

void calculateRatio(Item *items, int n) {
    for(int i = 0; i < n; i++) {
        items[i].ratio = (float)(items[i].value) / items[i].weight;
    }
}

int compare(const void *a, const void *b) {
    if (((Item *)b)->ratio > ((Item *)a)->ratio) {
        return 1;
    } else if (((Item *)b)->ratio < ((Item *)a)->ratio) {
        return -1;
    }
    return 0;
}

float greedyKnapsack(Item *items, int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0.0;
    int remainingCapacity = capacity;

    for(int i = 0; i < n; i++) {
        if (remainingCapacity <= 0) break;  // Knapsack is full
        if (items[i].weight <= remainingCapacity) {
            // Take the whole item
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
            printf("Took entire item with weight %d and value %d\n", items[i].weight, items[i].value);
        } else {
            // Take the fraction of the item
            totalValue += items[i].ratio * remainingCapacity;
            printf("Took %0.2f fraction of item with weight %d and value %d\n", (float)remainingCapacity / items[i].weight, items[i].value);
            remainingCapacity = 0;  // Knapsack is now full
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    printf("Number of items: ");
    scanf("%d", &n);
    
    Item *items = (Item *)malloc(n * sizeof(Item));
    
    for(int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d (space separated): ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    
    calculateRatio(items, n);
    
    float maxValue = greedyKnapsack(items, n, capacity);
    
    printf("Maximum value we can obtain: %0.2f\n", maxValue);
    
    free(items);
    return 0;
}