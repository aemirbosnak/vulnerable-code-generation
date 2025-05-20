//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 1000

typedef struct {
    char *name;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, float price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Too many items.\n");
        return;
    }
    items[num_items].name = strdup(name);
    items[num_items].price = price;
    num_items++;
}

void remove_item(int index) {
    if (index < 0 || index >= num_items) {
        printf("Error: Invalid item index.\n");
        return;
    }
    free(items[index].name);
    memmove(&items[index], &items[index + 1], sizeof(Item) * (num_items - index - 1));
    num_items--;
}

void print_items() {
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
}

int main() {
    add_item("Apple", 0.99);
    add_item("Banana", 0.49);
    add_item("Orange", 0.89);
    print_items();

    remove_item(1);
    print_items();

    return 0;
}