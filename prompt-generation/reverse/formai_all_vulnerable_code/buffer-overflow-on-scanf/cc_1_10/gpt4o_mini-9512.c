//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
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
    scanf(" %[^\n]", newMedicine.name);
    printf("Enter Medicine Price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter Medicine Quantity: ");
    scanf("%d", &newMedicine.quantity);

    inventory[medicineCount++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void removeMedicine() {
    int id, found = 0;

    printf("Enter Medicine ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; ++i) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < medicineCount - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            medicineCount--;
            printf("Medicine removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Medicine with ID %d not found!\n", id);
    }
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in the inventory.\n");
        return;
    }

    printf("\n--- Medicine Inventory ---\n");
    for (int i = 0; i < medicineCount; ++i) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("------------------------\n");
    }
}

void searchMedicine() {
    int id, found = 0;

    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; ++i) {
        if (inventory[i].id == id) {
            printf("Medicine found!\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine with ID %d not found!\n", id);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Display Medicines\n");
        printf("4. Search Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                removeMedicine();
                break;
            case 3:
                displayMedicines();
                break;
            case 4:
                searchMedicine();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}