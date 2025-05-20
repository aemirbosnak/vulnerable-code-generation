//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 30

// Structure to represent a menu item
typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

// Structure to represent an order
typedef struct {
    MenuItem item;
    int quantity;
} Order;

// Function to display the menu
void displayMenu(MenuItem menu[], int itemCount) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("------------------\n");
}

// Function to calculate the total bill
float calculateTotal(Order orders[], int orderCount) {
    float total = 0;
    for (int i = 0; i < orderCount; i++) {
        total += orders[i].item.price * orders[i].quantity;
    }
    return total;
}

// Function to print the bill
void printBill(Order orders[], int orderCount) {
    printf("\n--- Your Bill ---\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%s (x%d) - $%.2f\n", orders[i].item.name, orders[i].quantity, 
               orders[i].item.price * orders[i].quantity);
    }
    printf("------------------\n");
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Espresso", 2.50},
        {"Latte", 3.00},
        {"Cappuccino", 3.50},
        {"Black Coffee", 2.00},
        {"Tea", 1.50},
        {"Sandwich", 4.00},
        {"Cake", 2.00},
        {"Cookies", 1.00}
    };

    int itemCount = 8; // Number of items on the menu
    Order orders[MAX_ITEMS];
    int orderCount = 0;
    char choice;

    printf("Welcome to the Brave Cafe Billing System!\n");

    do {
        displayMenu(menu, itemCount);

        int itemNumber, quantity;
        printf("Enter item number to order (1-%d): ", itemCount);
        scanf("%d", &itemNumber);
        
        if (itemNumber < 1 || itemNumber > itemCount) {
            printf("Invalid item number! Please try again.\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[itemNumber - 1].name);
        scanf("%d", &quantity);
        
        if (quantity < 1) {
            printf("Quantity must be at least 1!\n");
            continue;
        }

        // Add order to orders array
        orders[orderCount].item = menu[itemNumber - 1];
        orders[orderCount].quantity = quantity;
        orderCount++;

        printf("Do you want to order another item? (y/n): ");
        getchar();  // To consume newline
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');

    // Calculate and print the total bill
    float total = calculateTotal(orders, orderCount);
    printBill(orders, orderCount);
    printf("Total Amount: $%.2f\n", total);
    printf("Thank you for visiting the Brave Cafe!\n");

    return 0;
}