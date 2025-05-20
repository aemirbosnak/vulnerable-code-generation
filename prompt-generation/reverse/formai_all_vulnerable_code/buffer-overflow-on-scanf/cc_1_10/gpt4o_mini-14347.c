//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_ITEMS];
int item_count = 0;

void addMedicine() {
    if (item_count >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }

    Medicine new_medicine;
    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);

    inventory[item_count] = new_medicine;
    item_count++;
    printf("Medicine added successfully!\n");
}

void displayInventory() {
    if (item_count == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\n----- Inventory -----\n");
    for (int i = 0; i < item_count; i++) {
        printf("Medicine Name: %s | Quantity: %d | Price: %.2f\n",
                inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("---------------------\n");
}

void sellMedicine() {
    char name[50];
    int quantity;
    printf("Enter medicine name to sell: ");
    scanf("%s", name);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Sold %d of %s. Remaining quantity: %d\n", 
                        quantity, inventory[i].name, inventory[i].quantity);
                return;
            } else {
                printf("Insufficient quantity of %s. Available: %d\n", 
                        inventory[i].name, inventory[i].quantity);
                return;
            }
        }
    }
    printf("Medicine %s not found in inventory.\n", name);
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Found %s | Quantity: %d | Price: %.2f\n",
                   inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Medicine %s not found in inventory.\n", name);
}

void restockMedicine() {
    char name[50];
    int quantity;
    printf("Enter medicine name to restock: ");
    scanf("%s", name);
    printf("Enter quantity to add: ");
    scanf("%d", &quantity);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity += quantity;
            printf("Restocked %d of %s. New quantity: %d\n", 
                    quantity, inventory[i].name, inventory[i].quantity);
            return;
        }
    }

    printf("Medicine %s not found in inventory. Please add it first.\n", name);
}

void displayMenu() {
    printf("\n----- Medical Store Management System -----\n");
    printf("1. Add Medicine\n");
    printf("2. Display Inventory\n");
    printf("3. Sell Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Restock Medicine\n");
    printf("6. Exit\n");
    printf("--------------------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                sellMedicine();
                break;
            case 4:
                searchMedicine();
                break;
            case 5:
                restockMedicine();
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}