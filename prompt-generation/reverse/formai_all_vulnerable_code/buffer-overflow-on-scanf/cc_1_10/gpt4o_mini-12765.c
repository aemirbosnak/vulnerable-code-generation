//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
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
int count = 0;

void addMedicine() {
    if (count >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
    Medicine new_medicine;
    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter manufacturer: ");
    scanf("%s", new_medicine.manufacturer);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);
    inventory[count++] = new_medicine;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (count == 0) {
        printf("No medicines in inventory.\n");
        return;
    }
    printf("Medicines in Inventory:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Manufacturer", "Price", "Quantity");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
    }
    printf("--------------------------------------------------\n");
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n",
                   inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Medicine not found.\n");
}

void sellMedicine() {
    char name[50];
    int quantity;
    printf("Enter medicine name to sell: ");
    scanf("%s", name);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Sold %d of %s. Remaining quantity: %d\n", quantity, inventory[i].name, inventory[i].quantity);
                return;
            } else {
                printf("Not enough stock. Available quantity: %d\n", inventory[i].quantity);
                return;
            }
        }
    }
    printf("Medicine not found.\n");
}

void menu() {
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Sell Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: sellMedicine(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}