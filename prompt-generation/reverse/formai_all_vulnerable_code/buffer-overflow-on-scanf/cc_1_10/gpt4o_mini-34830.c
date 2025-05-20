//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int itemCount;
} Menu;

typedef struct {
    char name[NAME_LENGTH];
    float totalBill;
} Customer;

void initializeMenu(Menu *menu) {
    strcpy(menu->items[0].name, "Espresso");
    menu->items[0].price = 2.50;
    
    strcpy(menu->items[1].name, "Latte");
    menu->items[1].price = 3.00;
    
    strcpy(menu->items[2].name, "Cappuccino");
    menu->items[2].price = 3.50;
    
    strcpy(menu->items[3].name, "Tea");
    menu->items[3].price = 1.50;

    // Additional items can be added here.
    menu->itemCount = 4;
}

void displayMenu(Menu *menu) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < menu->itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
    printf("------------------\n");
}

void takeOrder(Menu *menu, Customer *customer) {
    int choice, quantity;
    customer->totalBill = 0;

    printf("\nEnter your name: ");
    scanf("%s", customer->name);

    while (1) {
        printf("Select item by number (1 to %d) or 0 to finish: ", menu->itemCount);
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > menu->itemCount) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        
        printf("Enter quantity for %s: ", menu->items[choice - 1].name);
        scanf("%d", &quantity);
        
        customer->totalBill += menu->items[choice - 1].price * quantity;
        printf("%d x %s added to your order.\n", quantity, menu->items[choice - 1].name);
    }
}

void printBill(Customer *customer) {
    printf("\n--- Receipt for %s ---\n", customer->name);
    printf("Total Bill: $%.2f\n", customer->totalBill);
    printf("------------------------\n");
}

void thankYouMessage() {
    printf("\nThank you for visiting our cafe!\n");
    printf("We hope to see you again soon!\n");
}

int main() {
    Menu cafeMenu;
    Customer currentCustomer;

    initializeMenu(&cafeMenu);
    displayMenu(&cafeMenu);
    takeOrder(&cafeMenu, &currentCustomer);
    
    if (currentCustomer.totalBill > 0) {
        printBill(&currentCustomer);
    } else {
        printf("\nNo items ordered. Exiting...\n");
        return 0;
    }

    thankYouMessage();
    return 0;
}