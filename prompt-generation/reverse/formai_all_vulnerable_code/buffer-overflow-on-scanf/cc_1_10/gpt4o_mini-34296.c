//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 10
#define MAX_ORDER_ITEMS 20

// Structure to hold menu item details
typedef struct {
    char name[30];
    float price;
} MenuItem;

// Structure to hold order details
typedef struct {
    char itemName[30];
    int quantity;
} OrderItem;

MenuItem menu[MAX_MENU_ITEMS] = {
    {"Coffee", 2.50},
    {"Tea", 2.00},
    {"Sandwich", 5.00},
    {"Burger", 7.00},
    {"Pasta", 6.50},
    {"Juice", 3.00},
    {"Soda", 1.50},
    {"Cake", 4.00},
    {"Brownie", 3.50},
    {"Pizza", 8.00}
};

OrderItem order[MAX_ORDER_ITEMS];
int orderCount = 0;

void displayMenu() {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < MAX_MENU_ITEMS; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void addItemToOrder() {
    int choice, quantity;
    displayMenu();
    printf("Enter the menu item number you want to order: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > MAX_MENU_ITEMS) {
        printf("Invalid choice, please try again.\n");
        return;
    }
    
    printf("Enter quantity for %s: ", menu[choice - 1].name);
    scanf("%d", &quantity);
    
    strcpy(order[orderCount].itemName, menu[choice - 1].name);
    order[orderCount].quantity = quantity;
    orderCount++;
    
    printf("Added %d x %s to your order.\n", quantity, menu[choice - 1].name);
}

void removeItemFromOrder() {
    char itemName[30];
    printf("Enter the name of the item you want to remove: ");
    scanf("%s", itemName);
    
    for (int i = 0; i < orderCount; i++) {
        if (strcmp(order[i].itemName, itemName) == 0) {
            printf("Removed %d x %s from your order.\n", order[i].quantity, order[i].itemName);
            for (int j = i; j < orderCount - 1; j++) {
                order[j] = order[j + 1];
            }
            orderCount--;
            return;
        }
    }
    
    printf("Item not found in your order.\n");
}

void viewBill() {
    float total = 0.0;
    printf("\n--- Your Bill ---\n");
    for (int i = 0; i < orderCount; i++) {
        float itemTotal = order[i].quantity * menu[i].price;
        printf("%s x %d - $%.2f\n", order[i].itemName, order[i].quantity, itemTotal);
        total += itemTotal;
    }
    printf("Total Amount: $%.2f\n", total);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Cafe Billing System ---\n");
        printf("1. Add item to order\n");
        printf("2. Remove item from order\n");
        printf("3. View Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItemToOrder();
                break;
            case 2:
                removeItemFromOrder();
                break;
            case 3:
                viewBill();
                break;
            case 4:
                printf("Thank you for visiting! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}