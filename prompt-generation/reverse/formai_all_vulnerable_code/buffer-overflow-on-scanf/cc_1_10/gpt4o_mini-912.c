//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} Inventory;

void addMedicine(Inventory *inventory) {
    if (inventory->count >= MAX_MEDICINES) {
        printf("Cannot add more medicines! Inventory full.\n");
        return;
    }
    Medicine newMedicine;
    newMedicine.id = inventory->count + 1;
    
    printf("Enter medicine name: ");
    scanf(" %[^\n]", newMedicine.name);
    
    printf("Enter manufacturer: ");
    scanf(" %[^\n]", newMedicine.manufacturer);
    
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    
    inventory->medicines[inventory->count] = newMedicine;
    inventory->count++;
    
    printf("Medicine added successfully!\n");
}

void viewMedicines(Inventory *inventory) {
    if (inventory->count == 0) {
        printf("No medicines in the inventory.\n");
        return;
    }
    
    printf("\nMedicines in Inventory:\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("ID: %d, Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n",
               inventory->medicines[i].id,
               inventory->medicines[i].name,
               inventory->medicines[i].manufacturer,
               inventory->medicines[i].price,
               inventory->medicines[i].quantity);
    }
}

void deleteMedicine(Inventory *inventory) {
    if (inventory->count == 0) {
        printf("No medicines to delete.\n");
        return;
    }
    
    int id;
    printf("Enter the ID of the medicine to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > inventory->count) {
        printf("Invalid ID!\n");
        return;
    }
    
    for (int i = id - 1; i < inventory->count - 1; i++) {
        inventory->medicines[i] = inventory->medicines[i + 1];
    }
    
    inventory->count--;
    printf("Medicine deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Delete Medicine\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Inventory inventory;
    inventory.count = 0;
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine(&inventory);
                break;
            case 2:
                viewMedicines(&inventory);
                break;
            case 3:
                deleteMedicine(&inventory);
                break;
            case 4:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}