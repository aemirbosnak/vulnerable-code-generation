//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory is full, cannot add more medicines.\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter Medicine Name: ");
    scanf("%s", newMedicine.name);
    printf("Enter Manufacturer: ");
    scanf("%s", newMedicine.manufacturer);
    printf("Enter Quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter Price: ");
    scanf("%f", &newMedicine.price);

    inventory[medicineCount] = newMedicine;
    medicineCount++;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("--------------------------------------------------------\n");
    printf("| %s\t| %s\t | %s\t| %s\t|\n", "Name", "Manufacturer", "Quantity", "Price");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("| %s\t| %s\t | %d\t| %.2f\t|\n", 
               inventory[i].name, 
               inventory[i].manufacturer, 
               inventory[i].quantity, 
               inventory[i].price);
    }
    printf("--------------------------------------------------------\n");
}

void searchMedicine() {
    char searchTerm[50];
    printf("Enter Medicine Name to search: ");
    scanf("%s", searchTerm);

    int found = 0;
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, searchTerm) == 0) {
            found = 1;
            printf("Medicine found: %s, Manufacturer: %s, Quantity: %d, Price: %.2f\n",
                inventory[i].name, inventory[i].manufacturer, inventory[i].quantity, inventory[i].price);
            break;
        }
    }

    if (!found) {
        printf("Medicine not found in the inventory.\n");
    }
}

void sellMedicine() {
    char medicineName[50];
    int sellQuantity;
    printf("Enter Medicine Name to sell: ");
    scanf("%s", medicineName);
    printf("Enter Quantity to sell: ");
    scanf("%d", &sellQuantity);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, medicineName) == 0) {
            if (inventory[i].quantity >= sellQuantity) {
                inventory[i].quantity -= sellQuantity;
                printf("Sold %d of %s. Remaining quantity: %d\n", sellQuantity, inventory[i].name, inventory[i].quantity);
                return;
            } else {
                printf("Insufficient quantity! Available: %d\n", inventory[i].quantity);
                return;
            }
        }
    }

    printf("Medicine not found in the inventory.\n");
}

void deleteMedicine() {
    char medicineName[50];
    printf("Enter Medicine Name to delete: ");
    scanf("%s", medicineName);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, medicineName) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift left
            }
            medicineCount--;
            printf("Medicine %s deleted successfully!\n", medicineName);
            return;
        }
    }

    printf("Medicine not found in the inventory.\n");
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Sell Medicine\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
    printf("---------------------------------------\n");
}

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
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                sellMedicine();
                break;
            case 5:
                deleteMedicine();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}