//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct{
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

typedef struct{
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicalStore;

void initializeStore(MedicalStore *store) {
    store->count = 0;
}

void addMedicine(MedicalStore *store) {
    if(store->count >= MAX_MEDICINES) {
        printf("Store is full, cannot add more medicines.\n");
        return;
    }
    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    
    store->medicines[store->count] = newMedicine;
    store->count++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(MedicalStore *store) {
    if(store->count == 0) {
        printf("No medicines available in the store.\n");
        return;
    }
    printf("\nAvailable Medicines:\n");
    for(int i = 0; i < store->count; i++) {
        printf("%d. Name: %s, Quantity: %d, Price: %.2f\n", 
               i + 1, store->medicines[i].name, 
               store->medicines[i].quantity, 
               store->medicines[i].price);
    }
}

void updateMedicine(MedicalStore *store) {
    displayMedicines(store);
    if(store->count == 0) return;

    int choice;
    printf("Enter the number of the medicine to update: ");
    scanf("%d", &choice);
    if(choice < 1 || choice > store->count) {
        printf("Invalid choice!\n");
        return;
    }
    choice--; // Adjust for zero-indexing
    
    printf("Updating medicine: %s\n", store->medicines[choice].name);
    printf("Enter new quantity: ");
    scanf("%d", &store->medicines[choice].quantity);
    printf("Enter new price: ");
    scanf("%f", &store->medicines[choice].price);
    
    printf("Medicine updated successfully!\n");
}

void deleteMedicine(MedicalStore *store) {
    displayMedicines(store);
    if(store->count == 0) return;

    int choice;
    printf("Enter the number of the medicine to delete: ");
    scanf("%d", &choice);
    if(choice < 1 || choice > store->count) {
        printf("Invalid choice!\n");
        return;
    }
    choice--; // Adjust for zero-indexing

    for(int i = choice; i < store->count - 1; i++) {
        store->medicines[i] = store->medicines[i + 1];
    }
    store->count--;
    printf("Medicine deleted successfully!\n");
}

void searchMedicine(MedicalStore *store) {
    char name[NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    
    for(int i = 0; i < store->count; i++) {
        if(strcmp(store->medicines[i].name, name) == 0) {
            printf("Medicine found: Name: %s, Quantity: %d, Price: %.2f\n", 
                   store->medicines[i].name, 
                   store->medicines[i].quantity, 
                   store->medicines[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

int main() {
    MedicalStore store;
    initializeStore(&store);
    int choice;

    do {
        printf("\n---- Medical Store Management System ----\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Search Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                searchMedicine(&store);
                break;
            case 6:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}