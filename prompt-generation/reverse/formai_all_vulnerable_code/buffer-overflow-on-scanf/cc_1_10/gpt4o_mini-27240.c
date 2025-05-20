//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent menu items
typedef struct {
    int id;
    char name[30];
    float price;
} MenuItem;

// Structure to represent an order
typedef struct {
    int itemId;
    int quantity;
} Order;

// Function prototypes
void displayMenu(MenuItem menu[], int menuSize);
float calculateTotal(Order orders[], int orderCount, MenuItem menu[], int menuSize);
void takeOrder(Order orders[], int *orderCount, MenuItem menu[], int menuSize);
void printReceipt(Order orders[], int orderCount, MenuItem menu[], int menuSize);

int main() {
    // Initialize menu items
    MenuItem menu[] = {
        {1, "Espresso", 2.50},
        {2, "Latte", 3.00},
        {3, "Cappuccino", 3.50},
        {4, "Hot Chocolate", 3.00},
        {5, "Tea", 2.00}
    };
    
    int menuSize = sizeof(menu) / sizeof(menu[0]);
    Order orders[100];  // Max 100 orders
    int orderCount = 0;
    char choice;

    printf("Welcome to the C Cafe Billing System\n");

    do {
        displayMenu(menu, menuSize);
        takeOrder(orders, &orderCount, menu, menuSize);
        printf("Would you like to take another order? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printReceipt(orders, orderCount, menu, menuSize);

    return 0;
}

// Function to display menu items
void displayMenu(MenuItem menu[], int menuSize) {
    printf("Menu:\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// Function to take order from the user
void takeOrder(Order orders[], int *orderCount, MenuItem menu[], int menuSize) {
    int itemId, quantity;
    printf("Enter item ID to order: ");
    scanf("%d", &itemId);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Verify item ID
    if (itemId > 0 && itemId <= menuSize) {
        orders[*orderCount].itemId = itemId;
        orders[*orderCount].quantity = quantity;
        (*orderCount)++;
        printf("Added %d x %s to your order.\n", quantity, menu[itemId - 1].name);
    } else {
        printf("Invalid item ID. Please try again.\n");
    }
}

// Function to calculate total cost
float calculateTotal(Order orders[], int orderCount, MenuItem menu[], int menuSize) {
    float total = 0;
    for (int i = 0; i < orderCount; i++) {
        int itemId = orders[i].itemId - 1;  // Adjusting index
        total += menu[itemId].price * orders[i].quantity;
    }
    return total;
}

// Function to print the receipt
void printReceipt(Order orders[], int orderCount, MenuItem menu[], int menuSize) {
    printf("\n--- Receipt ---\n");
    for (int i = 0; i < orderCount; i++) {
        int itemId = orders[i].itemId - 1;  // Adjusting index
        printf("%s x %d - $%.2f\n", menu[itemId].name, orders[i].quantity, menu[itemId].price * orders[i].quantity);
    }
    float total = calculateTotal(orders, orderCount, menu, menuSize);
    printf("Total Amount: $%.2f\n", total);
    printf("----------------\nThank you for visiting C Cafe!\n");
}