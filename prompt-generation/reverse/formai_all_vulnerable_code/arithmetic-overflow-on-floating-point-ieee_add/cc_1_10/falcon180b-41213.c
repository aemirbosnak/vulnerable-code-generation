//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
} Item;

void add_item(Item items[], int *size, char *name, float price) {
    if (*size >= MAX_ITEMS) {
        printf("Error: Cannot add more items.\n");
        return;
    }

    strcpy(items[*size].name, name);
    items[*size].price = price;
    (*size)++;
}

void display_items(Item items[], int size) {
    printf("Items:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
}

void add_order(Item items[], int size, char *name, float price) {
    printf("Order added: %s - $%.2f\n", name, price);
}

void calculate_total(Item orders[], int size, float *total) {
    *total = 0;
    for (int i = 0; i < size; i++) {
        *total += orders[i].price;
    }
}

int main() {
    int size = 0;
    Item items[MAX_ITEMS];
    Item orders[MAX_ITEMS];
    float total = 0;

    add_item(items, &size, "Coffee", 2.99);
    add_item(items, &size, "Tea", 1.99);
    add_item(items, &size, "Pastry", 3.99);

    display_items(items, size);

    add_order(orders, 0, "Coffee", 2.99);
    add_order(orders, 1, "Pastry", 3.99);

    calculate_total(orders, 2, &total);

    printf("Total: $%.2f\n", total);

    return 0;
}