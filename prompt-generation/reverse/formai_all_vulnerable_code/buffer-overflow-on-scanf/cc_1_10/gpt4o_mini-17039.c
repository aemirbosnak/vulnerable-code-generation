//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    char expiry_date[15];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Inventory is full! Cannot add more medicines.\n");
        return;
    }

    Medicine new_medicine;
    printf("Enter Medicine Name: ");
    scanf("%s", new_medicine.name);
    printf("Enter Manufacturer: ");
    scanf("%s", new_medicine.manufacturer);
    printf("Enter Expiry Date (YYYY-MM-DD): ");
    scanf("%s", new_medicine.expiry_date);
    printf("Enter Quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter Price: ");
    scanf("%f", &new_medicine.price);

    inventory[medicine_count] = new_medicine;
    medicine_count++;
    printf("Medicine added successfully!\n\n");
}

void displayMedicines() {
    if (medicine_count == 0) {
        printf("No medicines in the inventory.\n\n");
        return;
    }

    printf("Current Inventory:\n");
    printf("%-20s %-20s %-15s %-10s %-10s\n", "Name", "Manufacturer", "Expiry Date", "Quantity", "Price");
    for (int i = 0; i < medicine_count; i++) {
        printf("%-20s %-20s %-15s %-10d $%-9.2f\n",
               inventory[i].name, 
               inventory[i].manufacturer, 
               inventory[i].expiry_date, 
               inventory[i].quantity, 
               inventory[i].price);
    }
    printf("\n");
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine Found!\n");
            printf("Name: %s\nManufacturer: %s\nExpiry: %s\nQuantity: %d\nPrice: $%.2f\n\n",
                   inventory[i].name, 
                   inventory[i].manufacturer, 
                   inventory[i].expiry_date, 
                   inventory[i].quantity, 
                   inventory[i].price);
            return;
        }
    }

    printf("Medicine not found in the inventory.\n\n");
}

void updateMedicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating Medicine: %s\n", inventory[i].name);
            printf("Current Quantity: %d, Enter new Quantity: ", inventory[i].quantity);
            scanf("%d", &inventory[i].quantity);
            printf("Current Price: $%.2f, Enter new Price: ", inventory[i].price);
            scanf("%f", &inventory[i].price);
            printf("Medicine updated successfully!\n\n");
            return;
        }
    }
    
    printf("Medicine not found in the inventory.\n\n");
}

void menu() {
    int choice;
    do {
        printf("=== Medical Store Management System ===\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: updateMedicine(); break;
            case 5: printf("Exiting... Thank you for using the system!\n"); break;
            default: printf("Invalid choice! Please try again.\n\n"); break;
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}