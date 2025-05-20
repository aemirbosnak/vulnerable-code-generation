//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    float total_price;
} Order;

void print_menu() {
    printf("Welcome to the Peaceful Cafe!\n");
    printf("-------------------------\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $1.50\n");
    printf("3. Smoothie - $3.50\n");
    printf("4. Sandwich - $5.00\n");
    printf("5. Salad - $4.00\n");
    printf("6. Exit\n");
}

void add_item(Order *order) {
    int item_number;
    int quantity;

    printf("Enter the item number: ");
    scanf("%d", &item_number);

    if (item_number < 1 || item_number > 6) {
        printf("Invalid item number.\n");
        return;
    }

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity < 1) {
        printf("Invalid quantity.\n");
        return;
    }

    order->items[order->num_items].quantity = quantity;

    switch (item_number) {
        case 1:
            strcpy(order->items[order->num_items].name, "Coffee");
            order->items[order->num_items].price = 2.50;
            break;
        case 2:
            strcpy(order->items[order->num_items].name, "Tea");
            order->items[order->num_items].price = 1.50;
            break;
        case 3:
            strcpy(order->items[order->num_items].name, "Smoothie");
            order->items[order->num_items].price = 3.50;
            break;
        case 4:
            strcpy(order->items[order->num_items].name, "Sandwich");
            order->items[order->num_items].price = 5.00;
            break;
        case 5:
            strcpy(order->items[order->num_items].name, "Salad");
            order->items[order->num_items].price = 4.00;
            break;
    }

    order->num_items++;
}

void print_order(Order *order) {
    printf("Your order:\n");
    printf("-------------------------\n");

    for (int i = 0; i < order->num_items; i++) {
        printf("%d %s - $%.2f\n", order->items[i].quantity, order->items[i].name, order->items[i].price * order->items[i].quantity);
    }

    printf("Total: $%.2f\n", order->total_price);
}

int main() {
    Order order;
    order.num_items = 0;
    order.total_price = 0.0;

    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                add_item(&order);
                break;
            case 6:
                print_order(&order);
                break;
        }
    } while (choice != 6);

    return 0;
}