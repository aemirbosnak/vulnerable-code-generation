//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCK 100
#define NAME_LENGTH 30
#define CODE_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine stock[MAX_STOCK];
    int count;
} MedicineStore;

void initializeStore(MedicineStore *store) {
    store->count = 0;
}

void addMedicine(MedicineStore *store, const char *name, const char *code, int quantity, float price) {
    if (store->count < MAX_STOCK) {
        strcpy(store->stock[store->count].name, name);
        strcpy(store->stock[store->count].code, code);
        store->stock[store->count].quantity = quantity;
        store->stock[store->count].price = price;
        store->count++;
        printf("Medicine %s added successfully.\n", name);
    } else {
        printf("Stock is full! Unable to add more medicines.\n");
    }
}

void displayMedicines(const MedicineStore *store) {
    if (store->count == 0) {
        printf("Medicines stock is empty.\n");
        return;
    }
    printf("---- Cyberpunk Medicine Stock ----\n");
    for (int i = 0; i < store->count; i++) {
        printf("Name: %s | Code: %s | Quantity: %d | Price: $%.2f\n", 
               store->stock[i].name, store->stock[i].code, 
               store->stock[i].quantity, store->stock[i].price);
    }
}

void saleMedicine(MedicineStore *store, const char *code, int quantity) {
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->stock[i].code, code) == 0) {
            if (store->stock[i].quantity >= quantity) {
                store->stock[i].quantity -= quantity;
                printf("Sold %d of %s. Remaining: %d\n", quantity, store->stock[i].name, store->stock[i].quantity);
                return;
            } else {
                printf("Not enough stock for %s. Requested: %d, Available: %d\n", store->stock[i].name, quantity, store->stock[i].quantity);
                return;
            }
        }
    }
    printf("Medicine with code %s not found.\n", code);
}

void restockMedicine(MedicineStore *store, const char *code, int quantity) {
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->stock[i].code, code) == 0) {
            store->stock[i].quantity += quantity;
            printf("Restocked %d of %s. New quantity: %d\n", quantity, store->stock[i].name, store->stock[i].quantity);
            return;
        }
    }
    printf("Medicine with code %s not found for restocking.\n", code);
}

void displayMenu() {
    printf("\n---- Cyberpunk Medical Store Management ----\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Sell Medicine\n");
    printf("4. Restock Medicine\n");
    printf("5. Exit\n");
}

int main() {
    MedicineStore store;
    initializeStore(&store);
    int choice;
    char name[NAME_LENGTH], code[CODE_LENGTH];
    int qty;
    float price;

    while (1) {
        displayMenu();

        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter medicine name: ");
                scanf("%s", name);
                printf("Enter medicine code: ");
                scanf("%s", code);
                printf("Enter quantity: ");
                scanf("%d", &qty);
                printf("Enter price: ");
                scanf("%f", &price);
                addMedicine(&store, name, code, qty, price);
                break;

            case 2:
                displayMedicines(&store);
                break;

            case 3:
                printf("Enter medicine code to sell: ");
                scanf("%s", code);
                printf("Enter quantity to sell: ");
                scanf("%d", &qty);
                saleMedicine(&store, code, qty);
                break;

            case 4:
                printf("Enter medicine code to restock: ");
                scanf("%s", code);
                printf("Enter quantity to restock: ");
                scanf("%d", &qty);
                restockMedicine(&store, code, qty);
                break;

            case 5:
                printf("Shutting down the system... \n");
                exit(0);
                break;

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}