//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for menu items
enum MenuItem {
    COFFEE_PLAIN,
    COFFEE_MOCHA,
    COFFEE_LATTE,
    TEA_BLACK,
    TEA_GREEN,
    TEA_HERBAL
};

// Constants for menu prices
const float MENU_PRICES[] = {
    1.50, // COFFEE_PLAIN
    2.00, // COFFEE_MOCHA
    2.50, // COFFEE_LATTE
    1.00, // TEA_BLACK
    1.25, // TEA_GREEN
    1.50  // TEA_HERBAL
};

// Constants for menu names
const char *MENU_NAMES[] = {
    "Coffee (Plain)",
    "Coffee (Mocha)",
    "Coffee (Latte)",
    "Tea (Black)",
    "Tea (Green)",
    "Tea (Herbal)"
};

// Function to get menu item name
const char *getMenuItemName(enum MenuItem item) {
    return MENU_NAMES[item];
}

// Function to get menu item price
float getMenuItemPrice(enum MenuItem item) {
    return MENU_PRICES[item];
}

// Function to print menu
void printMenu() {
    printf("Menu:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d. %s - $%.2f\n", i + 1, getMenuItemName(i), getMenuItemPrice(i));
    }
}

// Function to get user input for menu item
enum MenuItem getUserMenuItem() {
    int input;
    printf("Enter the number of the item you want: ");
    scanf("%d", &input);
    return input - 1; // Adjust for 0-based array
}

// Function to get user input for quantity
int getUserQuantity() {
    int quantity;
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    return quantity;
}

// Function to calculate total price
float calculateTotalPrice(enum MenuItem item, int quantity) {
    return getMenuItemPrice(item) * quantity;
}

// Function to print receipt
void printReceipt(enum MenuItem item, int quantity, float totalPrice) {
    printf("Receipt:\n");
    printf("Item: %s\n", getMenuItemName(item));
    printf("Quantity: %d\n", quantity);
    printf("Total: $%.2f\n", totalPrice);
}

// Main function
int main() {
    // Print a welcome message
    printf("Welcome to the Cafe Billing System!\n");
    // Print the menu
    printMenu();
    
    // Get user input for menu item
    enum MenuItem item = getUserMenuItem();
    
    // Get user input for quantity
    int quantity = getUserQuantity();
    
    // Calculate total price
    float totalPrice = calculateTotalPrice(item, quantity);
    
    // Print receipt
    printReceipt(item, quantity, totalPrice);
    
    // Print a thank you message
    printf("Thank you for your patronage!\n");

    return 0;
}