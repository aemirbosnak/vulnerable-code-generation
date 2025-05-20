//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    int quantity;
    float price;
};

struct customer {
    char name[50];
    int id;
};

void add_item(struct item items[], int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);
    (*num_items)++;
}

void display_items(struct item items[], int num_items) {
    printf("\nItem List:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, items[i].name, items[i].quantity, items[i].price);
    }
}

void purchase_item(struct item items[], int num_items, struct customer customer) {
    int choice;
    printf("\nSelect an item to purchase:\n");
    display_items(items, num_items);
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= num_items) {
        if (items[choice-1].quantity > 0) {
            printf("\nEnter number of units to purchase: ");
            int units;
            scanf("%d", &units);
            if (units > items[choice-1].quantity) {
                printf("Not enough units in stock.\n");
            } else {
                items[choice-1].quantity -= units;
                printf("\nPurchase successful!\n");
            }
        } else {
            printf("Item out of stock.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
}

void main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    struct customer customer;
    printf("\nEnter customer name: ");
    scanf("%s", customer.name);
    printf("Enter customer ID: ");
    scanf("%d", &customer.id);

    while (1) {
        printf("\nWelcome, %s (%d)!\n", customer.name, customer.id);
        printf("1. Purchase item\n2. View item list\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                purchase_item(items, num_items, customer);
                break;
            case 2:
                display_items(items, num_items);
                break;
            case 3:
                printf("\nThank you for shopping with us, %s (%d)!\n", customer.name, customer.id);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}