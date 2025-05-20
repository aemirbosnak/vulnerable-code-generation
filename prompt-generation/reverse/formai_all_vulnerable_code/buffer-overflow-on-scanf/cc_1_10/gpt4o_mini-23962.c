//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct {
    char name[30];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int count;
} Menu;

void initializeMenu(Menu *menu) {
    menu->count = 5;
    strcpy(menu->items[0].name, "Coffee");
    menu->items[0].price = 2.5;
    
    strcpy(menu->items[1].name, "Tea");
    menu->items[1].price = 2.0;
    
    strcpy(menu->items[2].name, "Sandwich");
    menu->items[2].price = 5.0;
    
    strcpy(menu->items[3].name, "Cake");
    menu->items[3].price = 3.5;
    
    strcpy(menu->items[4].name, "Juice");
    menu->items[4].price = 3.0;
}

void displayMenu(const Menu *menu) {
    printf("Welcome to the Cafe!\n");
    printf("Menu:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < menu->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
    printf("---------------------------------------------------\n");
}

void takeOrder(Menu *menu, float *total) {
    int choice, quantity;
    char continueOrdering;

    do {
        printf("Enter the item number to order (0 to finish): ");
        scanf("%d", &choice);

        if (choice == 0) break;

        if (choice < 1 || choice > menu->count) {
            printf("Invalid choice, please select again.\n");
            continue;
        }

        printf("Enter the quantity for %s: ", menu->items[choice - 1].name);
        scanf("%d", &quantity);

        if (quantity < 1) {
            printf("Invalid quantity, please try again.\n");
            continue;
        }

        *total += (menu->items[choice - 1].price * quantity);
        printf("Order added: %s x %d\n", menu->items[choice - 1].name, quantity);
        
        printf("Do you want to order more items (y/n)? ");
        while ((getchar()) != '\n'); // clear the input buffer
        scanf("%c", &continueOrdering);
    } while (continueOrdering == 'y' || continueOrdering == 'Y');
}

void generateBill(float total) {
    printf("Your total bill is: $%.2f\n", total);
}

int main() {
    Menu cafeMenu;
    float totalBill = 0.0;

    initializeMenu(&cafeMenu);
    displayMenu(&cafeMenu);
    takeOrder(&cafeMenu, &totalBill);
    generateBill(totalBill);

    return 0;
}