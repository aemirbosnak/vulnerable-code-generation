//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[30];
    char manufacturer[30];
    int id;
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
    
    Medicine newMedicine;
    printf("Enter Medicine ID: ");
    scanf("%d", &newMedicine.id);
    printf("Enter Medicine Name: ");
    scanf("%s", newMedicine.name);
    printf("Enter Manufacturer: ");
    scanf("%s", newMedicine.manufacturer);
    printf("Enter Price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter Quantity: ");
    scanf("%d", &newMedicine.quantity);
    
    inventory[medicineCount] = newMedicine;
    medicineCount++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }
    
    printf("\nMedicine Inventory:\n");
    printf("ID\tName\t\tManufacturer\tPrice\tQuantity\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%s\t\t%s\t%.2f\t%d\n", 
                inventory[i].id, 
                inventory[i].name, 
                inventory[i].manufacturer, 
                inventory[i].price, 
                inventory[i].quantity);
    }
}

void sellMedicine() {
    int id, quantity;
    printf("Enter Medicine ID to sell: ");
    scanf("%d", &id);
    
    for (int i = 0; i < medicineCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter Quantity to sell: ");
            scanf("%d", &quantity);
            
            if (quantity > inventory[i].quantity) {
                printf("Insufficient stock! Available quantity: %d\n", inventory[i].quantity);
                return;
            }
            
            inventory[i].quantity -= quantity;
            printf("Sold %d of %s. Remaining stock: %d\n", quantity, inventory[i].name, inventory[i].quantity);
            return;
        }
    }
    
    printf("Medicine not found!\n");
}

void generateSalesReport() {
    // For simplicity, we will just show the stock report as a pseudo sales report
    printf("\nSales Report (Current Stock):\n");
    viewMedicines();
}

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. Generate Sales Report\n");
        printf("5. Exit\n");
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
                sellMedicine();
                break;
            case 4:
                generateSalesReport();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}