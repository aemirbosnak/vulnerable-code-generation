//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 50
#define MAX_ORDERS 100

typedef struct {
    int id;
    char name[50];
    float price;
    int stock;
} MenuItem;

typedef struct {
    int id;
    MenuItem item;
    int quantity;
} Order;

MenuItem menu[MAX_MENU_ITEMS];
Order orders[MAX_ORDERS];

int menuCount = 0;
int orderCount = 0;

void addMenuItem() {
    if (menuCount >= MAX_MENU_ITEMS) {
        printf("Error: Menu is full!\n");
        return;
    }

    MenuItem newItem;
    newItem.id = menuCount + 1;

    printf("Enter the name of the menu item: ");
    scanf("%s", newItem.name);

    printf("Enter the price of the menu item: ");
    scanf("%f", &newItem.price);

    printf("Enter the stock of the menu item: ");
    scanf("%d", &newItem.stock);

    menu[menuCount++] = newItem;
    printf("Menu item added successfully!\n");
}

void displayMenu() {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d. %s - $%.2f (%d in stock)\n", menu[i].id, menu[i].name, menu[i].price, menu[i].stock);
    }
}

void placeOrder() {
    if (orderCount >= MAX_ORDERS) {
        printf("Error: Order limit reached!\n");
        return;
    }

    displayMenu();
    
    int itemId, quantity;
    printf("Enter the menu item ID to order: ");
    scanf("%d", &itemId);

    if (itemId < 1 || itemId > menuCount) {
        printf("Error: Invalid menu item ID!\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (quantity > menu[itemId - 1].stock) {
        printf("Error: Not enough stock!\n");
        return;
    }

    Order newOrder;
    newOrder.id = orderCount + 1;
    newOrder.item = menu[itemId - 1];
    newOrder.quantity = quantity;
    
    orders[orderCount++] = newOrder;
    menu[itemId - 1].stock -= quantity;

    printf("Order placed successfully!\n");
}

void calculateTotal() {
    float total = 0;
    printf("\n--- Order Summary ---\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%d. %s x%d - $%.2f\n", orders[i].id, orders[i].item.name, orders[i].quantity, orders[i].quantity * orders[i].item.price);
        total += orders[i].quantity * orders[i].item.price;
    }
    printf("Total Amount: $%.2f\n", total);
}

void menuOperations() {
    while (1) {
        printf("\n--- Menu Operations ---\n");
        printf("1. Add Menu Item\n");
        printf("2. Display Menu\n");
        printf("3. Place Order\n");
        printf("4. Calculate Total\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMenuItem();
                break;
            case 2:
                displayMenu();
                break;
            case 3:
                placeOrder();
                break;
            case 4:
                calculateTotal();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Error: Invalid option! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Cafe Billing System!\n");
    menuOperations();
    return 0;
}