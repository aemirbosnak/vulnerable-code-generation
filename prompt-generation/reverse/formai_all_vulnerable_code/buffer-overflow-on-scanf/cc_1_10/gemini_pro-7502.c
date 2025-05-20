//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int weight;
    int value;
} Item;

Item items[MAX_SIZE];
int n_items;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;

    return (item1->value / item1->weight) - (item2->value / item2->weight);
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n_items);

    for (int i = 0; i < n_items; i++) {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);

        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &items[i].value);
    }

    qsort(items, n_items, sizeof(Item), compare);

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int total_value = 0;
    int current_weight = 0;

    for (int i = 0; i < n_items; i++) {
        if (current_weight + items[i].weight <= capacity) {
            total_value += items[i].value;
            current_weight += items[i].weight;
        } else {
            int remaining_capacity = capacity - current_weight;
            total_value += (remaining_capacity * items[i].value) / items[i].weight;
            break;
        }
    }

    printf("The maximum total value is: %d\n", total_value);

    return 0;
}