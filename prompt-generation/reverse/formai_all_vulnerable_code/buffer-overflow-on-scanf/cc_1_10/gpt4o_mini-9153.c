//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int stock;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicalStore;

void initializeStore(MedicalStore *store) {
    store->count = 0;
}

void addMedicine(MedicalStore *store) {
    if (store->count >= MAX_MEDICINES) {
        printf("Error: Cannot add more medicines. Inventory full!\n");
        return;
    }
    
    Medicine newMedicine;

    printf("Enter Medicine Name: ");
    scanf("%s", newMedicine.name);
    printf("Enter Stock Quantity: ");
    scanf("%d", &newMedicine.stock);
    printf("Enter Price: ");
    scanf("%f", &newMedicine.price);
    
    store->medicines[store->count] = newMedicine;
    store->count++;
    
    printf("Medicine '%s' added successfully!\n", newMedicine.name);
}

void displayMedicines(const MedicalStore *store) {
    if (store->count == 0) {
        printf("No medicines in the inventory.\n");
        return;
    }
    
    printf("\n--- Medicine Inventory ---\n");
    for (int i = 0; i < store->count; i++) {
        printf("Name: %s, Stock: %d, Price: %.2f\n", store->medicines[i].name, store->medicines[i].stock, store->medicines[i].price);
    }
    printf("--------------------------\n");
}

void updateStock(MedicalStore *store) {
    char medicineName[NAME_LENGTH];
    printf("Enter Medicine Name to update stock: ");
    scanf("%s", medicineName);
    
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, medicineName) == 0) {
            int newStock;
            printf("Enter new stock quantity: ");
            scanf("%d", &newStock);
            store->medicines[i].stock = newStock;
            printf("Stock for '%s' updated to %d.\n", medicineName, newStock);
            return;
        }
    }
    
    printf("Medicine '%s' not found in the inventory.\n", medicineName);
}

void sellMedicine(MedicalStore *store) {
    char medicineName[NAME_LENGTH];
    int quantity;
    
    printf("Enter Medicine Name to sell: ");
    scanf("%s", medicineName);
    
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, medicineName) == 0) {
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity > store->medicines[i].stock) {
                printf("Error: Not enough stock for '%s'. Available: %d\n", medicineName, store->medicines[i].stock);
            } else {
                store->medicines[i].stock -= quantity;
                printf("Sold %d units of '%s'. Remaining stock: %d\n", quantity, medicineName, store->medicines[i].stock);
            }
            return;
        }
    }
    
    printf("Medicine '%s' not found in the inventory.\n", medicineName);
}

void exitProgram() {
    printf("Exiting the Medical Store Management System...\n");
}

int main() {
    MedicalStore store;
    initializeStore(&store);
    
    int choice;
    
    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Stock\n");
        printf("4. Sell Medicine\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine(&store);
                break;
            case 2:
                displayMedicines(&store);
                break;
            case 3:
                updateStock(&store);
                break;
            case 4:
                sellMedicine(&store);
                break;
            case 5:
                exitProgram();
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}