//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure to hold an item with its name and price
struct MenuItem {
    char name[50];
    float price;
};

// Structure to hold an order with the item, quantity and total price
struct Order {
    struct MenuItem item;
    int quantity;
    float totalPrice;
};

// Function to display the menu items
void displayMenu(struct MenuItem menu[], int itemCount) {
    printf("--------Menu--------\n");
    for(int i = 0; i < itemCount; i++) {
        printf("%d. %s - %.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to place an order
void placeOrder(struct MenuItem menu[], int itemCount, struct Order orders[], int *orderCount) {
    int itemNo, quantity;

    printf("Enter item number: ");
    scanf("%d", &itemNo);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Check if item no is valid
    if(itemNo < 1 || itemNo > itemCount) {
        printf("Invalid item number\n");
        return;
    }

    struct MenuItem menuItem = menu[itemNo-1];
    float totalPrice = menuItem.price * quantity;

    // Add the order to the orders list
    struct Order order = { menuItem, quantity, totalPrice };
    orders[(*orderCount)++] = order;

    printf("Order placed successfully!\n");
}

// Function to display the orders
void displayOrders(struct Order orders[], int orderCount) {
    printf("--------Orders--------\n");
    float grandTotal = 0;
    for(int i = 0; i < orderCount; i++) {
        struct Order order = orders[i];
        printf("%d. %s x %d - %.2f\n", i+1, order.item.name, order.quantity, order.totalPrice);
        grandTotal += order.totalPrice;
    }
    printf("Grand Total: %.2f\n", grandTotal);
}

int main() {
    struct MenuItem menu[MAX_ITEMS];
    int itemCount = 0;

    // Add some sample menu items
    struct MenuItem item1 = { "Coffee", 2.50 };
    struct MenuItem item2 = { "Tea", 1.80 };
    struct MenuItem item3 = { "Sandwich", 4.20 };

    menu[itemCount++] = item1;
    menu[itemCount++] = item2;
    menu[itemCount++] = item3;

    struct Order orders[MAX_ITEMS];
    int orderCount = 0;

    // Main loop to display options and handle user input
    while(1) {
        printf("\nOptions:\n");
        printf("1. Display Menu\n");
        printf("2. Place Order\n");
        printf("3. Display Orders\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayMenu(menu, itemCount);
                break;
            case 2:
                placeOrder(menu, itemCount, orders, &orderCount);
                break;
            case 3:
                displayOrders(orders, orderCount);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}