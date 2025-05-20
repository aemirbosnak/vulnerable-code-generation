//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: real-life
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

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", inventory[itemCount].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[itemCount].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[itemCount].price);
    itemCount++;
    printf("Item added successfully!\n");
}

void updateItem() {
    char name[NAME_LENGTH];
    printf("Enter item name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void deleteItem() {
    char name[NAME_LENGTH];
    printf("Enter item name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void viewInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    
    printf("Inventory:\n");
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

float calculateTotalValue() {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += (inventory[i].quantity * inventory[i].price);
    }
    return total;
}

float calculateAveragePrice() {
    float total = calculateTotalValue();
    if (itemCount == 0) return 0;
    return total / itemCount;
}

void displayStatistics() {
    float totalValue = calculateTotalValue();
    float averagePrice = calculateAveragePrice();
    
    printf("Total Inventory Value: %.2f\n", totalValue);
    printf("Average Price per Item: %.2f\n", averagePrice);
}

int main() {
    int choice;
    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Delete Item\n");
        printf("4. View Inventory\n");
        printf("5. Show Statistics\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                viewInventory();
                break;
            case 5:
                displayStatistics();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}