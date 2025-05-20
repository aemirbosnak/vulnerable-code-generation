//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char dosage[MAX_NAME_LENGTH];
    float price;
    int stock;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory is full!\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter dosage: ");
    scanf("%s", newMedicine.dosage);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter stock quantity: ");
    scanf("%d", &newMedicine.stock);

    inventory[medicineCount++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }

    printf("\nAvailable Medicines:\n");
    printf("-------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-10s |\n", "Name", "Dosage", "Price", "Stock");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("| %-20s | %-10s | %-10.2f | %-10d |\n", 
                inventory[i].name, 
                inventory[i].dosage, 
                inventory[i].price, 
                inventory[i].stock);
    }
    printf("-------------------------------------------------------\n");
}

void searchMedicine() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf("%s", searchName);

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Name: %s\nDosage: %s\nPrice: %.2f\nStock: %d\n", 
                    inventory[i].name, 
                    inventory[i].dosage, 
                    inventory[i].price, 
                    inventory[i].stock);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found in the inventory.\n");
    }
}

void updateStock() {
    char targetName[MAX_NAME_LENGTH];
    int newStock;

    printf("Enter medicine name to update stock: ");
    scanf("%s", targetName);
    printf("Enter new stock quantity: ");
    scanf("%d", &newStock);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, targetName) == 0) {
            inventory[i].stock = newStock;
            printf("Stock updated successfully!\n");
            return;
        }
    }
    
    printf("Medicine not found in the inventory.\n");
}

void deleteMedicine() {
    char targetName[MAX_NAME_LENGTH];
    printf("Enter medicine name to delete: ");
    scanf("%s", targetName);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, targetName) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }

    printf("Medicine not found in the inventory.\n");
}

void displayMenu() {
    printf("\n");
    printf("=================================\n");
    printf("  Medical Store Management System\n");
    printf("=================================\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Stock\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
    printf("=================================\n");
    printf("Select an option: ");
}

int main() {
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateStock();
                break;
            case 5:
                deleteMedicine();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}