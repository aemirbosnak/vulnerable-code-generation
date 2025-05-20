//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char manufacturer[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
    
    Medicine new_medicine;
    printf("Enter medicine name: ");
    scanf(" %[^\n]", new_medicine.name);
    printf("Enter manufacturer: ");
    scanf(" %[^\n]", new_medicine.manufacturer);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);
    
    inventory[medicine_count++] = new_medicine;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    printf("\nCurrent Inventory:\n");
    printf("----------------------------------------------------\n");
    printf("%-30s %-20s %-10s %-10s\n", "Name", "Manufacturer", "Price", "Quantity");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%-30s %-20s $%-9.2f %-10d\n", inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
    }
    printf("----------------------------------------------------\n");
}

void searchMedicine() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]", search_name);
    
    int found = 0;
    for (int i = 0; i < medicine_count; i++) {
        if (strcasecmp(inventory[i].name, search_name) == 0) {
            printf("Medicine found:\n");
            printf("Name: %s\nManufacturer: %s\nPrice: $%.2f\nQuantity: %d\n", 
                   inventory[i].name, 
                   inventory[i].manufacturer, 
                   inventory[i].price, 
                   inventory[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found in inventory.\n");
    }
}

void updateMedicine() {
    char update_name[MAX_NAME_LENGTH];
    printf("Enter medicine name to update: ");
    scanf(" %[^\n]", update_name);
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcasecmp(inventory[i].name, update_name) == 0) {
            printf("Updating %s...\n", inventory[i].name);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found for updating.\n");
}

void deleteMedicine() {
    char delete_name[MAX_NAME_LENGTH];
    printf("Enter medicine name to delete: ");
    scanf(" %[^\n]", delete_name);
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcasecmp(inventory[i].name, delete_name) == 0) {
            for (int j = i; j < medicine_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicine_count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found for deletion.\n");
}

void menu() {
    while (1) {
        printf("\n----- Medical Store Management System -----\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
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
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}