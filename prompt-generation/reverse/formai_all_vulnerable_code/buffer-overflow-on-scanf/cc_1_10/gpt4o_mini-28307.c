//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
} Menu;

typedef struct {
    MenuItem orderedItems[MAX_ITEMS];
    int itemCount;
} Order;

// Function prototypes.
void initializeMenu(Menu *menu);
void displayMenu(const Menu *menu);
void takeOrder(const Menu *menu, Order *order);
void printBill(const Order *order);
void resetOrder(Order *order);

// Main function.
int main() {
    Menu cafeMenu;
    Order customerOrder;
    
    initializeMenu(&cafeMenu);

    int choice;
    do {
        printf("\n--- Cafe Billing System ---\n");
        printf("1. Display Menu\n");
        printf("2. Take Order\n");
        printf("3. Print Bill\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayMenu(&cafeMenu);
                break;
            case 2:
                takeOrder(&cafeMenu, &customerOrder);
                break;
            case 3:
                printBill(&customerOrder);
                resetOrder(&customerOrder);
                break;
            case 4:
                printf("Thank you for visiting!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

// Initialize the menu with some items.
void initializeMenu(Menu *menu) {
    menu->count = 5;
    menu->items[0] = (MenuItem){1, "Coffee", 2.50};
    menu->items[1] = (MenuItem){2, "Tea", 1.50};
    menu->items[2] = (MenuItem){3, "Sandwich", 3.00};
    menu->items[3] = (MenuItem){4, "Cake", 2.00};
    menu->items[4] = (MenuItem){5, "Juice", 2.75};
}

// Display the cafe menu.
void displayMenu(const Menu *menu) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < menu->count; i++) {
        printf("%d. %s - $%.2f\n", menu->items[i].id, menu->items[i].name, menu->items[i].price);
    }
}

// Take an order from the customer.
void takeOrder(const Menu *menu, Order *order) {
    int itemId, quantity;

    printf("\n--- Place Your Order ---\n");
    order->itemCount = 0;

    while (1) {
        printf("Enter Item ID (0 to finish): ");
        scanf("%d", &itemId);
        
        if (itemId == 0) {
            break;
        }

        // Validate item ID
        if (itemId < 1 || itemId > menu->count) {
            printf("Invalid item ID! Please choose a valid item.\n");
            continue;
        }

        printf("Enter Quantity: ");
        scanf("%d", &quantity);
        
        // Validate quantity
        if (quantity <= 0) {
            printf("Invalid quantity! Please enter a positive number.\n");
            continue;
        }

        // Add item to order
        int index = itemId - 1; // Items start from 1
        for (int i = 0; i < quantity; i++) {
            order->orderedItems[order->itemCount++] = menu->items[index];
        }

        printf("Added %d x %s to your order.\n", quantity, menu->items[index].name);
    }
}

// Print the bill for the order.
void printBill(const Order *order) {
    float total = 0.0;

    printf("\n--- Your Bill ---\n");
    for (int i = 0; i < order->itemCount; i++) {
        printf("%s - $%.2f\n", order->orderedItems[i].name, order->orderedItems[i].price);
        total += order->orderedItems[i].price;
    }
    printf("Total: $%.2f\n", total);
}

// Reset the order.
void resetOrder(Order *order) {
    order->itemCount = 0;
}