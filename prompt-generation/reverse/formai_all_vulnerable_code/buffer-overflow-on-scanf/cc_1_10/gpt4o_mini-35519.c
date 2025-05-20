//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

// Structure to hold menu item information
struct MenuItem {
    char name[30];
    float price;
};

// Function to display the menu
void displayMenu(struct MenuItem menu[], int itemCount) {
    printf("Welcome to the Cheerful Café!\n");
    printf("Here is our delightful menu:\n\n");
    printf("%-20s %-10s\n", "Item", "Price");
    printf("------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-20s $%.2f\n", menu[i].name, menu[i].price);
    }
    printf("------------------------------\n");
}

// Function to place an order and calculate the bill
void placeOrder(struct MenuItem menu[], int itemCount) {
    int choice, quantity;
    float total = 0;
    
    printf("Please enter the item number you want to order (1 to %d) or 0 to finish: ", itemCount);
    while (1) {
        scanf("%d", &choice);
        if (choice == 0) break;
        
        if (choice < 1 || choice > itemCount) {
            printf("Oops! Please choose a valid item number.\n");
            continue;
        }
        
        printf("You chose %s. How many would you like? ", menu[choice-1].name);
        scanf("%d", &quantity);
        
        if (quantity < 1) {
            printf("Invalid quantity! Please choose at least 1.\n");
            continue;
        }
        
        total += menu[choice-1].price * quantity;
        printf("Great choice! Your current total is: $%.2f\n", total);
        printf("Please enter the next item number (1 to %d) or 0 to finish: ", itemCount);
    }
    
    printf("Your total bill is: $%.2f. Thank you for visiting the Cheerful Café! ☕\n", total);
}

int main() {
    struct MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50},
        {"Tea", 1.75},
        {"Sandwich", 3.00},
        {"Muffin", 2.25},
        {"Salad", 4.00},
        {"Juice", 2.50},
        {"Pastry", 3.50},
        {"Pasta", 5.00},
        {"Pizza", 6.50},
        {"Ice Cream", 2.00}
    };
    
    int itemCount = 10; 
    
    // Show the menu and place an order
    displayMenu(menu, itemCount);
    placeOrder(menu, itemCount);
    
    return 0;
}