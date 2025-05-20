//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INVENTORY 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_INVENTORY];
    int size;
} Inventory;

void print_menu() {
    printf("Warehouse Management System\n");
    printf("----------------------------\n");
    printf("1. View Inventory\n");
    printf("2. Add Item to Inventory\n");
    printf("3. Remove Item from Inventory\n");
    printf("4. Update Item Quantity\n");
    printf("5. Update Item Price\n");
    printf("6. Exit\n");
}

void view_inventory(Inventory* inventory) {
    printf("Items in Inventory:\n");
    for (int i = 0; i < inventory->size; i++) {
        printf("%d. %s - Quantity: %d Price: %.2f\n", i+1, inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
}

void add_item(Inventory* inventory) {
    if (inventory->size == MAX_INVENTORY) {
        printf("Inventory is full\n");
        return;
    }
    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter item price: ");
    scanf("%f", &item.price);

    inventory->items[inventory->size] = item;
    inventory->size++;
    printf("Item added to inventory\n");
}

void remove_item(Inventory* inventory) {
    if (inventory->size == 0) {
        printf("Inventory is empty\n");
        return;
    }
    printf("Enter item index to remove: ");
    int index;
    scanf("%d", &index);
    if (index < 1 || index > inventory->size) {
        printf("Invalid item index\n");
        return;
    }
    memmove(inventory->items+index-1, inventory->items+index, (inventory->size-index)*sizeof(Item));
    inventory->size--;
    printf("Item removed from inventory\n");
}

void update_quantity(Inventory* inventory) {
    if (inventory->size == 0) {
        printf("Inventory is empty\n");
        return;
    }
    printf("Enter item index to update: ");
    int index;
    scanf("%d", &index);
    if (index < 1 || index > inventory->size) {
        printf("Invalid item index\n");
        return;
    }
    printf("Enter new quantity: ");
    int quantity;
    scanf("%d", &quantity);
    inventory->items[index-1].quantity = quantity;
    printf("Item quantity updated\n");
}

void update_price(Inventory* inventory) {
    if (inventory->size == 0) {
        printf("Inventory is empty\n");
        return;
    }
    printf("Enter item index to update: ");
    int index;
    scanf("%d", &index);
    if (index < 1 || index > inventory->size) {
        printf("Invalid item index\n");
        return;
    }
    printf("Enter new price: ");
    float price;
    scanf("%f", &price);
    inventory->items[index-1].price = price;
    printf("Item price updated\n");
}

int main() {
    Inventory inventory = { .size = 0 };
    int choice;
    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                view_inventory(&inventory);
                break;
            case 2:
                add_item(&inventory);
                break;
            case 3:
                remove_item(&inventory);
                break;
            case 4:
                update_quantity(&inventory);
                break;
            case 5:
                update_price(&inventory);
                break;
            case 6:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 6);

    return 0;
}