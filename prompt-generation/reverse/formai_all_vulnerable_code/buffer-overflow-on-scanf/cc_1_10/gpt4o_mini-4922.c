//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicineStore;

// Function Prototypes
void initializeStore(MedicineStore *store);
void addMedicine(MedicineStore *store);
void displayMedicines(const MedicineStore *store);
void updateMedicine(MedicineStore *store);
void deleteMedicine(MedicineStore *store);
void searchMedicine(const MedicineStore *store);
void writeToFile(const MedicineStore *store);
void readFromFile(MedicineStore *store);

int main() {
    MedicineStore store;
    int choice;

    initializeStore(&store);
    readFromFile(&store);

    do {
        printf("\n--- Medicine Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Search Medicine\n");
        printf("6. Save and Exit\n");
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
                writeToFile(&store);
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeStore(MedicineStore *store) {
    store->count = 0;
}

void addMedicine(MedicineStore *store) {
    if (store->count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Storage full!\n");
        return;
    }
    
    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter manufacturer name: ");
    scanf("%s", newMedicine.manufacturer);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);

    store->medicines[store->count] = newMedicine;
    store->count++;
    printf("Medicine added successfully.\n");
}

void displayMedicines(const MedicineStore *store) {
    printf("\n--- List of Medicines ---\n");
    for (int i = 0; i < store->count; i++) {
        printf("Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n", 
               store->medicines[i].name, 
               store->medicines[i].manufacturer, 
               store->medicines[i].price, 
               store->medicines[i].quantity);
    }
}

void updateMedicine(MedicineStore *store) {
    char name[50];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            printf("Enter new manufacturer name: ");
            scanf("%s", store->medicines[i].manufacturer);
            printf("Enter new price: ");
            scanf("%f", &store->medicines[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &store->medicines[i].quantity);
            printf("Medicine updated successfully.\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine(MedicineStore *store) {
    char name[50];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            for (int j = i; j < store->count - 1; j++) {
                store->medicines[j] = store->medicines[j + 1];
            }
            store->count--;
            printf("Medicine deleted successfully.\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void searchMedicine(const MedicineStore *store) {
    char name[50];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            printf("Found Medicine -> Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n",
                   store->medicines[i].name,
                   store->medicines[i].manufacturer,
                   store->medicines[i].price,
                   store->medicines[i].quantity);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void writeToFile(const MedicineStore *store) {
    FILE *file = fopen("medicines.dat", "wb");
    fwrite(store->medicines, sizeof(Medicine), store->count, file);
    fclose(file);
    printf("Data saved successfully.\n");
}

void readFromFile(MedicineStore *store) {
    FILE *file = fopen("medicines.dat", "rb");
    if (file) {
        store->count = fread(store->medicines, sizeof(Medicine), MAX_MEDICINES, file);
        fclose(file);
        printf("Data loaded successfully.\n");
    } else {
        printf("No existing data found. Starting with an empty store.\n");
    }
}