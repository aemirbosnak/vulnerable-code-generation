//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int itemCount;
} Menu;

typedef struct {
    float totalBill;
    int itemCount;
} Bill;

void displayMenu(Menu *menu) {
    printf("\n\t==== Cafe Menu ====\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < menu->itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
    printf("--------------------------------------------------\n");
}

void placeOrder(Menu *menu, Bill *bill) {
    int choice;
    while (1) {
        printf("Select the item number to order (0 to finish ordering): ");
        scanf("%d", &choice);
        if (choice == 0) break;

        if (choice < 1 || choice > menu->itemCount) {
            printf("Invalid choice. Please select again.\n");
            continue;
        }

        int quantity;
        printf("Enter quantity for %s: ", menu->items[choice - 1].name);
        scanf("%d", &quantity);
        
        if (quantity < 1) {
            printf("Invalid quantity. Please enter a positive number.\n");
            continue;
        }

        float itemTotal = menu->items[choice - 1].price * quantity;
        printf("Added %d x %s ($%.2f) to the bill.\n", quantity, menu->items[choice - 1].name, itemTotal);
        
        bill->totalBill += itemTotal;
        bill->itemCount += quantity;
    }
}

void printBill(Bill *bill) {
    printf("\n\t==== Your Bill ====\n");
    printf("--------------------------------------------------\n");
    printf("Total items ordered: %d\n", bill->itemCount);
    printf("Total bill amount: $%.2f\n", bill->totalBill);
    printf("--------------------------------------------------\n");
}

void addMenuItem(Menu *menu) {
    if (menu->itemCount >= MAX_ITEMS) {
        printf("Menu is full! Cannot add more items.\n");
        return;
    }
    
    MenuItem newItem;
    printf("Enter the name of the menu item: ");
    scanf(" %[^\n]s", newItem.name);
    
    printf("Enter the price of the item: ");
    scanf("%f", &newItem.price);

    newItem.quantity = 0;  // Initially, quantity in menu items is not used
    menu->items[menu->itemCount] = newItem;
    menu->itemCount++;
    
    printf("Menu item '%s' added successfully!\n", newItem.name);
}

void manageMenu(Menu *menu) {
    int choice;
    while (1) {
        printf("\n\t==== Manage Menu ====\n");
        printf("1. Add Menu Item\n");
        printf("2. Display Menu\n");
        printf("3. Return to Main Menu\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMenuItem(menu);
                break;
            case 2:
                displayMenu(menu);
                break;
            case 3:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

int main() {
    Menu menu;
    Bill bill;
    
    menu.itemCount = 0;
    bill.totalBill = 0;
    bill.itemCount = 0;

    while (1) {
        printf("\n\t==== Welcome to Cafe ====\n");
        printf("1. Manage Menu\n");
        printf("2. Place Order\n");
        printf("3. Exit\n");
        printf("Select your option: ");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                manageMenu(&menu);
                break;
            case 2:
                if (menu.itemCount == 0) {
                    printf("Menu is empty! Please add items to the menu first.\n");
                } else {
                    displayMenu(&menu);
                    placeOrder(&menu, &bill);
                    printBill(&bill);
                }
                break;
            case 3:
                printf("Thank you for visiting! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}