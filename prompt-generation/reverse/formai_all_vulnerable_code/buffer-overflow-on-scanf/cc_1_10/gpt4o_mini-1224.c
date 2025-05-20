//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRUGS 100

typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int stock;
} Drug;

Drug inventory[MAX_DRUGS];
int drug_count = 0;

void addDrug() {
    if (drug_count >= MAX_DRUGS) {
        printf("Inventory is full! Cannot add more drugs.\n");
        return;
    }
    
    Drug new_drug;
    printf("Enter Drug ID: ");
    scanf("%d", &new_drug.id);
    printf("Enter Drug Name: ");
    scanf("%s", new_drug.name);
    printf("Enter Manufacturer: ");
    scanf("%s", new_drug.manufacturer);
    printf("Enter Price: ");
    scanf("%f", &new_drug.price);
    printf("Enter Stock Quantity: ");
    scanf("%d", &new_drug.stock);
    
    inventory[drug_count++] = new_drug;
    printf("Drug added successfully!\n");
}

void viewDrugs() {
    if (drug_count == 0) {
        printf("No drugs in inventory.\n");
        return;
    }
    printf("\nDrug Inventory:\n");
    printf("ID\tName\t\tManufacturer\tPrice\tStock\n");
    for (int i = 0; i < drug_count; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].stock);
    }
}

void updateStock() {
    int id;
    printf("Enter Drug ID to update stock: ");
    scanf("%d", &id);
    
    for (int i = 0; i < drug_count; i++) {
        if (inventory[i].id == id) {
            int new_stock;
            printf("Current stock of %s: %d\n", inventory[i].name, inventory[i].stock);
            printf("Enter new stock quantity: ");
            scanf("%d", &new_stock);
            inventory[i].stock = new_stock;
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Drug ID not found!\n");
}

void deleteDrug() {
    int id;
    printf("Enter Drug ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < drug_count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < drug_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            drug_count--;
            printf("Drug deleted successfully!\n");
            return;
        }
    }
    printf("Drug ID not found!\n");
}

void searchDrug() {
    char name[50];
    printf("Enter Drug Name to search: ");
    scanf("%s", name);
    
    int found = 0;
    printf("\nSearch Results:\n");
    printf("ID\tName\t\tManufacturer\tPrice\tStock\n");
    for (int i = 0; i < drug_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("%d\t%s\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].stock);
            found = 1;
        }
    }
    if (!found) {
        printf("No drugs found with the name %s!\n", name);
    }
}

void displayMenu() {
    printf("\n---- Medical Store Management System ----\n");
    printf("1. Add Drug\n");
    printf("2. View Drugs\n");
    printf("3. Update Stock\n");
    printf("4. Delete Drug\n");
    printf("5. Search Drug\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addDrug();
                break;
            case 2:
                viewDrugs();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                deleteDrug();
                break;
            case 5:
                searchDrug();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}