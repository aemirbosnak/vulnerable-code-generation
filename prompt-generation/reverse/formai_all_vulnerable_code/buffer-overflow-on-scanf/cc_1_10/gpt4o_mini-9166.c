//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function to add an item to the inventory
void addItem() {
    if (itemCount < MAX_ITEMS) {
        printf("Enter the name of the item: ");
        scanf("%s", inventory[itemCount].name);
        printf("Enter the quantity: ");
        scanf("%d", &inventory[itemCount].quantity);
        printf("Enter the price: ");
        scanf("%f", &inventory[itemCount].price);
        itemCount++;
        printf("Item added: %s, Quantity: %d, Price: %.2f\n", 
               inventory[itemCount-1].name, 
               inventory[itemCount-1].quantity, 
               inventory[itemCount-1].price);
    } else {
        printf("Inventory is full! Cannot add more items.\n");
    }
}

// Function to view all items in the inventory
void viewItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }
    printf("Inventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - Quantity: %d, Price: %.2f\n", 
               i + 1, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
}

// Function to delete an item from the inventory
void deleteItem() {
    if (itemCount == 0) {
        printf("No items to delete.\n");
        return;
    }
    viewItems();
    printf("Enter the item number to delete: ");
    int index;
    scanf("%d", &index);
    if (index < 1 || index > itemCount) {
        printf("Invalid item number.\n");
        return;
    }
    // Shift items to remove the item from the inventory
    for (int i = index - 1; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    itemCount--;
    printf("Item deleted.\n");
}

// Function to display the menu options
void displayMenu() {
    printf("Post-Apocalyptic Medical Store Management System\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Delete Item\n");
    printf("4. Exit\n");
}

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
                deleteItem();
                break;
            case 4:
                printf("Stay safe, survivor!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}