//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct WarehouseItem {
    char name[50];
    int quantity;
    float price;
} WarehouseItem;

WarehouseItem warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Sorry, we are out of room! The warehouse is hoarder-approved!\n");
        return;
    }

    WarehouseItem newItem;
    printf("Enter the name of the item (avoid names like 'Alfred' or 'The Great Marketo' - it's a warehouse, not a theater): ");
    scanf("%s", newItem.name);
    printf("Enter the quantity of %s (Hint: Less than 1000 unless you’re a distributor in need of therapy): ", newItem.name);
    scanf("%d", &newItem.quantity);
    printf("Enter the price of %s (Hint: This isn't a flea market - please be sensible): ", newItem.name);
    scanf("%f", &newItem.price);

    warehouse[itemCount] = newItem;
    itemCount++;

    printf("Added %s to the warehouse. Total items: %d.\n", newItem.name, itemCount);
}

void displayItems() {
    if (itemCount == 0) {
        printf("The warehouse is as empty as my soul after a long day... but you can start adding items!\n");
        return;
    }

    printf("Here's what we’ve got in our 'high-end' warehouse:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d: Item: %s | Quantity: %d | Price: $%.2f\n", i + 1, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

void removeItem() {
    if (itemCount == 0) {
        printf("You can't remove something that's already missing! Much like my motivation.\n");
        return;
    }

    int index;
    printf("Enter item number to remove (Hint: A number between 1 and %d): ", itemCount);
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Invalid selection! You don’t get a participation trophy for that move!\n");
        return;
    }

    for (int i = index - 1; i < itemCount - 1; i++) {
        warehouse[i] = warehouse[i + 1];
    }
    itemCount--;
    printf("Removed item number %d. It's gone like that donut I was saving for later...\n", index);
}

void menu() {
    int choice;
    while (1) {
        printf("\nWelcome to the Wacky Warehouse Management System!\n");
        printf("Please choose an option:\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Remove Item\n");
        printf("4. Exit (but who would want to leave such a fun place?)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                printf("Exiting... but remember, we will always treasure the memories we’ve made...\n");
                return;
            default:
                printf("Oops! That's not a valid option. Maybe ask a magic 8-ball next time!\n");
        }
    }
}

int main() {
    menu();
    return 0;
}