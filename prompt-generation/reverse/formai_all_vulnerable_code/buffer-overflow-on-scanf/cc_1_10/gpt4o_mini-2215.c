//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50
#define MAX_COMPANY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char company[MAX_COMPANY_LENGTH];
    int quantity;
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
        printf("Cannot add more medicines, storage full!\n");
        return;
    }
    
    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter company: ");
    scanf("%s", newMedicine.company);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);

    store->medicines[store->count] = newMedicine;
    store->count++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(MedicineStore *store) {
    if (store->count == 0) {
        printf("No medicines in the store.\n");
        return;
    }
    
    printf("\nList of Medicines:\n");
    for (int i = 0; i < store->count; i++) {
        printf("Medicine Name: %s, Company: %s, Quantity: %d, Price: %.2f\n",
               store->medicines[i].name,
               store->medicines[i].company,
               store->medicines[i].quantity,
               store->medicines[i].price);
    }
}

void searchMedicine(MedicineStore *store) {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the medicine name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, searchName) == 0) {
            printf("Medicine found: %s, Company: %s, Quantity: %d, Price: %.2f\n",
                   store->medicines[i].name,
                   store->medicines[i].company,
                   store->medicines[i].quantity,
                   store->medicines[i].price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine(MedicineStore *store) {
    char deleteName[MAX_NAME_LENGTH];
    printf("Enter the medicine name to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, deleteName) == 0) {
            store->medicines[i] = store->medicines[store->count - 1]; // Replace with the last item
            store->count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void menu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    printf("========================================\n");
}

int main() {
    MedicineStore store;
    initializeStore(&store);

    int choice;
    do {
        menu();
        printf("Enter your choice: ");
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
                deleteMedicine(&store);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}