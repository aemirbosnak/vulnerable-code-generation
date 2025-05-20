//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

typedef struct {
    int weight;
    int value;
} item;

int cmp(const void *a, const void *b) {
    item *i1 = (item *)a;
    item *i2 = (item *)b;
    float v1 = (float)i1->value / (float)i1->weight;
    float v2 = (float)i2->value / (float)i2->weight;
    return v2 > v1 ? 1 : -1;
}

int main() {
    int n, W, i, totalValue = 0, totalWeight = 0;
    item items[MAX_ITEMS];
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    
    // Taking the information about the items
    for(i=0; i<n; i++) {
        printf("Enter the weight and value of item #%d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    
    // Sorting the items based on their value-to-weight ratio
    qsort(items, n, sizeof(item), cmp);
    
    // Adding items to the knapsack until it's full
    for(i=0; i<n && totalWeight< W; i++) {
        if(items[i].weight <= W - totalWeight) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else {
            totalValue += (W - totalWeight) * (float)items[i].value / (float)items[i].weight;
            totalWeight = W;
        }
    }
    
    printf("\nTotal weight of items in the knapsack: %d\n", totalWeight);
    printf("Total value of items in the knapsack: %d\n", totalValue);
    
    return 0;
}