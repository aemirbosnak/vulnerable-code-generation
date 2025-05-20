//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MenuItem {
    char name[100];
    int price;
};

struct Order {
    char name[100];
    int quantity;
    int total_price;
};

int main() {
    struct MenuItem menu[] = {
        {"Cappuccino", 100},
        {"Espresso", 80},
        {"Latte", 120},
        {"Mocha", 150},
        {"Tea", 50}
    };
    int menuSize = sizeof(menu) / sizeof(struct MenuItem);
    struct Order orders[100];
    int totalOrders = 0;
    while(1) {
        printf("Welcome to the C Cafe!\n");
        printf("Please choose an option:\n");
        printf("1. Add an order\n");
        printf("2. View all orders\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Please choose a menu item:\n");
            for(int i=0; i<menuSize; i++) {
                printf("%d. %s - Rs. %d\n", i+1, menu[i].name, menu[i].price);
            }
            int menuItem;
            scanf("%d", &menuItem);
            if(menuItem < 1 || menuItem > menuSize) {
                printf("Invalid choice, please try again.\n");
                continue;
            }
            printf("Enter the quantity:\n");
            int quantity;
            scanf("%d", &quantity);
            if(quantity < 1) {
                printf("Invalid quantity, please try again.\n");
                continue;
            }
            int total_price = quantity * menu[menuItem-1].price;
            struct Order order;
            strcpy(order.name, menu[menuItem-1].name);
            order.quantity = quantity;
            order.total_price = total_price;
            orders[totalOrders++] = order;
            printf("Order added successfully!\n");
        } else if(choice == 2) {
            printf("All Orders:\n");
            printf("Name\t\tQuantity\tPrice\n");
            for(int i=0; i<totalOrders; i++) {
                printf("%s\t\t%d\t\t%d\n", orders[i].name, orders[i].quantity, orders[i].total_price);
            }
        } else if(choice == 3) {
            printf("Thank you for visiting C Cafe!\n");
            exit(0);
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}