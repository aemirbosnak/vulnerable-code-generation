//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_SIZE];
int medicineCount = 0;

void displayMenu() {
    printf("***** Medical Store Management System *****\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Delete Medicine\n");
    printf("4. Display Inventory\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
    printf("********************************************\n");
    printf("Choose an option: ");
}

void addMedicine() {
    if (medicineCount < MAX_SIZE) {
        Medicine newMedicine;
        printf("Enter Medicine ID: ");
        scanf("%d", &newMedicine.id);
        printf("Enter Medicine Name: ");
        scanf(" %[^\n]%*c", newMedicine.name);
        printf("Enter Manufacturer: ");
        scanf(" %[^\n]%*c", newMedicine.manufacturer);
        printf("Enter Price: ");
        scanf("%f", &newMedicine.price);
        printf("Enter Quantity: ");
        scanf("%d", &newMedicine.quantity);
        
        inventory[medicineCount++] = newMedicine;
        printf("Medicine added successfully!\n");
    } else {
        printf("Inventory full, cannot add more medicines.\n");
    }
}

void updateMedicine() {
    int id, i;
    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);
  
    for (i = 0; i < medicineCount; i++) {
        if (inventory[i].id == id) {
            printf("Updating Medicine ID: %d\n", id);
            printf("Enter New Name: ");
            scanf(" %[^\n]%*c", inventory[i].name);
            printf("Enter New Manufacturer: ");
            scanf(" %[^\n]%*c", inventory[i].manufacturer);
            printf("Enter New Price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter New Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
  
    printf("Medicine with ID %d not found.\n", id);
}

void deleteMedicine() {
    int id, i, j;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);
  
    for (i = 0; i < medicineCount; i++) {
        if (inventory[i].id == id) {
            for (j = i; j < medicineCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicineCount--;
            printf("Medicine with ID %d deleted successfully!\n", id);
            return;
        }
    }
  
    printf("Medicine with ID %d not found.\n", id);
}

void displayInventory() {
    printf("***** Current Inventory *****\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("ID: %d, Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n",
            inventory[i].id, inventory[i].name, inventory[i].manufacturer,
            inventory[i].price, inventory[i].quantity);
    }
    printf("******************************\n");
}

void searchMedicine() {
    char name[50];
    printf("Enter Medicine Name to search: ");
    scanf(" %[^\n]%*c", name);
  
    int found = 0;
    for (int i = 0; i < medicineCount; i++) {
        if (strcasecmp(inventory[i].name, name) == 0) {
            printf("Found Medicine - ID: %d, Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n",
                inventory[i].id, inventory[i].name, inventory[i].manufacturer,
                inventory[i].price, inventory[i].quantity);
            found = 1;
        }
    }
  
    if (!found) {
        printf("No medicine found with the name '%s'.\n", name);
    }
}

int main() {
    int choice;
  
    do {
        displayMenu();
        scanf("%d", &choice);
      
        switch (choice) {
            case 1: addMedicine(); break;
            case 2: updateMedicine(); break;
            case 3: deleteMedicine(); break;
            case 4: displayInventory(); break;
            case 5: searchMedicine(); break;
            case 6: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
  
    return 0;
}