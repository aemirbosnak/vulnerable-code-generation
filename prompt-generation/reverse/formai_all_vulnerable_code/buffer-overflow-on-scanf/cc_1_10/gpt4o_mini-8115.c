//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    int id;
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int item_count = 0;

void addItem();
void viewItems();
void removeItem();
void displayMenu();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Remove Item\n");
    printf("4. Exit\n");
}

void addItem() {
    if (item_count >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item new_item;
    new_item.id = item_count + 1;  // Set ID based on current item count
    
    printf("Enter item name: ");
    getchar();  // To consume newline character left by previous scanf
    fgets(new_item.name, ITEM_NAME_LENGTH, stdin);
    new_item.name[strcspn(new_item.name, "\n")] = 0; // Remove newline

    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);
    
    warehouse[item_count] = new_item;
    item_count++;
    printf("Item added successfully! Item ID: %d\n", new_item.id);
}

void viewItems() {
    if (item_count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    
    printf("\n--- Warehouse Items ---\n");
    for (int i = 0; i < item_count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", 
               warehouse[i].id, 
               warehouse[i].name, 
               warehouse[i].quantity);
    }
}

void removeItem() {
    if (item_count == 0) {
        printf("No items to remove.\n");
        return;
    }
    
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < item_count; i++) {
        if (warehouse[i].id == id) {
            found = 1;
            // Shift remaining items to fill the gap
            for (int j = i; j < item_count - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            item_count--;
            printf("Item removed successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}