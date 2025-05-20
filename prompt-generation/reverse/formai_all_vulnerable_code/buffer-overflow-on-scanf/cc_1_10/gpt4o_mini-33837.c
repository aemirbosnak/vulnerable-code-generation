//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: visionary
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
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicalStore;

void initializeStore(MedicalStore* store) {
    store->count = 0;
}

void addMedicine(MedicalStore* store) {
    if (store->count < MAX_MEDICINES) {
        Medicine newMed;
        printf("Enter medicine name: ");
        scanf("%s", newMed.name);
        printf("Enter quantity: ");
        scanf("%d", &newMed.quantity);
        printf("Enter price: ");
        scanf("%f", &newMed.price);
        
        store->medicines[store->count] = newMed;
        store->count++;
        
        printf("Medicine added successfully!\n");
    } else {
        printf("Store is full, cannot add more medicines.\n");
    }
}

void displayMedicines(const MedicalStore* store) {
    printf("\nCurrent medicines in store:\n");
    for (int i = 0; i < store->count; i++) {
        printf("%d: %s | Quantity: %d | Price: %.2f\n", 
               i + 1, 
               store->medicines[i].name, 
               store->medicines[i].quantity, 
               store->medicines[i].price);
    }
}

void sellMedicine(MedicalStore* store) {
    char medicineName[NAME_LENGTH];
    int quantity;

    printf("Enter the name of the medicine to sell: ");
    scanf("%s", medicineName);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, medicineName) == 0) {
            if (store->medicines[i].quantity >= quantity) {
                store->medicines[i].quantity -= quantity;
                printf("Sold %d of %s. Remaining quantity: %d\n", 
                       quantity, 
                       medicineName, 
                       store->medicines[i].quantity);
                return;
            } else {
                printf("Insufficient quantity in stock!\n");
                return;
            }
        }
    }
    printf("Medicine not found in store!\n");
}

void searchMedicine(const MedicalStore* store) {
    char medicineName[NAME_LENGTH];
    printf("Enter the medicine name to search: ");
    scanf("%s", medicineName);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, medicineName) == 0) {
            printf("Medicine found! Name: %s | Quantity: %d | Price: %.2f\n", 
                   store->medicines[i].name, 
                   store->medicines[i].quantity, 
                   store->medicines[i].price);
            return;
        }
    }
    printf("Medicine not found in store!\n");
}

void menu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Sell Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
}

int main() {
    MedicalStore store;
    initializeStore(&store);
    int choice;

    while (1) {
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
                sellMedicine(&store);
                break;
            case 4:
                searchMedicine(&store);
                break;
            case 5:
                printf("Exiting the system. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}