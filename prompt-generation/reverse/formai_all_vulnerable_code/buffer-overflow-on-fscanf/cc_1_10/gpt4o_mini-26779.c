//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRUGS 100
#define NAME_SIZE 50

typedef struct {
    char name[NAME_SIZE];
    int quantity;
    float price;
} Drug;

Drug inventory[MAX_DRUGS];
int drugCount = 0;

void addDrug() {
    if (drugCount >= MAX_DRUGS) {
        printf("Inventory full! Cannot add more drugs.\n");
        return;
    }
    printf("Enter drug name: ");
    scanf("%s", inventory[drugCount].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[drugCount].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[drugCount].price);
    drugCount++;
    printf("Drug added successfully!\n");
}

void viewInventory() {
    if (drugCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("\n--- Drug Inventory ---\n");
    for (int i = 0; i < drugCount; i++) {
        printf("Name: %s | Quantity: %d | Price: %.2f\n", 
            inventory[i].name, 
            inventory[i].quantity, 
            inventory[i].price);
    }
}

void sellDrug() {
    char name[NAME_SIZE];
    printf("Enter drug name to sell: ");
    scanf("%s", name);
    for (int i = 0; i < drugCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            int quantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity > inventory[i].quantity) {
                printf("Not enough stock! Available quantity: %d\n", inventory[i].quantity);
            } else {
                inventory[i].quantity -= quantity;
                printf("Sold %d of %s. Total price: %.2f\n", 
                    quantity, name, 
                    quantity * inventory[i].price);
            }
            return;
        }
    }
    printf("Drug not found!\n");
}

void restockDrug() {
    char name[NAME_SIZE];
    printf("Enter drug name to restock: ");
    scanf("%s", name);
    for (int i = 0; i < drugCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            int quantity;
            printf("Enter quantity to restock: ");
            scanf("%d", &quantity);
            inventory[i].quantity += quantity;
            printf("Restocked %d of %s. New quantity: %d\n", 
                quantity, name, 
                inventory[i].quantity);
            return;
        }
    }
    printf("Drug not found!\n");
}

void saveInventory() {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Failed to save inventory!\n");
        return;
    }
    for (int i = 0; i < drugCount; i++) {
        fprintf(file, "%s %d %.2f\n", 
            inventory[i].name, 
            inventory[i].quantity, 
            inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved successfully!\n");
}

void loadInventory() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No inventory file found!\n");
        return;
    }
    while (!feof(file) && drugCount < MAX_DRUGS) {
        fscanf(file, "%s %d %f", 
            inventory[drugCount].name, 
            &inventory[drugCount].quantity, 
            &inventory[drugCount].price);
        drugCount++;
    }
    fclose(file);
    printf("Inventory loaded successfully! %d drugs loaded.\n", drugCount);
}

void menu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Drug\n");
    printf("2. View Inventory\n");
    printf("3. Sell Drug\n");
    printf("4. Restock Drug\n");
    printf("5. Save Inventory\n");
    printf("6. Load Inventory\n");
    printf("7. Exit\n");
}

int main() {
    int choice;
    loadInventory();
    do {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addDrug(); break;
            case 2: viewInventory(); break;
            case 3: sellDrug(); break;
            case 4: restockDrug(); break;
            case 5: saveInventory(); break;
            case 6: loadInventory(); break;
            case 7: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid option! Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}