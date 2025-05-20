//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Inventory {
    struct Item items[100];
    int count;
};

void addItem(struct Inventory* inventory, char name[], int quantity, float price) {
    if (inventory->count < 100) {
        struct Item item;
        strcpy(item.name, name);
        item.quantity = quantity;
        item.price = price;
        inventory->items[inventory->count] = item;
        inventory->count++;
        printf("Item added successfully!\n");
    } else {
        printf("Inventory is full!\n");
    }
}

void displayInventory(struct Inventory inventory) {
    printf("Items in inventory:\n");
    for (int i = 0; i < inventory.count; i++) {
        printf("- %s (%d) - $%.2f each\n", inventory.items[i].name, inventory.items[i].quantity, inventory.items[i].price);
    }
}

void updateItem(struct Inventory* inventory, int index, int newQuantity) {
    if (index >= 0 && index < inventory->count) {
        inventory->items[index].quantity = newQuantity;
        printf("Item updated successfully!\n");
    } else {
        printf("Item index out of range!\n");
    }
}

void removeItem(struct Inventory* inventory, int index) {
    if (index >= 0 && index < inventory->count) {
        for (int i = index; i < inventory->count - 1; i++) {
            inventory->items[i] = inventory->items[i+1];
        }
        inventory->count--;
        printf("Item removed successfully!\n");
    } else {
        printf("Item index out of range!\n");
    }
}

int main() {
    struct Inventory inventory = {{}, 0};
    char name[50];
    int quantity;
    float price;
    int choice = -1;
    int index;
    int newQuantity;
    
    while(choice != 0) {
        printf("\nSelect an option:\n1. Add item\n2. Display inventory\n3. Update item\n4. Remove item\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%f", &price);
                addItem(&inventory, name, quantity, price);
                break;
            case 2:
                displayInventory(inventory);
                break;
            case 3:
                printf("Enter item index: ");
                scanf("%d", &index);
                printf("Enter new quantity: ");
                scanf("%d", &newQuantity);
                updateItem(&inventory, index, newQuantity);
                break;
            case 4:
                printf("Enter item index: ");
                scanf("%d", &index);
                removeItem(&inventory, index);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!");
        }
    }
    return 0;
}