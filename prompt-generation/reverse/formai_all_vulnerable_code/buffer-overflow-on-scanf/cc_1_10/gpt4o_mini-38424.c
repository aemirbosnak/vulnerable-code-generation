//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char manufacturer[MAX_NAME_LEN];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicalStore;

// Function Prototypes
void addMedicine(MedicalStore *store);
void displayMedicines(const MedicalStore *store);
void searchMedicine(const MedicalStore *store);
void deleteMedicine(MedicalStore *store);
void updateMedicine(MedicalStore *store);
void displayMenu();

int main() {
    MedicalStore store;
    store.count = 0;
    int choice;

    do {
        displayMenu();
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
                updateMedicine(&store);
                break;
            case 5:
                deleteMedicine(&store);
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Medicine\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
}

void addMedicine(MedicalStore *store) {
    if (store->count >= MAX_MEDICINES) {
        printf("Error: Medicine storage is full!\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter manufacturer name: ");
    scanf("%s", newMedicine.manufacturer);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);

    store->medicines[store->count] = newMedicine;
    store->count++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(const MedicalStore *store) {
    if (store->count == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\n=== List of Medicines ===\n");
    printf("%-20s %-20s %-10s %-10s\n", "Medicine Name", "Manufacturer", "Quantity", "Price");
    for (int i = 0; i < store->count; i++) {
        printf("%-20s %-20s %-10d %-10.2f\n", store->medicines[i].name,
               store->medicines[i].manufacturer,
               store->medicines[i].quantity,
               store->medicines[i].price);
    }
}

void searchMedicine(const MedicalStore *store) {
    char name[MAX_NAME_LEN];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s, Manufacturer: %s, Quantity: %d, Price: %.2f\n",
                   store->medicines[i].name,
                   store->medicines[i].manufacturer,
                   store->medicines[i].quantity,
                   store->medicines[i].price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void updateMedicine(MedicalStore *store) {
    char name[MAX_NAME_LEN];
    printf("Enter medicine name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            printf("Updating medicine: %s\n", store->medicines[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &store->medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &store->medicines[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found for update!\n");
}

void deleteMedicine(MedicalStore *store) {
    char name[MAX_NAME_LEN];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            // shift medicines down to fill the gap
            for (int j = i; j < store->count - 1; j++) {
                store->medicines[j] = store->medicines[j + 1];
            }
            store->count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found for deletion!\n");
}