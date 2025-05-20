//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char name[50];
    char type[30];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[SIZE];
    int count;
} MedicalStore;

void initializeStore(MedicalStore *store) {
    store->count = 0;
}

void addMedicine(MedicalStore *store) {
    if (store->count >= SIZE) {
        printf("No more space to add medicines.\n");
        return;
    }
    Medicine med;
    printf("Enter medicine name: ");
    scanf("%s", med.name);
    printf("Enter medicine type: ");
    scanf("%s", med.type);
    printf("Enter quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter price: ");
    scanf("%f", &med.price);
    store->medicines[store->count++] = med;
    printf("Medicine added successfully!\n");
}

void displayMedicines(const MedicalStore *store) {
    if (store->count == 0) {
        printf("No medicines in the store.\n");
        return;
    }
    printf("\nList of Medicines:\n");
    for (int i = 0; i < store->count; i++) {
        printf("%d. Name: %s, Type: %s, Quantity: %d, Price: %.2f\n",
               i + 1, store->medicines[i].name,
               store->medicines[i].type,
               store->medicines[i].quantity,
               store->medicines[i].price);
    }
}

void updateMedicine(MedicalStore *store) {
    int index;
    displayMedicines(store);
    printf("Enter the index of the medicine to update: ");
    scanf("%d", &index);

    if (index <= 0 || index > store->count) {
        printf("Invalid index!\n");
        return;
    }

    Medicine *med = &store->medicines[index - 1];
    printf("Updating %s...\n", med->name);
    printf("Enter new quantity (-1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        med->quantity = newQuantity;
    }
    printf("Enter new price (-1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice != -1.0) {
        med->price = newPrice;
    }
    printf("Medicine updated successfully!\n");
}

void deleteMedicine(MedicalStore *store) {
    int index;
    displayMedicines(store);
    printf("Enter the index of the medicine to delete: ");
    scanf("%d", &index);

    if (index <= 0 || index > store->count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < store->count - 1; i++) {
        store->medicines[i] = store->medicines[i + 1];
    }
    store->count--;
    printf("Medicine deleted successfully!\n");
}

void searchMedicine(const MedicalStore *store) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            printf("Medicine found - Name: %s, Type: %s, Quantity: %d, Price: %.2f\n",
                   store->medicines[i].name,
                   store->medicines[i].type,
                   store->medicines[i].quantity,
                   store->medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found.\n");
    }
}

void showMenu() {
    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
}

int main() {
    MedicalStore store;
    initializeStore(&store);
    int choice;

    do {
        showMenu();
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
                updateMedicine(&store);
                break;
            case 4:
                deleteMedicine(&store);
                break;
            case 5:
                searchMedicine(&store);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}