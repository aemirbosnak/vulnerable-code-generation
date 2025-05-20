//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    float total;
} Order;

void print_menu() {
    printf("Welcome to Donald's Cafe!\n");
    printf("------------------------\n");
    printf("1. Coffee - $1.50\n");
    printf("2. Tea - $1.25\n");
    printf("3. Croissant - $2.00\n");
    printf("4. Muffin - $1.75\n");
    printf("5. Scone - $2.25\n");
    printf("------------------------\n");
    printf("Enter the number of the item you would like to order, or 0 to exit:\n");
}

void add_item_to_order(Order *order) {
    int item_number;
    printf("Enter the number of the item you would like to order: ");
    scanf("%d", &item_number);

    if (item_number < 1 || item_number > 5) {
        printf("Invalid item number. Please enter a number between 1 and 5.\n");
        return;
    }

    Item item;
    switch (item_number) {
        case 1:
            strcpy(item.name, "Coffee");
            item.price = 1.50;
            break;
        case 2:
            strcpy(item.name, "Tea");
            item.price = 1.25;
            break;
        case 3:
            strcpy(item.name, "Croissant");
            item.price = 2.00;
            break;
        case 4:
            strcpy(item.name, "Muffin");
            item.price = 1.75;
            break;
        case 5:
            strcpy(item.name, "Scone");
            item.price = 2.25;
            break;
    }

    printf("Enter the quantity of %s you would like to order: ", item.name);
    scanf("%d", &item.quantity);

    order->items[order->num_items] = item;
    order->num_items++;
    order->total += item.quantity * item.price;
}

void print_order(Order *order) {
    printf("------------------------\n");
    printf("Your Order:\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%d %s - $%.2f\n", order->items[i].quantity, order->items[i].name, order->items[i].quantity * order->items[i].price);
    }
    printf("------------------------\n");
    printf("Total: $%.2f\n", order->total);
}

int main() {
    Order order;
    order.num_items = 0;
    order.total = 0.0;

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                add_item_to_order(&order);
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 5.\n");
        }
    } while (choice != 0);

    print_order(&order);

    return 0;
}