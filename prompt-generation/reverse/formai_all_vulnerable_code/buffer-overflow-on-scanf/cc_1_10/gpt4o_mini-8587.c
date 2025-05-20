//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float value;
    float weight;
    float ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}

void knapsackGreedy(float capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);
    
    float totalValue = 0.0;
    float totalWeight = 0.0;

    printf("Item Selection for the Knapsack:\n");
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Selected Item ID: %d, Weight: %.2f, Value: %.2f\n", items[i].id, items[i].weight, items[i].value);
        } else {
            float remainingCapacity = capacity - totalWeight;
            if (remainingCapacity > 0) {
                totalValue += items[i].value * (remainingCapacity / items[i].weight);
                printf("Partially Selected Item ID: %d, Weight: %.2f, Value: %.2f\n", items[i].id, remainingCapacity, items[i].value * (remainingCapacity / items[i].weight));
            }
            break;
        }
    }

    printf("Total Weight: %.2f\n", totalWeight);
    printf("Total Value: %.2f\n", totalValue);
}

void initializeItems(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        items[i].weight = rand() % 10 + 1;  // Random weight between 1 to 10
        items[i].value = rand() % 100 + 1;  // Random value between 1 to 100
        items[i].ratio = items[i].value / items[i].weight; // Calculate value-to-weight ratio
    }
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    Item *items = (Item *)malloc(n * sizeof(Item));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }

    srand(time(0)); // Seed for random number generation
    initializeItems(items, n);

    printf("\nItems before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("Item ID: %d, Weight: %.2f, Value: %.2f, Ratio: %.2f\n", items[i].id, items[i].weight, items[i].value, items[i].ratio);
    }

    knapsackGreedy(capacity, items, n);

    free(items);
    return 0;
}