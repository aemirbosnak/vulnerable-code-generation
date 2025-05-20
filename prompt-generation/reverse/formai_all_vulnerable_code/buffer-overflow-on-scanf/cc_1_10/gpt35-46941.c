//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

struct menu_item {
    char name[50];
    float price;
};

struct order_item {
    char name[50];
    int quantity;
    float price;
};

float calculate_total(struct order_item *orders, int num_items) {
    float total = 0;
    for (int i = 0; i < num_items; i++) {
        total += orders[i].price * orders[i].quantity;
    }
    return total;
}

int main() {
    struct menu_item menu[MAX_ITEMS];
    int num_items = 0;
    
    // Add menu items
    strcpy(menu[num_items].name, "Burger");
    menu[num_items].price = 5.99;
    num_items++;
    
    strcpy(menu[num_items].name, "Fries");
    menu[num_items].price = 2.99;
    num_items++;
    
    // Take order
    struct order_item orders[MAX_ITEMS];
    int num_orders = 0;
    
    printf("Welcome to the Cafe! Here's our menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    
    printf("Enter the item number you'd like to order (or 0 to finish): ");
    int item_num;
    scanf("%d", &item_num);
    
    while (item_num != 0) {
        if (item_num < 1 || item_num > num_items) {
            printf("Invalid item number. Please try again.\n");
        } else {
            struct menu_item selected_item = menu[item_num - 1];
            printf("How many %ss would you like? ", selected_item.name);
            int quantity;
            scanf("%d", &quantity);
            struct order_item order = {0};
            strcpy(order.name, selected_item.name);
            order.quantity = quantity;
            order.price = selected_item.price;
            orders[num_orders] = order;
            num_orders++;
        }
        printf("Enter the item number you'd like to order (or 0 to finish): ");
        scanf("%d", &item_num);
    }
    
    // Print receipt
    printf("Thanks for your order! Here's your receipt:\n");
    for (int i = 0; i < num_orders; i++) {
        printf("%d. %s x%d - $%.2f\n", i+1, orders[i].name, orders[i].quantity, orders[i].price * orders[i].quantity);
    }
    
    float total = calculate_total(orders, num_orders);
    printf("Total: $%.2f\n", total);
    
    return 0;
}