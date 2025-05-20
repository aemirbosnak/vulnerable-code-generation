//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char type[30];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicineStore;

void initializeStore(MedicineStore* store) {
    store->count = 0;
}

void addMedicine(MedicineStore* store) {
    if (store->count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Inventory full!\n");
        return;
    }
    Medicine med;
    printf("Enter medicine name: ");
    scanf("%s", med.name);
    printf("Enter medicine type: ");
    scanf("%s", med.type);
    printf("Enter medicine quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &med.price);

    store->medicines[store->count] = med;
    store->count++;
    printf("Medicine added successfully!\n");
}

void listMedicines(MedicineStore* store) {
    if (store->count == 0) {
        printf("No medicines in inventory.\n");
        return;
    }
    printf("\nListing all medicines:\n");
    for (int i = 0; i < store->count; i++) {
        Medicine med = store->medicines[i];
        printf("Name: %s, Type: %s, Quantity: %d, Price: %.2f\n", 
                med.name, med.type, med.quantity, med.price);
    }
}

void updateMedicine(MedicineStore* store) {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            printf("Current quantity: %d, Enter new quantity: ", store->medicines[i].quantity);
            scanf("%d", &store->medicines[i].quantity);
            printf("Current price: %.2f, Enter new price: ", store->medicines[i].price);
            scanf("%f", &store->medicines[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine(MedicineStore* store) {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            for (int j = i; j < store->count - 1; j++) {
                store->medicines[j] = store->medicines[j + 1];
            }
            store->count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void searchMedicine(MedicineStore* store) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            Medicine med = store->medicines[i];
            printf("Found medicine: Name: %s, Type: %s, Quantity: %d, Price: %.2f\n", 
                    med.name, med.type, med.quantity, med.price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void displayMenu() {
    printf("\nMedicine Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. List Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MedicineStore store;
    initializeStore(&store);
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(&store);
                break;
            case 2:
                listMedicines(&store);
                break;
            case 3:
                updateMedicine(&store);
                break;
            case 4:
                deleteMedicine(&store);
                break;
            case 5:
                searchMedicine(&store);
                break;
            case 6:
                printf("Exiting the program. Have a great day!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}