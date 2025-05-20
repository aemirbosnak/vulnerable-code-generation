//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    float value;
    float weight;
    float ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->ratio > item1->ratio) - (item2->ratio < item1->ratio);
}

void fractionalKnapsack(int n, float capacity, Item items[]) {
    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (capacity <= 0) {
            break;
        }

        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Taking the whole item %d (Value: %.2f, Weight: %.2f)\n", items[i].index + 1, items[i].value, items[i].weight);
        } else {
            float fraction = capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Taking %.2f of item %d (Value: %.2f, Weight: %.2f)\n", fraction, items[i].index + 1, items[i].value * fraction, capacity);
            capacity = 0;  // Knapsack is now full
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", totalValue);
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item *items = (Item *)malloc(n * sizeof(Item));

    printf("Enter the capacity of the Knapsack: ");
    scanf("%f", &capacity);

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%f %f", &items[i].value, &items[i].weight);
        items[i].index = i;
        items[i].ratio = items[i].value / items[i].weight;
    }

    fractionalKnapsack(n, capacity, items);
    free(items);
    
    return 0;
}