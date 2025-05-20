//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: invasive
/* Welcome to the C Cafe Billing System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10      // maximum number of items in the menu
#define MAX_ORDERS 50     // maximum number of orders that can be placed
#define MENU_FILE "menu.txt"  // the file containing the menu items and their prices

/* Struct for holding menu items */
typedef struct MenuItem {
    char name[50];
    float price;
} MenuItem;

/* Struct for holding an order */
typedef struct Order {
    int item_number;
    int quantity;
    float total_price;
} Order;

/* Function to load the menu from file */
void load_menu(MenuItem *menu) {
    int i = 0;
    FILE *fp = fopen(MENU_FILE, "r");
    if (fp == NULL) {
        printf("Error: unable to open menu file.\n");
        exit(1);
    }
    while (!feof(fp) && i < MAX_ITEMS) {
        fscanf(fp, "%s%f", menu[i].name, &menu[i].price);
        i++;
    }
    fclose(fp);
}

/* Function to display the menu */
void display_menu(MenuItem *menu) {
    printf("\n**** MENU ****\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %-30s%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

/* Function to take an order */
void take_order(MenuItem *menu, Order *orders, int *order_count) {
    int item_number, quantity;
    printf("\nWhat would you like to order? Please enter an item number: ");
    scanf("%d", &item_number);
    if (item_number < 1 || item_number > MAX_ITEMS) {
        printf("Error: invalid item number.\n");
        return;
    }
    printf("How many would you like to order? ");
    scanf("%d", &quantity);
    if (quantity < 1) {
        printf("Error: quantity must be greater than 0.\n");
        return;
    }
    float total_price = menu[item_number-1].price * quantity;
    Order order = { item_number, quantity, total_price };
    orders[*order_count] = order;
    *order_count += 1;
    printf("Order placed successfully.\n");
}

/* Function to display the order details and total */
void display_order(Order *orders, int order_count, MenuItem *menu) {
    printf("\n**** ORDER DETAILS ****\n");
    float total = 0.0;
    for (int i = 0; i < order_count; i++) {
        printf("%d x %-30s%.2f\n", orders[i].quantity, menu[orders[i].item_number-1].name, orders[i].total_price);
        total += orders[i].total_price;
    }
    printf("Total: %.2f\n", total);
}

int main() {
    MenuItem menu[MAX_ITEMS];
    Order orders[MAX_ORDERS];
    int order_count = 0;
    load_menu(menu);
    display_menu(menu);
    while (1) {
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Place an order\n");
        printf("2. View order\n");
        printf("3. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                take_order(menu, orders, &order_count);
                break;
            case 2:
                display_order(orders, order_count, menu);
                break;
            case 3:
                printf("Thank you for using C Cafe Billing System!\n");
                exit(0);
            default:
                printf("Error: invalid choice.\n");
                break;
        }
    }
    return 0;
}