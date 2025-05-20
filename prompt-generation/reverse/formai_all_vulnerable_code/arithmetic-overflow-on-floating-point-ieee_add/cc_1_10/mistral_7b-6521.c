//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 10
#define MAX_ORDER_ITEMS 5

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int id;
    int quantity;
    MenuItem item;
} OrderItem;

MenuItem menu[MAX_MENU_ITEMS] = {{"Cappuccino", 3.5}, {"Latte", 3.2}, {"Espresso", 2.5}, {"Americano", 2.8}, {"Macchiato", 2.2}, {"Mocha", 3.8}, {"Chai Latte", 3.6}, {"Tea", 2.0}, {"Hot Chocolate", 3.0}, {"Cold Brew", 2.7}};
OrderItem order[MAX_ORDER_ITEMS] = {};
int num_orders = 0, num_items_in_order = 0;

void print_menu() {
    printf("\n-----------------------------------------\n");
    printf("|             C AFE MENU               |\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < MAX_MENU_ITEMS; i++) {
        printf("| %-15s | %.2f |\n", menu[i].name, menu[i].price);
    }

    printf("-----------------------------------------\n");
}

void place_order(int item_index, int quantity) {
    if (num_items_in_order >= MAX_ORDER_ITEMS) {
        printf("Cannot add more items to the order.\n");
        return;
    }

    OrderItem new_order_item = {.id = num_orders++, .quantity = quantity, .item = menu[item_index]};
    order[num_items_in_order++] = new_order_item;

    printf("Added %d %s to your order.\n", quantity, menu[item_index].name);
}

void calculate_bill() {
    float total_bill = 0;

    printf("\n-----------------------------------------\n");
    printf("|          YOUR ORDER SUMMARY           |\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < num_items_in_order; i++) {
        total_bill += order[i].quantity * order[i].item.price;
        printf("| %-15s | %.2f | %.2f |\n", order[i].item.name, order[i].quantity, order[i].item.price);
    }

    printf("-----------------------------------------\n");
    printf("|               Total Bill               |\n");
    printf("-----------------------------------------\n");
    printf("|                 %.2f              |\n", total_bill);
}

int main() {
    int choice;

    while (1) {
        print_menu();
        printf("Enter the item number or 0 to place an order, 9 to calculate bill, or 10 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            int item_index, quantity;
            printf("Enter the item index: ");
            scanf("%d", &item_index);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);

            place_order(item_index, quantity);
        } else if (choice == 9) {
            calculate_bill();
            num_items_in_order = 0;
        } else if (choice == 10) {
            break;
        }
    }

    return 0;
}