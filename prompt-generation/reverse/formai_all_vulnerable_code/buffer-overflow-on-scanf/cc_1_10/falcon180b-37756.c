//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
} item_t;

void add_item(item_t *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", (*num_items == MAX_ITEMS - 1)? items[*num_items].name : "");
    printf("Enter item price: $");
    scanf("%lf", &items[*num_items].price);
    (*num_items)++;
}

void display_items(item_t *items, int num_items) {
    printf("Item\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t$%.2lf\n", items[i].name, items[i].price);
    }
}

void calculate_total(item_t *items, int num_items) {
    double total = 0.0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price;
    }
    printf("Total Expense: $%.2lf\n", total);
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    if (num_items > MAX_ITEMS - 1) {
        printf("Error: Maximum number of items is %d.\n", MAX_ITEMS - 1);
        return 1;
    }

    for (int i = 0; i < num_items; i++) {
        add_item(items, &num_items);
    }

    display_items(items, num_items);
    calculate_total(items, num_items);

    return 0;
}