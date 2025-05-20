//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LEN 30
#define MAX_ORDER_HISTORY 100

// Structures for menu item and order
struct MenuItem {
    char name[MAX_ITEM_NAME_LEN];
    int price;
};

struct Order {
    struct MenuItem item;
    int quantity;
    int total;
};

// Function to add a new menu item
void addMenuItem(struct MenuItem menu[], int *numItems) {
    struct MenuItem newItem;
    printf("Enter the name of the item (max %d characters): ", MAX_ITEM_NAME_LEN);
    scanf("%s", newItem.name);
    printf("Enter the price of the item: ");
    scanf("%d", &newItem.price);
    menu[*numItems] = newItem;
    *numItems += 1;
    printf("Item added successfully!\n");
}

// Function to display the menu
void displayMenu(struct MenuItem menu[], int numItems) {
    printf("===================\n");
    printf("     MENU\n");
    printf("===================\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s: $%d\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to place a new order
void placeOrder(struct MenuItem menu[], int numItems, struct Order orderHistory[], int *numOrders) {
    printf("Enter the number of the item you want to order: ");
    int itemNum;
    scanf("%d", &itemNum);
    if (itemNum < 1 || itemNum > numItems) {
        printf("Invalid item number.\n");
        return;
    }
    printf("Enter the quantity: ");
    int quantity;
    scanf("%d", &quantity);
    if (quantity < 1) {
        printf("Invalid quantity.\n");
        return;
    }
    struct MenuItem item = menu[itemNum-1];
    int total = item.price * quantity;
    printf("Your total for %d %s is $%d.\n", quantity, item.name, total);
    printf("Confirm order? (yes/no): ");
    char confirm[4];
    scanf("%s", confirm);
    if (strcmp(confirm, "yes") == 0) {
        struct Order newOrder;
        newOrder.item = item;
        newOrder.quantity = quantity;
        newOrder.total = total;
        orderHistory[*numOrders] = newOrder;
        *numOrders += 1;
        printf("Order placed successfully!\n");
    } else {
        printf("Order cancelled.\n");
    }
}

// Function to display order history
void displayOrderHistory(struct Order orderHistory[], int numOrders) {
    printf("=====================\n");
    printf("    ORDER HISTORY\n");
    printf("=====================\n");
    if (numOrders == 0) {
        printf("No orders placed.\n");
        return;
    }
    for (int i = 0; i < numOrders; i++) {
        struct Order order = orderHistory[i];
        printf("Order %d: %d x %s = $%d\n", i+1, order.quantity, order.item.name, order.total);
    }
}

int main() {
    struct MenuItem menu[50];
    int numItems = 0;

    struct Order orderHistory[MAX_ORDER_HISTORY];
    int numOrders = 0;

    while (1) {
        printf("\n\n");
        printf("=====================\n");
        printf("   CAFE BILLING SYSTEM\n");
        printf("=====================\n");
        printf("1. Add an item to the menu\n");
        printf("2. Display the menu\n");
        printf("3. Place a new order\n");
        printf("4. Display order history\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMenuItem(menu, &numItems);
                break;
            case 2:
                displayMenu(menu, numItems);
                break;
            case 3:
                placeOrder(menu, numItems, orderHistory, &numOrders);
                break;
            case 4:
                displayOrderHistory(orderHistory, numOrders);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}