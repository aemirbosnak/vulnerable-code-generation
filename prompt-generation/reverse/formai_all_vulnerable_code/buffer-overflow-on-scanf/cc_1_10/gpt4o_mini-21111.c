//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_ITEMS 100

typedef struct {
    int value;
    int weight;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} ItemList;

void initializeItemList(ItemList *list) {
    list->itemCount = 0;
}

void addItem(ItemList *list, int value, int weight) {
    if (list->itemCount < MAX_ITEMS) {
        list->items[list->itemCount].value = value;
        list->items[list->itemCount].weight = weight;
        list->itemCount++;
    } else {
        printf("Item list is full! Cannot add more items.\n");
    }
}

int compareItems(const void *a, const void *b) {
    double valuePerWeightA = (double)((Item *)a)->value / ((Item *)a)->weight;
    double valuePerWeightB = (double)((Item *)b)->value / ((Item *)b)->weight;
    
    return (valuePerWeightA < valuePerWeightB) - (valuePerWeightA > valuePerWeightB);
}

double knapsackGreedy(ItemList *list, int capacity) {
    qsort(list->items, list->itemCount, sizeof(Item), compareItems);
    
    double totalValue = 0.0;
    int i;
    for (i = list->itemCount - 1; i >= 0; i--) {
        if (capacity <= 0) {
            break;
        }
        
        if (list->items[i].weight <= capacity) {
            totalValue += list->items[i].value;
            capacity -= list->items[i].weight;
        } else {
            totalValue += list->items[i].value * ((double)capacity / list->items[i].weight);
            capacity = 0;
        }
    }
    return totalValue;
}

void printMenu() {
    printf("===========================\n");
    printf("       Knapsack Problem    \n");
    printf("===========================\n");
}

int main() {
    ItemList itemList;
    initializeItemList(&itemList);
    
    addItem(&itemList, 60, 10);
    addItem(&itemList, 100, 20);
    addItem(&itemList, 120, 30);
    
    int capacity;
    printMenu();
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    double maxValue = knapsackGreedy(&itemList, capacity);
    printf("The maximum value in the knapsack is: %.2f\n", maxValue);
    
    return 0;
}