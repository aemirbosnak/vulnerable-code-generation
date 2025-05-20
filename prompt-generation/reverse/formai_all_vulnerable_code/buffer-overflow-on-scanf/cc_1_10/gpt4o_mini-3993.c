//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int stock;
    float price;
} Medicine;

Medicine inventory[MAX_ITEMS];
int itemCount = 0;

void addMedicine() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full, cannot add more medicines.\n");
        return;
    }

    Medicine newMed;
    printf("Enter medicine name: ");
    scanf(" %[^\n]", newMed.name);
    printf("Enter quantity in stock: ");
    scanf("%d", &newMed.stock);
    printf("Enter price: ");
    scanf("%f", &newMed.price);

    inventory[itemCount] = newMed;
    itemCount++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (itemCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }

    printf("\n--- Medicines in Inventory ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("Name: %s\n", inventory[i].name);
        printf("Stock: %d\n", inventory[i].stock);
        printf("Price: $%.2f\n", inventory[i].price);
        printf("-------------------------------\n");
    }
}

void updateStock() {
    char name[NAME_LENGTH];
    int newStock;
    printf("Enter medicine name to update stock: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Current stock of %s: %d\n", inventory[i].name, inventory[i].stock);
            printf("Enter new stock quantity: ");
            scanf("%d", &newStock);
            inventory[i].stock = newStock;
            printf("Stock updated successfully!\n");
            return;
        }
    }

    printf("Medicine '%s' not found in the inventory.\n", name);
}

void deleteMedicine() {
    char name[NAME_LENGTH];
    printf("Enter medicine name to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Medicine '%s' deleted successfully!\n", name);
            return;
        }
    }

    printf("Medicine '%s' not found in the inventory.\n", name);
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Update Stock\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    printf("Select an option: ");
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
                viewMedicines();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}