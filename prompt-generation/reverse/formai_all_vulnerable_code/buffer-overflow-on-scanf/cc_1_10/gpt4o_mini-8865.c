//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 50
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine();
void viewMedicines();
void updateMedicine();
void deleteMedicine();
void searchMedicine();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
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
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                searchMedicine();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
}

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", inventory[medicineCount].name);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[medicineCount].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[medicineCount].quantity);

    medicineCount++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in the inventory.\n");
        return;
    }

    printf("\n--- Medicines in Inventory ---\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("Medicine %d: Name: %s, Price: %.2f, Quantity: %d\n",
               i + 1, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void updateMedicine() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Current details - Name: %s, Price: %.2f, Quantity: %d\n",
                   inventory[i].name, inventory[i].price, inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void searchMedicine() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found! Name: %s, Price: %.2f, Quantity: %d\n",
                   inventory[i].name, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Medicine not found!\n");
}