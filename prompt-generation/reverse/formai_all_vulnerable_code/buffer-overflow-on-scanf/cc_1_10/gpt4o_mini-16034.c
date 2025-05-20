//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void *a, const void *b) {
    double r1 = (double)((Item *)a)->value / (double)((Item *)a)->weight;
    double r2 = (double)((Item *)b)->value / (double)((Item *)b)->weight;
    return r1 < r2 ? 1 : -1; // Descending order
}

void knapsackGreedy(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);
    
    int totalValue = 0;
    int totalWeight = 0;
    
    printf("Selected items are:\n");
    
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: Weight = %d, Value = %d\n", i, items[i].weight, items[i].value);
        } else {
            double fraction = (double)(capacity - totalWeight) / (double)items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Item %d: Weight = %d, Value = %d (fraction = %.2f)\n", i, items[i].weight, items[i].value, fraction);
            break;  // No more items can be added
        }
    }
    
    printf("Total Weight: %d\n", totalWeight);
    printf("Total Value: %d\n", totalValue);
}

int main() {
    int n, capacity;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item *items = (Item *)malloc(n * sizeof(Item));
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    
    knapsackGreedy(items, n, capacity);
    
    free(items); // Avoid memory leak
    return 0;
}