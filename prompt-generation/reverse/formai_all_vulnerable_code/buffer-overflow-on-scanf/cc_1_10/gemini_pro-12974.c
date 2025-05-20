//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item structure
typedef struct Item {
    int code;
    char name[50];
    float price;
    int quantity;
} Item;

// Array of items
Item items[] = {
    {1, "Espresso", 2.50, 0},
    {2, "Cappuccino", 3.00, 0},
    {3, "Latte", 3.50, 0},
    {4, "Mocha", 4.00, 0},
    {5, "Americano", 2.75, 0}
};

// Number of items
int numItems = sizeof(items) / sizeof(Item);

// Function to display the menu
void displayMenu() {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", items[i].code, items[i].name, items[i].price);
    }
}

// Function to get the user's order
int getOrder() {
    int code;
    printf("Enter the code of the item you want to order: ");
    scanf("%d", &code);
    return code;
}

// Function to validate the user's order
int validateOrder(int code) {
    for (int i = 0; i < numItems; i++) {
        if (items[i].code == code) {
            return 1;
        }
    }
    return 0;
}

// Function to get the quantity of the item ordered
int getQuantity() {
    int quantity;
    printf("Enter the quantity of the item you want to order: ");
    scanf("%d", &quantity);
    return quantity;
}

// Function to add the item to the order
void addToOrder(int code, int quantity) {
    for (int i = 0; i < numItems; i++) {
        if (items[i].code == code) {
            items[i].quantity += quantity;
        }
    }
}

// Function to display the order
void displayOrder() {
    printf("Your order:\n");
    for (int i = 0; i < numItems; i++) {
        if (items[i].quantity > 0) {
            printf("%d. %s - $%.2f (%d)\n", items[i].code, items[i].name, items[i].price, items[i].quantity);
        }
    }
}

// Function to calculate the total price of the order
float calculateTotal() {
    float total = 0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price * items[i].quantity;
    }
    return total;
}

// Function to print the receipt
void printReceipt(float total) {
    printf("Receipt:\n");
    displayOrder();
    printf("Total: $%.2f\n", total);
}

// Main function
int main() {
    // Display the menu
    displayMenu();

    // Get the user's order
    int code = getOrder();

    // Validate the user's order
    if (validateOrder(code)) {
        // Get the quantity of the item ordered
        int quantity = getQuantity();

        // Add the item to the order
        addToOrder(code, quantity);

        // Display the order
        displayOrder();

        // Calculate the total price of the order
        float total = calculateTotal();

        // Print the receipt
        printReceipt(total);
    } else {
        printf("Invalid item code. Please try again.\n");
    }

    return 0;
}