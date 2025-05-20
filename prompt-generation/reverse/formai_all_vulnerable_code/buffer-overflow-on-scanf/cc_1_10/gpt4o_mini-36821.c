//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} MenuItem;

typedef struct {
    MenuItem items[MAX_ITEMS];
    int itemCount;
} CafeMenu;

void addMenuItem(CafeMenu *menu, const char *name, float price) {
    if (menu->itemCount < MAX_ITEMS) {
        strcpy(menu->items[menu->itemCount].name, name);
        menu->items[menu->itemCount].price = price;
        menu->itemCount++;
    } else {
        printf("Menu is full, cannot add more items.\n");
    }
}

void displayMenu(const CafeMenu *menu) {
    printf("\nCafe Menu:\n");
    for (int i = 0; i < menu->itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu->items[i].name, menu->items[i].price);
    }
}

void printBill(float total) {
    printf("\n---------- Bill ----------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("--------------------------\n");
}

int main() {
    CafeMenu menu = { .itemCount = 0 };
    char moreItems = 'y';
    int choice;
    float totalAmount = 0.0;

    // Add some default items to the menu
    addMenuItem(&menu, "Coffee", 2.50);
    addMenuItem(&menu, "Tea", 1.75);
    addMenuItem(&menu, "Sandwich", 5.00);
    addMenuItem(&menu, "Cake", 3.25);
    addMenuItem(&menu, "Juice", 2.10);

    while (moreItems == 'y') {
        displayMenu(&menu);
        printf("Select an item by number (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break; // Exit the loop
        } else if (choice < 1 || choice > menu.itemCount) {
            printf("Invalid choice, please try again.\n");
            continue; // Prompt again
        }

        totalAmount += menu.items[choice - 1].price;
        printf("You selected: %s - $%.2f\n", menu.items[choice - 1].name, menu.items[choice - 1].price);
        printf("Do you want to order more items? (y/n): ");
        getchar(); // To consume newline character left in buffer
        scanf("%c", &moreItems);
    }

    printBill(totalAmount);
    return 0;
}