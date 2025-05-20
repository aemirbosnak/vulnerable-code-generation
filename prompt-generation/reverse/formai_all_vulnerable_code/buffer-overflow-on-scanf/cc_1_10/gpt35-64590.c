//FormAI DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

struct item {
    char name[50];
    int id;
    float price;
    int quantity;
};

void displayMenu();
void displayInventory(struct item inventory[MAX_ITEMS], int count);
void addNewItem(struct item inventory[MAX_ITEMS], int *count);
void updateItem(struct item inventory[MAX_ITEMS], int count);
void deleteItem(struct item inventory[MAX_ITEMS], int *count);

int main() {
    struct item inventory[MAX_ITEMS];
    int count = 0;
    int choice;
    
    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                displayInventory(inventory, count);
                break;
                
            case 2:
                addNewItem(inventory, &count);
                break;
                
            case 3:
                updateItem(inventory, count);
                break;
                
            case 4:
                deleteItem(inventory, &count);
                break;
                
            case 5:
                printf("Exiting program.\n");
                exit(0);
                
            default:
                printf("Invalid choice.\n");    
        }
    }
    
    return 0;
}

// Displays the main menu.
void displayMenu() {
    printf("\n--- Product Inventory System ---\n\n");
    printf("1. Display Inventory\n");
    printf("2. Add New Item\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
}

// Displays the inventory.
void displayInventory(struct item inventory[MAX_ITEMS], int count) {
    int i;
    if(count == 0) {
        printf("Inventory is empty.\n");
    } else {
        printf("Inventory:\n");
        for(i = 0; i < count; i++) {
            printf("%d. %s (ID: %d) - $%.2f - Quantity: %d\n", i+1, inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
        }
    }
}

// Adds a new item to the inventory.
void addNewItem(struct item inventory[MAX_ITEMS], int *count) {
    if(*count == MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }
    
    struct item newItem;
    
    printf("Enter item name: ");
    scanf("%49s", newItem.name);
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    
    inventory[*count] = newItem;
    (*count)++;
    
    printf("Item added.\n");
}

// Updates an existing item in the inventory.
void updateItem(struct item inventory[MAX_ITEMS], int count) {
    if(count == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    
    int id, i;
    printf("Enter item ID: ");
    scanf("%d", &id);
    
    for(i = 0; i < count; i++) {
        if(inventory[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Item updated.\n");
            return;
        }
    }
    
    printf("Item not found.\n");
}

// Deletes an item from the inventory.
void deleteItem(struct item inventory[MAX_ITEMS], int *count) {
    if(*count == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    
    int id, i, j;
    printf("Enter item ID: ");
    scanf("%d", &id);
    
    for(i = 0; i < *count; i++) {
        if(inventory[i].id == id) {
            for(j = i; j < *count-1; j++) {
                inventory[j] = inventory[j+1];
            }
            (*count)--;
            printf("Item deleted.\n");
            return;
        }
    }
    
    printf("Item not found.\n");
}