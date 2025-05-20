//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    int stock;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicineStore;

void initializeStore(MedicineStore *store) {
    store->count = 0;
}

void addMedicine(MedicineStore *store) {
    if (store->count >= MAX_MEDICINES) {
        printf("The medicine store is full. Cannot add more medicines.\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter the name of the medicine: ");
    scanf("%s", newMedicine.name);
    printf("Enter the category of the medicine: ");
    scanf("%s", newMedicine.category);
    printf("Enter the stock quantity: ");
    scanf("%d", &newMedicine.stock);
    printf("Enter the price of the medicine: ");
    scanf("%f", &newMedicine.price);

    store->medicines[store->count] = newMedicine;
    store->count++;

    printf("Medicine %s added successfully!\n", newMedicine.name);
}

void displayMedicines(MedicineStore *store) {
    if (store->count == 0) {
        printf("No medicines found in the store.\n");
        return;
    }

    printf("\nList of Medicines:\n");
    for (int i = 0; i < store->count; i++) {
        printf("Name: %s, Category: %s, Stock: %d, Price: %.2f\n",
               store->medicines[i].name,
               store->medicines[i].category,
               store->medicines[i].stock,
               store->medicines[i].price);
    }
}

void searchMedicine(MedicineStore *store) {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, searchName) == 0) {
            printf("Medicine found: Name: %s, Category: %s, Stock: %d, Price: %.2f\n",
                   store->medicines[i].name,
                   store->medicines[i].category,
                   store->medicines[i].stock,
                   store->medicines[i].price);
            return;
        }
    }
    printf("Medicine %s not found in the store.\n", searchName);
}

void updateStock(MedicineStore *store) {
    char updateName[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to update stock: ");
    scanf("%s", updateName);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, updateName) == 0) {
            int newStock;
            printf("Current stock: %d. Enter new stock quantity: ", store->medicines[i].stock);
            scanf("%d", &newStock);
            store->medicines[i].stock = newStock;
            printf("Stock updated for medicine %s!\n", updateName);
            return;
        }
    }
    printf("Medicine %s not found in the store.\n", updateName);
}

void deleteMedicine(MedicineStore *store) {
    char deleteName[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, deleteName) == 0) {
            store->medicines[i] = store->medicines[store->count - 1];
            store->count--;
            printf("Medicine %s deleted successfully!\n", deleteName);
            return;
        }
    }
    printf("Medicine %s not found in the store.\n", deleteName);
}

void displayMenu() {
    printf("\n--- Medicine Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Stock\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MedicineStore store;
    initializeStore(&store);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(&store);
                break;
            case 2:
                displayMedicines(&store);
                break;
            case 3:
                searchMedicine(&store);
                break;
            case 4:
                updateStock(&store);
                break;
            case 5:
                deleteMedicine(&store);
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}