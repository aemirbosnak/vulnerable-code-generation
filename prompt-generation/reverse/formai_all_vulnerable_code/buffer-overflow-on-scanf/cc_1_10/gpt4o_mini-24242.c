//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Medicine
typedef struct {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Structure for the Medical Store
typedef struct {
    Medicine *medicines;
    int count;
} MedicalStore;

// Function prototypes
void addMedicine(MedicalStore *store);
void displayMedicines(const MedicalStore *store);
void updateMedicine(MedicalStore *store);
void deleteMedicine(MedicalStore *store);
void freeStore(MedicalStore *store);

int main() {
    MedicalStore store;
    store.count = 0;
    store.medicines = NULL;
    int choice;

    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
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
                freeStore(&store);
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void addMedicine(MedicalStore *store) {
    store->medicines = realloc(store->medicines, sizeof(Medicine) * (store->count + 1));
    if (store->medicines == NULL) {
        perror("Error reallocating memory");
        exit(EXIT_FAILURE);
    }

    Medicine *newMedicine = &store->medicines[store->count];

    printf("Enter medicine name: ");
    scanf(" %[^\n]", newMedicine->name);
    printf("Enter medicine price: ");
    scanf("%f", &newMedicine->price);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine->quantity);

    store->count++;
    printf("Medicine \"%s\" added successfully.\n", newMedicine->name);
}

void displayMedicines(const MedicalStore *store) {
    if (store->count == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\n--- Medicines List ---\n");
    for (int i = 0; i < store->count; i++) {
        printf("Medicine #%d\n", i + 1);
        printf("Name: %s\n", store->medicines[i].name);
        printf("Price: %.2f\n", store->medicines[i].price);
        printf("Quantity: %d\n", store->medicines[i].quantity);
        printf("-----------------------\n");
    }
}

void updateMedicine(MedicalStore *store) {
    if (store->count == 0) {
        printf("No medicines available to update.\n");
        return;
    }

    int index;
    printf("Enter the medicine number to update (1 to %d): ", store->count);
    scanf("%d", &index);

    if (index < 1 || index > store->count) {
        printf("Invalid medicine number.\n");
        return;
    }

    Medicine *medToUpdate = &store->medicines[index - 1];
    printf("Updating Medicine: %s\n", medToUpdate->name);

    printf("Enter new price: ");
    scanf("%f", &medToUpdate->price);
    printf("Enter new quantity: ");
    scanf("%d", &medToUpdate->quantity);

    printf("Medicine \"%s\" updated successfully.\n", medToUpdate->name);
}

void deleteMedicine(MedicalStore *store) {
    if (store->count == 0) {
        printf("No medicines available to delete.\n");
        return;
    }

    int index;
    printf("Enter the medicine number to delete (1 to %d): ", store->count);
    scanf("%d", &index);

    if (index < 1 || index > store->count) {
        printf("Invalid medicine number.\n");
        return;
    }

    Medicine *medToDelete = &store->medicines[index - 1];
    printf("Deleting Medicine: %s\n", medToDelete->name);

    for (int i = index - 1; i < store->count - 1; i++) {
        store->medicines[i] = store->medicines[i + 1];
    }
    
    store->count--;
    store->medicines = realloc(store->medicines, sizeof(Medicine) * store->count);

    printf("Medicine \"%s\" deleted successfully.\n", medToDelete->name);
}

void freeStore(MedicalStore *store) {
    if (store->medicines != NULL) {
        free(store->medicines);
    }
}