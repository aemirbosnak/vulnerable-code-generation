//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine();
void viewMedicines();
void updateMedicine();
void deleteMedicine();
void searchMedicine();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
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
                printf("Exiting the Medical Store Management System.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
}

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter manufacturer: ");
    scanf("%s", newMedicine.manufacturer);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);

    inventory[medicineCount] = newMedicine;
    medicineCount++;
    printf("Medicine added successfully.\n");
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available in inventory.\n");
        return;
    }

    printf("\nAvailable Medicines:\n");
    printf("=====================================================\n");
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Manufacturer", "Price", "Quantity");
    printf("=====================================================\n");

    for (int i = 0; i < medicineCount; i++) {
        printf("%-20s %-20s %.2f %-10d\n", inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
    }
}

void updateMedicine() {
    char name[50];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating medicine %s:\n", name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Medicine updated successfully.\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[50];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift medicines
            }
            medicineCount--;
            printf("Medicine %s deleted successfully.\n", name);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void searchMedicine() {
    char name[50];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nMedicine found:\n");
            printf("=====================================================\n");
            printf("%-20s %-20s %-10s %-10s\n", "Name", "Manufacturer", "Price", "Quantity");
            printf("=====================================================\n");
            printf("%-20s %-20s %.2f %-10d\n", inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Medicine not found!\n");
}