//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} item_t;

void add_item(item_t *items, int num_items) {
    char name[50];
    float price;
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item price: ");
    scanf("%f", &price);

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    items[num_items].quantity = quantity;

    num_items++;
}

void display_items(item_t *items, int num_items) {
    printf("\nItem Name\t\tPrice\t\tQuantity\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%.2f\t\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

float calculate_total(item_t *items, int num_items) {
    float total = 0.0;

    for (int i = 0; i < num_items; i++) {
        total += items[i].price * items[i].quantity;
    }

    return total;
}

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        add_item(items, num_items);
    }

    display_items(items, num_items);

    float total = calculate_total(items, num_items);

    printf("\nTotal Expense: %.2f\n", total);

    return 0;
}