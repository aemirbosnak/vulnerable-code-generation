//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHT 50 // maximum weight capacity of knapsack
#define MAX_ITEMS 10  // maximum number of items

// a structure to represent an item
struct Item {
    int value;   // value of the item
    int weight;  // weight of the item
};

// function to sort items based on their value/weight ratio in descending order
int compare(const void* a, const void* b) {
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;
    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;
    if (ratio1 < ratio2)
        return 1;
    else if (ratio1 > ratio2)
        return -1;
    else
        return 0;
}

int main() {
    int n;  // number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[MAX_ITEMS];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    qsort(items, n, sizeof(struct Item), compare);  // sort items in descending order of value/weight ratio
    int total_weight = 0;  // total weight of items in the knapsack
    double total_value = 0.0; // total value of items in the knapsack
    int i = 0;  // index of current item
    while (total_weight < MAX_WEIGHT && i < n) {
        if (total_weight + items[i].weight <= MAX_WEIGHT) {
            total_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            int remaining_weight = MAX_WEIGHT - total_weight;
            total_weight += remaining_weight;
            total_value += ((double)remaining_weight / items[i].weight) * items[i].value;
        }
        i++;
    }
    printf("Total weight: %d\n", total_weight);
    printf("Total value: %.2lf\n", total_value);
    return 0;
}