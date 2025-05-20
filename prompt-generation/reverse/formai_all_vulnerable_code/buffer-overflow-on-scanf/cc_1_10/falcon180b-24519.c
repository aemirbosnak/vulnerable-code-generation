//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MENU_ITEMS 20
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEM_PRICE 1000
#define MAX_CUSTOMERS 50

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    float price;
} MenuItem;

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    char order[MAX_ITEM_NAME_LENGTH];
    float totalPrice;
} CustomerOrder;

void loadMenuItems(MenuItem menuItems[MAX_MENU_ITEMS]) {
    int i = 0;
    while (i < MAX_MENU_ITEMS) {
        printf("Enter name and price of item %d (separated by space):\n", i+1);
        scanf("%s %f", menuItems[i].name, &menuItems[i].price);
        i++;
    }
}

void displayMenu(MenuItem menuItems[MAX_MENU_ITEMS]) {
    int i = 0;
    while (i < MAX_MENU_ITEMS) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
        i++;
    }
}

void placeOrder(CustomerOrder customerOrder, MenuItem menuItems[MAX_MENU_ITEMS]) {
    int i = 0;
    while (i < MAX_MENU_ITEMS) {
        printf("Enter item name to order (or 'done' to finish ordering):\n");
        scanf("%s", customerOrder.order);
        if (strcmp(customerOrder.order, "done") == 0) {
            break;
        }
        for (int j = 0; j < MAX_MENU_ITEMS; j++) {
            if (strcmp(menuItems[j].name, customerOrder.order) == 0) {
                customerOrder.totalPrice += menuItems[j].price;
                printf("Added %s to order - $%.2f\n", customerOrder.order, menuItems[j].price);
                break;
            }
        }
        i++;
    }
}

void printOrderSummary(CustomerOrder customerOrder) {
    printf("Order summary:\n");
    printf("Name: %s\n", customerOrder.name);
    printf("Order: %s\n", customerOrder.order);
    printf("Total price: $%.2f\n", customerOrder.totalPrice);
}

int main() {
    MenuItem menuItems[MAX_MENU_ITEMS];
    loadMenuItems(menuItems);

    CustomerOrder customerOrder;
    strcpy(customerOrder.name, "John Doe");

    placeOrder(customerOrder, menuItems);

    printOrderSummary(customerOrder);

    return 0;
}