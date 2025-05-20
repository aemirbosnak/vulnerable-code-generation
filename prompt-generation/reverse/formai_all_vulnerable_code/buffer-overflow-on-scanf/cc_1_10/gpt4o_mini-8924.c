//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
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
    if (store->count < MAX_MEDICINES) {
        Medicine med;
        printf("Enter medicine name: ");
        scanf(" %[^\n]", med.name);
        printf("Enter quantity: ");
        scanf("%d", &med.quantity);
        printf("Enter price: ");
        scanf("%f", &med.price);

        store->medicines[store->count++] = med;
        printf("Medicine added successfully!\n");
    } else {
        printf("Store is full, cannot add more medicines.\n");
    }
}

void displayMedicines(MedicineStore *store) {
    if (store->count == 0) {
        printf("No medicines in the store.\n");
        return;
    }
    
    printf("\nMedicines in store:\n");
    printf("%-30s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < store->count; i++) {
        printf("%-30s %-10d %-10.2f\n", store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
    }
}

void updateMedicine(MedicineStore *store) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            printf("Current Quantity: %d, Current Price: %.2f\n", store->medicines[i].quantity, store->medicines[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &store->medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &store->medicines[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine(MedicineStore *store) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            store->medicines[i] = store->medicines[store->count - 1]; // Move last medicine to current position
            store->count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void saveToFile(MedicineStore *store, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fwrite(store, sizeof(MedicineStore), 1, file);
    fclose(file);
    printf("Data saved to file successfully.\n");
}

void loadFromFile(MedicineStore *store, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fread(store, sizeof(MedicineStore), 1, file);
    fclose(file);
    printf("Data loaded from file successfully.\n");
}

void displayMenu() {
    printf("\n=== Medicine Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Save to File\n");
    printf("6. Load from File\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
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
                updateMedicine(&store);
                break;
            case 4:
                deleteMedicine(&store);
                break;
            case 5:
                saveToFile(&store, "medicines.dat");
                break;
            case 6:
                loadFromFile(&store, "medicines.dat");
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}