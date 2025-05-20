//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Medicine;

Medicine medicineList[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Medicine inventory is full!\n");
        return;
    }
    
    Medicine newMedicine;
    printf("Enter medicine ID: ");
    scanf("%d", &newMedicine.id);
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter medicine price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter quantity available: ");
    scanf("%d", &newMedicine.quantity);
    
    medicineList[medicineCount++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available in the inventory.\n");
        return;
    }

    printf("\nAvailable Medicines:\n");
    printf("%-10s %-30s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    for (int i = 0; i < medicineCount; i++) {
        printf("%-10d %-30s %-10.2f %-10d\n", 
            medicineList[i].id, 
            medicineList[i].name, 
            medicineList[i].price, 
            medicineList[i].quantity);
    }
}

void sellMedicine() {
    int id, quantity;
    printf("Enter medicine ID to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < medicineCount; i++) {
        if (medicineList[i].id == id) {
            if (medicineList[i].quantity >= quantity) {
                medicineList[i].quantity -= quantity;
                printf("Sold %d of %s.\n", quantity, medicineList[i].name);
                printf("Total Price: %.2f\n", quantity * medicineList[i].price);
            } else {
                printf("Insufficient quantity available.\n");
            }
            return;
        }
    }
    
    printf("Medicine with ID %d not found.\n", id);
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Sell Medicine\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                sellMedicine();
                break;
            case 4:
                printf("Exiting the system. Have a good day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}