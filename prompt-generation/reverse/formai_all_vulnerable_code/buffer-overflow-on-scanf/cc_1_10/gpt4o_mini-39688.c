//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int menuCount = 0;

void addMenuItem(char *name, float price) {
    strcpy(menu[menuCount].name, name);
    menu[menuCount].price = price;
    menu[menuCount].quantity = 0; // initial quantity
    menuCount++;
}

void displayMenu() {
    printf("\n--- Café Bliss Menu ---\n");
    printf("ID\tItem\t\tPrice\n");
    for(int i = 0; i < menuCount; i++) {
        printf("%d\t%s\t%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("-----------------------\n");
}

void takeOrder() {
    int choice, quantity;
    while (1) {
        displayMenu();
        printf("Enter item ID to order (0 to finish): ");
        scanf("%d", &choice);
        if (choice == 0) break; // end of order

        if (choice < 1 || choice > menuCount) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[choice - 1].name);
        scanf("%d", &quantity);
        
        if (quantity < 1) {
            printf("Quantity must be at least 1. Try again!\n");
            continue;
        }

        menu[choice - 1].quantity += quantity;
        printf("Added %d x %s to your order.\n", quantity, menu[choice - 1].name);
    }
}

void printBill() {
    float total = 0.0;
    printf("\n--- Your Bill ---\n");
    printf("Item\t\tQuantity\tPrice\n");
    for(int i = 0; i < menuCount; i++) {
        if (menu[i].quantity > 0) {
            float itemTotal = menu[i].quantity * menu[i].price;
            printf("%s\t\t%d\t\t%.2f\n", menu[i].name, menu[i].quantity, itemTotal);
            total += itemTotal;
        }
    }
    printf("-----------------------------\n");
    printf("Total Amount: %.2f\n", total);
    printf("-----------------------------\n");
}

int main() {
    // Initialize the menu
    addMenuItem("Espresso", 3.00);
    addMenuItem("Cappuccino", 3.50);
    addMenuItem("Latte", 4.00);
    addMenuItem("Mocha", 4.50);
    addMenuItem("Tea", 2.00);
    addMenuItem("Sandwich", 5.00);
    addMenuItem("Cake", 4.00);
    
    printf("Welcome to Café Bliss!\n");
    
    takeOrder(); // take user's order
    printBill(); // print the final bill
    
    return 0;
}