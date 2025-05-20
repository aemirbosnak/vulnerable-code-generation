//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define ITEM_NAME_LENGTH 30

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
} Menu;

typedef struct {
    MenuItem selectedItems[MAX_ITEMS];
    int quantities[MAX_ITEMS];
    int itemCount;
} Bill;

void initializeMenu(Menu *menu) {
    strcpy(menu->items[0].name, "Coffee");
    menu->items[0].price = 2.50;
    strcpy(menu->items[1].name, "Tea");
    menu->items[1].price = 1.75;
    strcpy(menu->items[2].name, "Sandwich");
    menu->items[2].price = 3.00;
    strcpy(menu->items[3].name, "Burger");
    menu->items[3].price = 4.50;
    strcpy(menu->items[4].name, "Pasta");
    menu->items[4].price = 5.00;
    menu->count = 5;
}

void displayMenu(Menu menu) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < menu.count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu.items[i].name, menu.items[i].price);
    }
    printf("------------------\n");
}

void addItemToBill(Bill *bill, MenuItem item, int quantity) {
    bill->selectedItems[bill->itemCount] = item;
    bill->quantities[bill->itemCount] = quantity;
    bill->itemCount++;
}

void generateBill(Bill bill) {
    float total = 0;
    printf("\n--- Your Bill ---\n");
    
    for (int i = 0; i < bill.itemCount; i++) {
        float itemTotal = bill.selectedItems[i].price * bill.quantities[i];
        printf("%s (x%d) - $%.2f\n", bill.selectedItems[i].name, bill.quantities[i], itemTotal);
        total += itemTotal;
    }
    printf("------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("------------------\n");
}

int main() {
    Menu menu;
    Bill bill;
    int choice, quantity;
    char another;

    bill.itemCount = 0;

    initializeMenu(&menu);

    do {
        displayMenu(menu);
        printf("Select an item by number (1-%d): ", menu.count);
        scanf("%d", &choice);
        
        if (choice < 1 || choice > menu.count) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        // Add item to bill
        addItemToBill(&bill, menu.items[choice - 1], quantity);

        printf("Would you like to add another item? (y/n): ");
        scanf(" %c", &another);

    } while (another == 'y' || another == 'Y');

    generateBill(bill);
    
    return 0;
}