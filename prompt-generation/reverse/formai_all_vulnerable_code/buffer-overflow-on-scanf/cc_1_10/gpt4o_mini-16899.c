//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: genius
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

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory full, cannot add more medicines.\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    
    printf("Enter manufacturer name: ");
    scanf("%s", newMedicine.manufacturer);
    
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    
    inventory[medicineCount++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }
    
    printf("\n%-20s %-20s %-10s %-10s\n", "Name", "Manufacturer", "Price", "Quantity");
    for (int i = 0; i < medicineCount; i++) {
        printf("%-20s %-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
    }
}

void updateMedicine() {
    char name[50];
    printf("Enter name of medicine to update: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating medicine: %s\n", name);
            printf("New manufacturer name: ");
            scanf("%s", inventory[i].manufacturer);
            
            printf("New price: ");
            scanf("%f", &inventory[i].price);
            
            printf("New quantity: ");
            scanf("%d", &inventory[i].quantity);
            
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void deleteMedicine() {
    char name[50];
    printf("Enter name of medicine to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i] = inventory[--medicineCount];
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void showMenu() {
    printf("\n----- Medical Store Management System -----\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
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
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}