//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine inventory[MAX_MEDICINES];
    int count;
} MedicalStore;

void addMedicine(MedicalStore *store) {
    if (store->count >= MAX_MEDICINES) {
        printf("Inventory full, cannot add more medicines.\n");
        return;
    }
    Medicine med;
    printf("Enter medicine name: ");
    scanf(" %[^\n]", med.name);
    printf("Enter quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter price: ");
    scanf("%f", &med.price);
    store->inventory[store->count++] = med;
    printf("Medicine added successfully!\n");
}

void listMedicines(MedicalStore *store) {
    if (store->count == 0) {
        printf("No medicines in inventory.\n");
        return;
    }
    printf("\nMedicines in Inventory:\n");
    printf("-------------------------------------\n");
    printf("%-25s %-10s %-10s\n", "Name", "Quantity", "Price");
    printf("-------------------------------------\n");
    for (int i = 0; i < store->count; i++) {
        printf("%-25s %-10d %-10.2f\n", store->inventory[i].name, store->inventory[i].quantity, store->inventory[i].price);
    }
    printf("-------------------------------------\n");
}

void searchMedicine(MedicalStore *store) {
    char searchName[NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]", searchName);
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->inventory[i].name, searchName) == 0) {
            printf("Medicine found: %s, Quantity: %d, Price: %.2f\n", store->inventory[i].name, store->inventory[i].quantity, store->inventory[i].price);
            return;
        }
    }
    printf("Medicine not found in inventory.\n");
}

void sellMedicine(MedicalStore *store) {
    char sellName[NAME_LENGTH];
    int quantity;
    printf("Enter medicine name to sell: ");
    scanf(" %[^\n]", sellName);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->inventory[i].name, sellName) == 0) {
            if (store->inventory[i].quantity < quantity) {
                printf("Not enough stock to sell %d of %s. Available quantity is %d.\n", quantity, sellName, store->inventory[i].quantity);
                return;
            }
            store->inventory[i].quantity -= quantity;
            printf("Sold %d of %s. Remaining quantity: %d.\n", quantity, sellName, store->inventory[i].quantity);
            return;
        }
    }
    printf("Medicine not found in inventory.\n");
}

void exitProgram() {
    printf("Exiting the Medical Store Management System. Goodbye!\n");
}

void displayMenu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. List Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Sell Medicine\n");
    printf("5. Exit\n");
    printf("========================================\n");
}

int main() {
    MedicalStore store = { .count = 0 };
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(&store);
                break;
            case 2:
                listMedicines(&store);
                break;
            case 3:
                searchMedicine(&store);
                break;
            case 4:
                sellMedicine(&store);
                break;
            case 5:
                exitProgram();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}