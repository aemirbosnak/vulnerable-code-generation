//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    double price;
    int quantity;
};

void add_item(struct item *items, int num_items, char *name, double price, int quantity) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: maximum number of items reached.\n");
        exit(1);
    }
    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    items[num_items].quantity = quantity;
    num_items++;
}

void print_items(struct item *items, int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total(struct item *items, int num_items) {
    double total = 0.0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    while (1) {
        printf("Enter item name: ");
        char name[50];
        scanf("%s", name);
        if (strlen(name) == 0) {
            printf("Error: item name cannot be empty.\n");
            continue;
        }
        printf("Enter item price: ");
        double price;
        scanf("%lf", &price);
        printf("Enter item quantity: ");
        int quantity;
        scanf("%d", &quantity);
        add_item(items, num_items, name, price, quantity);
        if (num_items == 0) {
            printf("No items added yet.\n");
        } else {
            printf("Items added:\n");
            print_items(items, num_items);
        }
    }

    calculate_total(items, num_items);

    return 0;
}