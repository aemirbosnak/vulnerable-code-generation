//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRUGS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Drug;

typedef struct {
    Drug drugs[MAX_DRUGS];
    int count;
} DrugInventory;

void addDrug(DrugInventory *inventory);
void displayDrugs(const DrugInventory *inventory);
void purchaseDrug(DrugInventory *inventory);
void restockDrug(DrugInventory *inventory);
void saveToFile(const DrugInventory *inventory);
void loadFromFile(DrugInventory *inventory);

int main() {
    DrugInventory inventory = { .count = 0 };
    int choice;
    loadFromFile(&inventory);

    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Drug\n");
        printf("2. Display Drugs\n");
        printf("3. Purchase Drug\n");
        printf("4. Restock Drug\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addDrug(&inventory);
                break;
            case 2: 
                displayDrugs(&inventory);
                break;
            case 3: 
                purchaseDrug(&inventory);
                break;
            case 4: 
                restockDrug(&inventory);
                break;
            case 5: 
                saveToFile(&inventory);
                printf("Exiting the system...\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addDrug(DrugInventory *inventory) {
    if (inventory->count >= MAX_DRUGS) {
        printf("Inventory full! Cannot add more drugs.\n");
        return;
    }
    Drug newDrug;
    printf("Enter drug name: ");
    scanf("%s", newDrug.name);
    printf("Enter drug price: ");
    scanf("%f", &newDrug.price);
    printf("Enter drug quantity: ");
    scanf("%d", &newDrug.quantity);
    inventory->drugs[inventory->count++] = newDrug;
    printf("Drug added successfully!\n");
}

void displayDrugs(const DrugInventory *inventory) {
    if (inventory->count == 0) {
        printf("No drugs available in stock.\n");
        return;
    }
    printf("\nAvailable Drugs:\n");
    printf("%-20s %-10s %-10s\n", "Drug Name", "Price", "Quantity");
    for (int i = 0; i < inventory->count; i++) {
        printf("%-20s %-10.2f %-10d\n", inventory->drugs[i].name, inventory->drugs[i].price, inventory->drugs[i].quantity);
    }
}

void purchaseDrug(DrugInventory *inventory) {
    char name[MAX_NAME_LENGTH];
    int quantity;
    printf("Enter drug name to purchase: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->drugs[i].name, name) == 0) {
            if (inventory->drugs[i].quantity >= quantity) {
                inventory->drugs[i].quantity -= quantity;
                printf("Purchased %d units of %s. Total Cost: $%.2f\n", quantity, name, inventory->drugs[i].price * quantity);
                return;
            } else {
                printf("Insufficient quantity! Available: %d\n", inventory->drugs[i].quantity);
                return;
            }
        }
    }
    printf("Drug not found!\n");
}

void restockDrug(DrugInventory *inventory) {
    char name[MAX_NAME_LENGTH];
    int quantity;
    printf("Enter drug name to restock: ");
    scanf("%s", name);
    printf("Enter quantity to restock: ");
    scanf("%d", &quantity);

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->drugs[i].name, name) == 0) {
            inventory->drugs[i].quantity += quantity;
            printf("Restocked %d units of %s. New Quantity: %d\n", quantity, name, inventory->drugs[i].quantity);
            return;
        }
    }
    printf("Drug not found! Please add it first.\n");
}

void saveToFile(const DrugInventory *inventory) {
    FILE *file = fopen("inventory.dat", "wb");
    if (file) {
        fwrite(inventory, sizeof(DrugInventory), 1, file);
        fclose(file);
    } else {
        printf("Failed to save inventory.\n");
    }
}

void loadFromFile(DrugInventory *inventory) {
    FILE *file = fopen("inventory.dat", "rb");
    if (file) {
        fread(inventory, sizeof(DrugInventory), 1, file);
        fclose(file);
    }
}