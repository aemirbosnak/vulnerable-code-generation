//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

struct item {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
};

void add_item(struct item* items, int num_items, char* name, char* price, int quantity) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached\n");
        return;
    }

    strncpy(items[num_items].name, name, MAX_NAME_LEN);
    strncpy(items[num_items].price, price, MAX_PRICE_LEN);
    items[num_items].quantity = quantity;

    num_items++;
}

void display_items(struct item* items, int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %s - %d\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total(struct item* items, int num_items) {
    float total = 0.0;

    for (int i = 0; i < num_items; i++) {
        float price = atof(items[i].price);
        total += price * items[i].quantity;
    }

    printf("Total: %.2f\n", total);
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;

    while (1) {
        printf("Enter item name:");
        scanf("%s", name);

        printf("Enter item price:");
        scanf("%s", price);

        printf("Enter item quantity:");
        scanf("%d", &quantity);

        add_item(items, num_items, name, price, quantity);

        printf("Do you want to add another item? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice!= 'y') {
            break;
        }
    }

    display_items(items, num_items);
    calculate_total(items, num_items);

    return 0;
}