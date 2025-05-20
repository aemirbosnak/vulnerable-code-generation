//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int value;
    int weight;
} Item;

int compare(const void *a, const void *b) {
    double ratio1 = (double)((Item*)a)->value / ((Item*)a)->weight;
    double ratio2 = (double)((Item*)b)->value / ((Item*)b)->weight;
    
    if (ratio1 < ratio2) return 1;
    else if (ratio1 > ratio2) return -1;
    return 0;
}

void fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    printf("Selected items for the fractional knapsack:\n");

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item ID: %d, Weight: %d, Value: %d\n", items[i].id, items[i].weight, items[i].value);
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            printf("Item ID: %d, Weight: %d (fraction used), Value: %d (fraction used)\n", 
                   items[i].id, remainingWeight, (int)(items[i].value * ((double)remainingWeight / items[i].weight)));
            break;
        }
    }

    printf("Total value in the knapsack: %f\n", totalValue);
}

int main() {
    int capacity, n;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].id = i + 1;
    }

    fractionalKnapsack(capacity, items, n);

    free(items);
    
    return 0;
}