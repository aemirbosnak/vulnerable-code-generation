//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_ITEMS 10
#define MAX_PROFIT 100

typedef struct {
    char name[MAX_NAME_LEN];
    int weight;
    int value;
} Item;

void generate_items(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        sprintf(items[i].name, "Cyberware %d", i + 1);
        items[i].weight = rand() % 100 + 1;
        items[i].value = rand() % MAX_PROFIT + 1;
    }
}

int compare_profit(const void *a, const void *b) {
    const Item *item1 = a;
    const Item *item2 = b;
    return item2->value - item1->value;
}

void print_solution(Item items[], int n) {
    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (items[i].value > 0) {
            printf("%s (%d credits)\n", items[i].name, items[i].value);
        }
    }
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    generate_items(items, n);

    qsort(items, n, sizeof(Item), compare_profit);

    int capacity = 0;
    printf("Enter your backpack capacity: ");
    scanf("%d", &capacity);

    int profit = 0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].value > 0 && items[i].weight <= capacity) {
            profit += items[i].value;
            capacity -= items[i].weight;
        }
    }

    printf("Maximum profit: %d credits\n", profit);
    print_solution(items, n);

    return 0;
}