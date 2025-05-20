//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Inventory;

void initInventory(Inventory* inv) {
    inv->itemCount = 0;
}

void addItem(Inventory* inv) {
    if (inv->itemCount >= MAX_ITEMS) {
        printf("Alas! The inventory cannot hold more wares!\n");
        return;
    }
    
    Item newItem;
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    
    printf("Enter the quantity of %s: ", newItem.name);
    scanf("%d", &newItem.quantity);
    
    printf("Enter the price of %s: ", newItem.name);
    scanf("%f", &newItem.price);
    
    inv->items[inv->itemCount] = newItem;
    inv->itemCount++;
    printf("Huzzah! %s added to the inventory!\n", newItem.name);
}

void displayInventory(const Inventory* inv) {
    if (inv->itemCount == 0) {
        printf("The inventory is empty! No wares for sale.\n");
        return;
    }
    
    printf("Current Inventory:\n");
    for (int i = 0; i < inv->itemCount; i++) {
        printf("%d. %s - Quantity: %d, Price: %.2f gold coins\n",
               i + 1, inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

void removeItem(Inventory* inv) {
    if (inv->itemCount == 0) {
        printf("The inventory is empty! Nothing to remove.\n");
        return;
    }
    
    int itemNumber;
    displayInventory(inv);
    printf("Which item wouldst thou like to remove (enter the number)? ");
    scanf("%d", &itemNumber);
    
    if (itemNumber < 1 || itemNumber > inv->itemCount) {
        printf("That number is invalid, no item removed!\n");
        return;
    }

    for (int i = itemNumber - 1; i < inv->itemCount - 1; i++) {
        inv->items[i] = inv->items[i + 1];
    }

    inv->itemCount--;
    printf("Pray forgive me, item number %d hath been removed from the inventory!\n", itemNumber);
}

void merchantMenu() {
    printf("Welcome to the Merchant's Inventory System!\n");
    printf("1. Add Item\n");
    printf("2. Display Inventory\n");
    printf("3. Remove Item\n");
    printf("4. Exit\n");
}

int main() {
    Inventory inventory;
    initInventory(&inventory);
    int choice;

    while (1) {
        merchantMenu();
        printf("What dost thou desire to do? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&inventory);
                break;
            case 2:
                displayInventory(&inventory);
                break;
            case 3:
                removeItem(&inventory);
                break;
            case 4:
                printf("Farewell, dear merchant! Until we meet again!\n");
                return 0;
            default:
                printf("Thou hast chosen an invalid option. Try again!\n");
        }
    }

    return 0;
}