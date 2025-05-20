//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

void initializeInventory(Inventory* inv) {
    inv->count = 0;
}

void addItem(Inventory* inv){
    if (inv->count >= MAX_ITEMS) {
        printf("Inventory full!\n");
        return;
    }
    Item newItem;
    newItem.id = inv->count + 1;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    inv->items[inv->count++] = newItem;
    printf("Item added: %s\n", newItem.name);
}

void viewItems(const Inventory* inv) {
    if (inv->count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("Inventory:\n");
    for (int i = 0; i < inv->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n",
               inv->items[i].id, inv->items[i].name,
               inv->items[i].quantity, inv->items[i].price);
    }
}

void searchItem(const Inventory* inv) {
    char searchName[NAME_LEN];
    printf("Enter item name to search: ");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].name, searchName) == 0) {
            printf("Item found - ID: %d, Quantity: %d, Price: $%.2f\n",
                   inv->items[i].id, inv->items[i].quantity,
                   inv->items[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item not found.\n");
    }
}

void updateItem(Inventory* inv) {
    int itemId;
    printf("Enter item ID to update: ");
    scanf("%d", &itemId);
    if (itemId <= 0 || itemId > inv->count) {
        printf("Invalid ID.\n");
        return;
    }
    Item* item = &inv->items[itemId - 1];
    printf("Updating item: %s\n", item->name);
    printf("Current quantity: %d, Current price: $%.2f\n",
           item->quantity, item->price);
    printf("Enter new quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter new price: ");
    scanf("%f", &item->price);
    printf("Item updated!\n");
}

void deleteItem(Inventory* inv) {
    int itemId;
    printf("Enter item ID to delete: ");
    scanf("%d", &itemId);
    if (itemId <= 0 || itemId > inv->count) {
        printf("Invalid ID.\n");
        return;
    }
    for (int i = itemId - 1; i < inv->count - 1; i++) {
        inv->items[i] = inv->items[i + 1];
    }
    inv->count--;
    printf("Item deleted.\n");
}

void menu(Inventory* inv) {
    int choice;
    do {
        printf("\n--- Inventory Menu ---\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addItem(inv); break;
            case 2: viewItems(inv); break;
            case 3: searchItem(inv); break;
            case 4: updateItem(inv); break;
            case 5: deleteItem(inv); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid option! Try again.\n");
        }
    } while (choice != 6);
}

int main() {
    Inventory inventory;
    initializeInventory(&inventory);
    menu(&inventory);
    return 0;
}