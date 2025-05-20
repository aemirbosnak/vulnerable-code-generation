//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char manufacturer[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory is full. Cannot add more medicines.\n");
        return;
    }
    
    Medicine newMedicine;
    newMedicine.id = medicineCount + 1;

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

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }

    printf("ID\tName\tManufacturer\tPrice\tQuantity\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
    }
}

void searchMedicine() {
    char name[MAX_NAME_LENGTH];
    printf("Enter Medicine Name to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Found Medicine:\n");
            printf("ID: %d\nName: %s\nManufacturer: %s\nPrice: %.2f\nQuantity: %d\n", 
                    inventory[i].id, inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void updateMedicine() {
    int id;
    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > medicineCount) {
        printf("Invalid ID.\n");
        return;
    }

    Medicine *med = &inventory[id - 1]; // Adjust for zero-based index
    printf("Updating Medicine ID: %d\n", med->id);
    printf("Current Name: %s\n", med->name);
    printf("Current Manufacturer: %s\n", med->manufacturer);
    printf("Current Price: %.2f\n", med->price);
    printf("Current Quantity: %d\n", med->quantity);

    printf("Enter new Name: ");
    scanf("%s", med->name);
    printf("Enter new Manufacturer: ");
    scanf("%s", med->manufacturer);
    printf("Enter new Price: ");
    scanf("%f", &med->price);
    printf("Enter new Quantity: ");
    scanf("%d", &med->quantity);

    printf("Medicine updated successfully!\n");
}

void deleteMedicine() {
    int id;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > medicineCount) {
        printf("Invalid ID.\n");
        return;
    }

    for (int i = id - 1; i < medicineCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    medicineCount--;
    printf("Medicine ID %d deleted successfully!\n", id);
}

int main() {
    int choice;
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
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
                updateMedicine();
                break;
            case 5:
                deleteMedicine();
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}