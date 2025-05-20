//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct item {
    int weight;
    int benefit;
} Item;

Item items[MAX];

int compare(const void* a, const void* b) {
    Item* i1 = (Item*)a;
    Item* i2 = (Item*)b;
    double r1 = (double)i1->benefit / i1->weight;
    double r2 = (double)i2->benefit / i2->weight;
    if (r1 > r2) {
        return -1;
    } else if (r1 < r2) {
        return 1;
    } else {
        return 0;
    }
}

int knapsack(int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);
    int weight = 0;
    int benefit = 0;
    for (int i = 0; i < n; i++) {
        if (weight + items[i].weight <= capacity) {
            weight += items[i].weight;
            benefit += items[i].benefit;
        } else {
            int remaining_capacity = capacity - weight;
            double ratio = (double)remaining_capacity / items[i].weight;
            weight += remaining_capacity;
            benefit += ratio * items[i].benefit;
            break;
        }
    }
    return benefit;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    for (int i = 0; i < n; i++) {
        printf("Enter the item %d weight and benefit: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].benefit);
    }
    int result = knapsack(n, capacity);
    printf("The maximum benefit is %d\n", result);
    return 0;
}