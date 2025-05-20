//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    float ratio; // value/weight ratio
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1; // Sort in descending order
}

float knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);
    
    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item *items = (Item *)malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight; // Calculate the ratio
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    float maxProfit = knapsack(items, n, capacity);
    printf("Maximum value in the knapsack: %.2f\n", maxProfit);

    free(items);
    return 0;
}