//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }
    
    Item newItem;
    newItem.id = itemCount + 1; // Set ID based on current count
    
    printf("Enter name of the item: ");
    scanf(" %[^\n]", newItem.name);
    
    printf("Enter quantity of the item: ");
    scanf("%d", &newItem.quantity);
    
    printf("Enter price of the item: ");
    scanf("%f", &newItem.price);
    
    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void viewInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateItem() {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > itemCount) {
        printf("Invalid ID!\n");
        return;
    }
    
    Item *item = &inventory[id - 1];
    
    printf("Current Name: %s\n", item->name);
    printf("Enter new name (or press enter to keep current): ");
    char newName[50];
    scanf(" %[^\n]", newName);
    if (strlen(newName) > 0) {
        strcpy(item->name, newName);
    }
    
    printf("Current Quantity: %d\n", item->quantity);
    printf("Enter new quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        item->quantity = newQuantity;
    }
    
    printf("Current Price: %.2f\n", item->price);
    printf("Enter new price (or -1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice != -1) {
        item->price = newPrice;
    }
    
    printf("Item updated successfully!\n");
}

void deleteItem() {
    int id;
    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > itemCount) {
        printf("Invalid ID!\n");
        return;
    }
    
    for (int i = id - 1; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    itemCount--;
    printf("Item deleted successfully!\n");
}

void searchItem() {
    char name[50];
    printf("Enter the name of the item to search: ");
    scanf(" %[^\n]", name);
    
    printf("\nSearch Results:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------------------------\n");
    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strstr(inventory[i].name, name) != NULL) {
            printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No items found with the name '%s'.\n", name);
    }
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. View Inventory\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Search Item\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                searchItem();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}