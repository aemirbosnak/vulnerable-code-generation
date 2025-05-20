//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define variables for menu items
int menuChoice, quantity;
float totalPrice = 0.0;

// Define struct for menu item
typedef struct menuItem {
    char name[20];
    float price;
} MenuItem;

// Create array of menu items
MenuItem menu[5] = {
    {"Coffee", 1.99},
    {"Tea", 1.49},
    {"Bagel", 2.99},
    {"Muffin", 1.99},
    {"Croissant", 2.49}
};

// Create function to display menu and get user's choice
int getMenuChoice() {
    int choice;
    printf("Welcome to Puzzler's Cafe!\n\n");
    printf("Menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s: $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    printf("\nPlease enter your choice (1-5): ");
    scanf("%d", &choice);
    return choice;
}

// Create function to get user's desired quantity
int getQuantity() {
    int q;
    printf("\nHow many would you like: ");
    scanf("%d", &q);
    return q;
}

// Create function to add item to order and calculate total price
void addToOrder(int choice, int quantity) {
    totalPrice += (menu[choice-1].price * quantity);
}

// Create function to display order summary and total price
void displayOrder() {
    printf("\nOrder Summary:\n");
    for (int i = 0; i < 5; i++) {
        if (menu[i].price * quantity != 0) {
            printf("%d %s\n", quantity, menu[i].name);
        }
    }
    printf("\nTotal price: $%.2f\n", totalPrice);
}

int main() {
    // Loop through program until user chooses to exit
    while(1) {
        // Get user's menu choice and quantity
        menuChoice = getMenuChoice();
        if (menuChoice == 5) {
            printf("\nGoodbye!\n");
            return 0;
        }
        quantity = getQuantity();
        addToOrder(menuChoice, quantity);
        displayOrder();
    }
    return 0;
}