//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_VAL 1000

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void* a, const void* b) {
    Item *itemA = (Item*)a;
    Item *itemB = (Item*)b;

    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;

    if (ratioA > ratioB)
        return -1;
    else if (ratioA < ratioB)
        return 1;
    else
        return 0;
}

void knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);

    int totalWeight = 0;
    int totalValue = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - totalWeight;
            double valuePerWeight = (double)items[i].value / items[i].weight;
            totalWeight += remainingWeight;
            totalValue += remainingWeight * valuePerWeight;
            break;
        }
    }

    printf("Maximum value you can take is %d and total weight is %d\n", totalValue, totalWeight);
}

int main() {
    srand(time(NULL));

    Item items[MAX_SIZE];
    int n, i, capacity;

    printf("Enter the number of items you have: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Generating random items with values between 1 to %d and weights between 1 to %d...\n", MAX_VAL, MAX_VAL);

    for (i = 0; i < n; i++) {
        items[i].value = rand() % MAX_VAL + 1;
        items[i].weight = rand() % MAX_VAL + 1;
    }

    printf("Sorting the items by value per weight ratio...\n");

    knapsack(items, n, capacity);

    return 0;
}