//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int itemCount;
} Menu;

void initializeMenu(Menu *menu) {
    menu->itemCount = 5;

    // Sample menu items
    strcpy(menu->items[0].name, "Coffee");
    menu->items[0].price = 2.5;

    strcpy(menu->items[1].name, "Tea");
    menu->items[1].price = 1.5;

    strcpy(menu->items[2].name, "Sandwich");
    menu->items[2].price = 3.0;

    strcpy(menu->items[3].name, "Pizza");
    menu->items[3].price = 4.5;

    strcpy(menu->items[4].name, "Cake");
    menu->items[4].price = 2.0;
}

void displayMenu(Menu *menu) {
    printf("Menu:\n");
    for (int i = 0; i < menu->itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
}

void generateBill(Menu *menu) {
    int choice[MAX_ITEMS];
    int quantity[MAX_ITEMS];
    int itemsOrdered = 0;
    char moreItems;

    do {
        displayMenu(menu);
        printf("Enter the item number you want to order (0 to finish): ");
        int itemNumber;
        scanf("%d", &itemNumber);
        
        if (itemNumber == 0) break;

        printf("Enter quantity for %s: ", menu->items[itemNumber - 1].name);
        scanf("%d", &quantity[itemsOrdered]);
        choice[itemsOrdered] = itemNumber - 1;
        itemsOrdered++;

        printf("Do you want to order more items? (y/n): ");
        scanf(" %c", &moreItems);
    } while (moreItems == 'y' && itemsOrdered < MAX_ITEMS);

    // Generate bill
    printf("\n----- Bill -----\n");
    float total = 0.0;
    for (int i = 0; i < itemsOrdered; i++) {
        printf("%s x %d = $%.2f\n", menu->items[choice[i]].name, quantity[i], menu->items[choice[i]].price * quantity[i]);
        total += menu->items[choice[i]].price * quantity[i];
    }
    printf("Total Amount: $%.2f\n", total);
}

int main() {
    Menu cafeMenu;
    initializeMenu(&cafeMenu);

    printf("Welcome to the Cafe Billing System\n");
    generateBill(&cafeMenu);

    printf("Thank you for your visit!\n");
    return 0;
}