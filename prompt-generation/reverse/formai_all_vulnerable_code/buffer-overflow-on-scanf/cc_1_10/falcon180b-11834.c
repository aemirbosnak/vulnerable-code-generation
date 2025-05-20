//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int price;
} ITEM;

typedef struct {
    char name[MAX_NAME_LEN];
    ITEM items[MAX_ITEMS];
    int num_items;
} CUSTOMER;

void add_item(ITEM *item, char *name, int price) {
    strcpy(item->name, name);
    item->price = price;
}

void add_customer(CUSTOMER *customer, char *name) {
    strcpy(customer->name, name);
    customer->num_items = 0;
}

void add_item_to_customer(CUSTOMER *customer, ITEM *item) {
    if (customer->num_items >= MAX_ITEMS) {
        printf("Sorry, customer %s has too many items.\n", customer->name);
        return;
    }
    strcpy(customer->items[customer->num_items].name, item->name);
    customer->items[customer->num_items].price = item->price;
    customer->num_items++;
}

void print_customer(CUSTOMER *customer) {
    printf("Customer name: %s\n", customer->name);
    printf("Number of items: %d\n", customer->num_items);
    for (int i = 0; i < customer->num_items; i++) {
        printf("Item %d: %s - $%d\n", i+1, customer->items[i].name, customer->items[i].price);
    }
}

int main() {
    CUSTOMER customer;
    ITEM item;
    char name[MAX_NAME_LEN];
    int choice, price;

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    add_customer(&customer, name);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add item\n");
        printf("2. Print bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item price: ");
            scanf("%d", &price);
            add_item(&item, name, price);
            add_item_to_customer(&customer, &item);
            break;
        case 2:
            print_customer(&customer);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}