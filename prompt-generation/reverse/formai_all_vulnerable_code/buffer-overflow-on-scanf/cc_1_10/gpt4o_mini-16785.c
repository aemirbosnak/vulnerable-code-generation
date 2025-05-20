//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory full. Cannot add more medicines.\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter medicine quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &newMedicine.price);

    inventory[medicineCount++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void viewInventory() {
    if (medicineCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("%-20s %-10s %-10s\n", "Medicine Name", "Quantity", "Price");
    for (int i = 0; i < medicineCount; i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void sellMedicine() {
    char medicineName[MAX_NAME_LENGTH];
    int sellQty;

    printf("Enter medicine name to sell: ");
    scanf("%s", medicineName);
    printf("Enter quantity to sell: ");
    scanf("%d", &sellQty);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, medicineName) == 0) {
            if (sellQty > inventory[i].quantity) {
                printf("Insufficient stock available.\n");
                return;
            }
            inventory[i].quantity -= sellQty;
            float totalPrice = sellQty * inventory[i].price;
            printf("Sold %d of %s. Total Price: %.2f\n", sellQty, inventory[i].name, totalPrice);
            return;
        }
    }

    printf("Medicine not found in inventory.\n");
}

void generateSalesReport() {
    printf("\nSales Report:\n");
    printf("%-20s %-10s %-10s\n", "Medicine Name", "Quantity", "Total Price");
    for (int i = 0; i < medicineCount; i++) {
        if (inventory[i].quantity < 100) { // Assuming some periodic check might be needed
            printf("%-20s %-10d %-10.2f\n", inventory[i].name, (100 - inventory[i].quantity), 
                   (100 - inventory[i].quantity) * inventory[i].price);
        }
    }
}

void displayMenu() {
    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. View Inventory\n");
    printf("3. Sell Medicine\n");
    printf("4. Generate Sales Report\n");
    printf("5. Exit\n");
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
                viewInventory();
                break;
            case 3:
                sellMedicine();
                break;
            case 4:
                generateSalesReport();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}