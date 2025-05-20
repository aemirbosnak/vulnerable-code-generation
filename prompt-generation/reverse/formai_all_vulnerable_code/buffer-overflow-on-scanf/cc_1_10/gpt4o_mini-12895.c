//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[100];
    char manufacturer[100];
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
    scanf("%s", m.name);
    printf("Enter manufacturer: ");
    scanf("%s", m.manufacturer);
    printf("Enter quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter price: ");
    scanf("%f", &m.price);
    
    inventory[medicineCount++] = m;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }
    printf("\nMedicines in Inventory:\n");
    printf("----------------------------------------------------------\n");
    printf("%-20s %-20s %-10s %s\n", "Name", "Manufacturer", "Quantity", "Price");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%-20s %-20s %-10d %.2f\n", inventory[i].name, inventory[i].manufacturer, inventory[i].quantity, inventory[i].price);
    }
    printf("----------------------------------------------------------\n");
}

void searchMedicine() {
    char name[100];
    printf("Enter the name of medicine to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("%-20s %-20s %-10d %.2f\n", inventory[i].name, inventory[i].manufacturer, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

void updateMedicine() {
    char name[100];
    printf("Enter the name of medicine to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating medicine %s:\n", name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void deleteMedicine() {
    char name[100];
    printf("Enter the name of medicine to delete: ");
    scanf("%s", name);
    
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
    printf("Medicine not found.\n");
}

void displayMenu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Medicine\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
    printf("=========================================\n");
}

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
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
                updateMedicine();
                break;
            case 5:
                deleteMedicine();
                break;
            case 6:
                printf("Exiting. Thank you for using the Medical Store Management System.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}