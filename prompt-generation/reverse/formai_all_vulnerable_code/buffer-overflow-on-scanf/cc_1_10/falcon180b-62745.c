//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_VALUE 1000

typedef struct {
    int value;
    int weight;
} Item;

Item items[MAX_ITEMS];
int num_items;
int max_weight;

void generate_random_items(int num_items) {
    srand(time(NULL));
    for (int i = 0; i < num_items; i++) {
        items[i].value = rand() % MAX_VALUE;
        items[i].weight = rand() % MAX_VALUE;
    }
}

bool compare_items(const void *a, const void *b) {
    const Item *item1 = a;
    const Item *item2 = b;
    return (double)item1->value / item1->weight > (double)item2->value / item2->weight;
}

void sort_items() {
    qsort(items, num_items, sizeof(Item), compare_items);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    printf("Enter maximum weight: ");
    scanf("%d", &max_weight);

    generate_random_items(num_items);
    sort_items();

    printf("Sorted items by value/weight ratio:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d: %d/%d = %.2f\n", i+1, items[i].value, items[i].weight, (double)items[i].value / items[i].weight);
    }

    int knapsack_value = 0;
    int knapsack_weight = 0;
    for (int i = 0; i < num_items; i++) {
        if (knapsack_weight + items[i].weight <= max_weight) {
            knapsack_value += items[i].value;
            knapsack_weight += items[i].weight;
        } else {
            break;
        }
    }

    printf("\nKnapsack value: %d\n", knapsack_value);

    return 0;
}