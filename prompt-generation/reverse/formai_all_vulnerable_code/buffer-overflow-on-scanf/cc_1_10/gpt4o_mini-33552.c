//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    int weight;
    int value;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int totalItems;
} Knapsack;

void addItem(Knapsack *k, int weight, int value) {
    if (k->totalItems < MAX_ITEMS) {
        k->items[k->totalItems].weight = weight;
        k->items[k->totalItems].value = value;
        k->totalItems++;
    } else {
        printf("Cannot add more items to the knapsack!\n");
    }
}

void printItems(Knapsack k) {
    printf("Items in the knapsack:\n");
    for (int i = 0; i < k.totalItems; i++) {
        printf("Item %d -> Weight: %d, Value: %d\n", i + 1, k.items[i].weight, k.items[i].value);
    }
}

int compare(const void *a, const void *b) {
    double ratioA = (double)(((Item *)a)->value) / ((Item *)a)->weight;
    double ratioB = (double)(((Item *)b)->value) / ((Item *)b)->weight;

    if (ratioA < ratioB) return 1; // Sort in descending order
    if (ratioA > ratioB) return -1;
    return 0;
}

int greedyKnapsack(Knapsack k, int capacity) {
    qsort(k.items, k.totalItems, sizeof(Item), compare);

    int totalValue = 0;
    int currentWeight = 0;

    printf("Selected items in the greedy knapsack:\n");
    
    for (int i = 0; i < k.totalItems && currentWeight < capacity; i++) {
        if (currentWeight + k.items[i].weight <= capacity) {
            totalValue += k.items[i].value;
            currentWeight += k.items[i].weight;
            printf("Added Item %d -> Weight: %d, Value: %d\n", i + 1, k.items[i].weight, k.items[i].value);
        } else {
            printf("Cannot add Item %d -> Weight: %d, Value: %d (Exceeded capacity)\n", i + 1, k.items[i].weight, k.items[i].value);
        }
    }
    
    return totalValue;
}

int main() {
    Knapsack k = {{0}, 0};
    
    int capacity;
    
    printf("Welcome to the Magical Knapsack Adventure!\n");
    printf("Enter the maximum weight capacity of your knapsack: ");
    scanf("%d", &capacity);
    
    printf("Now, let's add some shiny items with their weights and values!\n");

    while (1) {
        int weight, value;
        printf("Enter the weight and value of the item (or -1 to finish): ");
        scanf("%d", &weight);
        
        if (weight == -1) break;

        printf("Enter the value of the item: ");
        scanf("%d", &value);
        
        addItem(&k, weight, value);
    }

    printItems(k);

    int maxProfit = greedyKnapsack(k, capacity);
    printf("The maximum profit is: %d\n", maxProfit);
    
    printf("Thank you for using the Magical Knapsack Adventure. May your treasures remain safe!\n");
    return 0;
}