//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
  
    Medicine m;
    printf("Enter medicine name: ");
    scanf(" %[^\n]", m.name);
    printf("Enter quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter price: ");
    scanf("%f", &m.price);

    inventory[medicineCount++] = m;
    printf("Medicine added successfully!\n");
}

void displayInventory() {
    if (medicineCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }

    printf("\nInventory:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Medicine Name", "Quantity", "Price");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%-20s %-10d $%-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("--------------------------------------------------\n");
}

void updateMedicine() {
    char name[NAME_LENGTH];
    printf("Enter medicine name to update: ");
    scanf(" %[^\n]", name);
  
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Current quantity: %d. Enter new quantity: ", inventory[i].quantity);
            scanf("%d", &inventory[i].quantity);
            printf("Current price: $%.2f. Enter new price: ", inventory[i].price);
            scanf("%f", &inventory[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
  
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[NAME_LENGTH];
    printf("Enter medicine name to delete: ");
    scanf(" %[^\n]", name);
  
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
  
    printf("Medicine not found!\n");
}

void searchMedicine() {
    char name[NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]", name);
  
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found: %s | Quantity: %d | Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
  
    printf("Medicine not found!\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Inventory\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Search Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                searchMedicine();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}