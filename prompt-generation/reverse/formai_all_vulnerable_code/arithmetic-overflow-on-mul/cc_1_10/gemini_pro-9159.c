//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME_LEN 50

typedef struct {
    char name[MAX_ITEM_NAME_LEN];
    int price;
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    int total_price;
} Order;

void add_item(Order *order, Item item) {
    if (order->num_items == MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    order->items[order->num_items++] = item;
}

void print_order(Order *order) {
    printf("\n********************************************************************\n");
    printf("Order Summary:\n");
    printf("--------------------------------------------------------------------\n");

    printf("No. | Item Name | Price | Quantity | Total\n");
    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < order->num_items; i++) {
        Item item = order->items[i];
        printf("%2d | %-20s | %4d | %4d | %d\n", i + 1, item.name, item.price, item.quantity, item.price * item.quantity);
    }

    printf("\nTotal Price: %d\n", order->total_price);
    printf("********************************************************************\n\n");
}

int main() {
    Order order = {0};
    int choice = 0;

    while (choice != 4) {
        printf("\nCafe Billing System:\n");
        printf("--------------------\n");
        printf("1. Add Item\n");
        printf("2. Print Order\n");
        printf("3. Clear Order\n");
        printf("4. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    Item item;
                    printf("\nEnter Item Name: ");
                    scanf("%s", item.name);
                    printf("Enter Price: ");
                    scanf("%d", &item.price);
                    printf("Enter Quantity: ");
                    scanf("%d", &item.quantity);
                    order.total_price += item.price * item.quantity;
                    add_item(&order, item);
                    printf("Item added successfully.\n");
                    break;
                }
            case 2:
                print_order(&order);
                break;
            case 3:
                order.num_items = 0;
                order.total_price = 0;
                printf("Order cleared successfully.\n");
                break;
            case 4:
                printf("Thank you for using Cafe Billing System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}