//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store item details
struct MenuItem {
    int id;
    char name[30];
    float price;
};

// Structure to store ordered items
struct OrderItem {
    int id;
    int quantity;
};

// Function declarations
void displayMenu(struct MenuItem menu[], int size);
void takeOrder(struct OrderItem order[], struct MenuItem menu[], int *orderCount);
void calculateBill(struct OrderItem order[], struct MenuItem menu[], int orderCount);
void printReceipt(struct OrderItem order[], struct MenuItem menu[], int orderCount);

// Constant for maximum menu items and orders
#define MAX_MENU_ITEMS 10
#define MAX_ORDERS 20

int main() {
    struct MenuItem menu[MAX_MENU_ITEMS] = {
        {1, "Espresso", 2.50},
        {2, "Latte", 3.00},
        {3, "Cappuccino", 3.50},
        {4, "Mocha", 3.75},
        {5, "Tea", 1.50},
        {6, "Iced Coffee", 3.25},
        {7, "Sandwich", 5.00},
        {8, "Cookies", 2.00},
        {9, "Cake Slice", 4.50},
        {10, "Juice", 2.75}
    };

    struct OrderItem order[MAX_ORDERS];
    int orderCount = 0;

    printf("Welcome to the C Cafe Billing System!\n\n");

    while (1) {
        printf("1. Display Menu\n");
        printf("2. Take Order\n");
        printf("3. Print Receipt\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(menu, MAX_MENU_ITEMS);
                break;
            case 2:
                takeOrder(order, menu, &orderCount);
                break;
            case 3:
                printReceipt(order, menu, orderCount);
                break;
            case 4:
                printf("Thank you for visiting C Cafe! Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}

// Function to display the cafe menu
void displayMenu(struct MenuItem menu[], int size) {
    printf("C Cafe Menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// Function to take order from the user
void takeOrder(struct OrderItem order[], struct MenuItem menu[], int *orderCount) {
    printf("Enter item ID to order (0 to finish): ");
    int id, quantity;
    
    while (1) {
        scanf("%d", &id);
        if (id == 0) {
            break;
        }

        if (id < 1 || id > MAX_MENU_ITEMS) {
            printf("Invalid item ID! Please try again.\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[id - 1].name);
        scanf("%d", &quantity);

        order[*orderCount].id = id;
        order[*orderCount].quantity = quantity;
        (*orderCount)++;
        printf("Added %d x %s to your order.\n", quantity, menu[id - 1].name);
    }
}

// Function to print the receipt
void printReceipt(struct OrderItem order[], struct MenuItem menu[], int orderCount) {
    float total = 0.0;
    printf("\n---------- Receipt ----------\n");
    
    for (int i = 0; i < orderCount; i++) {
        int itemID = order[i].id;
        int qty = order[i].quantity;
        float itemTotal = menu[itemID - 1].price * qty;
        total += itemTotal;

        printf("%d x %s - $%.2f\n", qty, menu[itemID - 1].name, itemTotal);
    }

    printf("----------------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("----------------------------\n");
}