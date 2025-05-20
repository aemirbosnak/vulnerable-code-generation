//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    float ratio; // value/weight ratio
} Item;

void calculate_ratio(Item* items, int n) {
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
}

int compare_items(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1; // Sort in descending order
}

float knapsack(int W, Item* items, int n) {
    qsort(items, n, sizeof(Item), compare_items); // Sort items by value/weight ratio
    
    float totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) { // If the item can be fully included
            W -= items[i].weight;
            totalValue += items[i].value;
            printf("Included item %d: Value = %d, Weight = %d\n", i, items[i].value, items[i].weight);
        } else { // Take the fractional part of the item
            totalValue += items[i].ratio * W;
            printf("Included fractional part of item %d: Value = %.2f, Weight = %d\n", 
                    i, items[i].ratio * W, W);
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item* items = (Item*)malloc(n * sizeof(Item));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    calculate_ratio(items, n);
    float maxValue = knapsack(W, items, n);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    free(items); // Free allocated memory
    return 0;
}