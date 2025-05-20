//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine();
void updateMedicine();
void deleteMedicine();
void listMedicines();
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
                updateMedicine();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                listMedicines();
                break;
            case 5:
                searchMedicine();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n----- Medical Store Management System -----\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Delete Medicine\n");
    printf("4. List Medicines\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
    printf("------------------------------------------\n");
}

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
    
    Medicine new_medicine;
    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter category: ");
    scanf("%s", new_medicine.category);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);
    
    inventory[medicine_count++] = new_medicine;
    printf("Medicine added successfully!\n");
}

void updateMedicine() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating details for %s\n", name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    
    printf("Medicine %s not found in inventory.\n", name);
}

void deleteMedicine() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < medicine_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicine_count--;
            printf("Medicine %s deleted successfully!\n", name);
            return;
        }
    }
    
    printf("Medicine %s not found in inventory.\n", name);
}

void listMedicines() {
    if (medicine_count == 0) {
        printf("No medicines in inventory.\n");
        return;
    }
    
    printf("\n----- Inventory List -----\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("Name: %s, Category: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].name, inventory[i].category,
               inventory[i].quantity, inventory[i].price);
    }
    printf("--------------------------\n");
}

void searchMedicine() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found: Name: %s, Category: %s, Quantity: %d, Price: %.2f\n",
                   inventory[i].name, inventory[i].category,
                   inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    
    printf("Medicine %s not found in inventory.\n", name);
}