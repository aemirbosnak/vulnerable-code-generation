//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicineStore;

void addMedicine(MedicineStore *store) {
    if (store->count >= MAX_MEDICINES) {
        printf("Oh, my dear! The shelves are full, we cannot add more medicines.\n");
        return;
    }
    Medicine m;
    printf("Enter the name of the medicine you wish to add: ");
    scanf("%s", m.name);
    printf("Enter the price of %s: ", m.name);
    scanf("%f", &m.price);
    printf("Enter the quantity of %s: ", m.name);
    scanf("%d", &m.quantity);
    
    store->medicines[store->count++] = m;
    printf("Sweetheart, %s has been added to the shelf!\n", m.name);
}

void displayMedicines(MedicineStore *store) {
    if (store->count == 0) {
        printf("Alas, the shelves are empty. No medicines to display.\n");
        return;
    }
    printf("\nMedicines Available in the Store:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < store->count; i++) {
        printf("Name: %s, Price: %.2f, Quantity: %d\n", 
                store->medicines[i].name, store->medicines[i].price, store->medicines[i].quantity);
    }
    printf("--------------------------------------------------\n");
}

void sellMedicine(MedicineStore *store) {
    if (store->count == 0) {
        printf("Oh love, we cannot sell what we do not possess.\n");
        return;
    }
    char name[50];
    printf("Which medicine do you want to sell? ");
    scanf("%s", name);

    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            int quantity;
            printf("How many units of %s do you wish to sell? ", name);
            scanf("%d", &quantity);
            if (quantity <= store->medicines[i].quantity) {
                store->medicines[i].quantity -= quantity;
                printf("Sweetheart, you have successfully sold %d units of %s.\n", quantity, name);
                return;
            } else {
                printf("Oh no, darling! We do not have enough of %s to sell.\n", name);
                return;
            }
        }
    }
    printf("Darling, I couldn't find any medicine by the name %s.\n", name);
}

void saveStore(MedicineStore *store) {
    FILE *file = fopen("store_data.txt", "w");
    if (file == NULL) {
        printf("Oh my heart, something went wrong while saving the data!\n");
        return;
    }

    fprintf(file, "%d\n", store->count);
    for (int i = 0; i < store->count; i++) {
        fprintf(file, "%s %.2f %d\n", store->medicines[i].name, store->medicines[i].price, store->medicines[i].quantity);
    }
    
    fclose(file);
    printf("Our beautiful store data has been saved to the file.\n");
}

void loadStore(MedicineStore *store) {
    FILE *file = fopen("store_data.txt", "r");
    if (file == NULL) {
        printf("Oh love, I couldn't find the stored data! Starting fresh.\n");
        return;
    }

    fscanf(file, "%d\n", &store->count);
    for (int i = 0; i < store->count; i++) {
        fscanf(file, "%s %f %d\n", store->medicines[i].name, &store->medicines[i].price, &store->medicines[i].quantity);
    }
    
    fclose(file);
    printf("Our cherished medicines have been loaded back into the store!\n");
}

int main() {
    MedicineStore store = { .count = 0 };

    loadStore(&store);

    int choice;
    do {
        printf("\nWelcome to the Heartfelt Medical Store Management System!\n");
        printf("1. Add Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. Save Store\n");
        printf("5. Exit\n");
        printf("Please choose an option: ");
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
                saveStore(&store);
                break;
            case 5:
                printf("Farewell, my dear! Until we meet again.\n");
                break;
            default:
                printf("Oh darling! Please choose a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}