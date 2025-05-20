//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
    float price;
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int item_count = 0;

void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Inventory full. Cannot add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    inventory[item_count++] = newItem;
    printf("Item '%s' added to inventory.\n", newItem.name);
}

void display_inventory() {
    if (item_count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("Inventory:\n");
    printf("%-20s %-10s %-10s\n", "Item Name", "Price", "Quantity");
    for (int i = 0; i < item_count; i++) {
        printf("%-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void sell_item() {
    char item_name[30];
    int quantity;
    printf("Enter item name to sell: ");
    scanf("%s", item_name);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(inventory[i].name, item_name) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Sold %d of '%s'. Remaining stock: %d\n", quantity, item_name, inventory[i].quantity);
                return;
            } else {
                printf("Not enough stock for '%s'. Available: %d\n", item_name, inventory[i].quantity);
                return;
            }
        }
    }
    printf("Item '%s' not found in inventory.\n", item_name);
}

void menu() {
    int choice;
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Sell Item\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                sell_item();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}