//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRUGS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    char manufacturer[NAME_LEN];
    int quantity;
    float price;
} Drug;

Drug inventory[MAX_DRUGS];
int drugCount = 0;

void addDrug() {
    if (drugCount >= MAX_DRUGS) {
        printf("Inventory is full. Cannot add more drugs.\n");
        return;
    }

    Drug newDrug;
    printf("Enter drug name: ");
    scanf(" %[^\n]", newDrug.name);
    printf("Enter manufacturer: ");
    scanf(" %[^\n]", newDrug.manufacturer);
    printf("Enter quantity: ");
    scanf("%d", &newDrug.quantity);
    printf("Enter price: ");
    scanf("%f", &newDrug.price);

    inventory[drugCount++] = newDrug;
    printf("Drug added successfully!\n");
}

void displayInventory() {
    if (drugCount == 0) {
        printf("No drugs in the inventory.\n");
        return;
    }

    printf("\nInventory List:\n");
    printf("-------------------------------------------------\n");
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Manufacturer", "Quantity", "Price");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < drugCount; i++) {
        printf("%-20s %-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].manufacturer, 
                                                inventory[i].quantity, inventory[i].price);
    }
    printf("-------------------------------------------------\n");
}

void updateDrug() {
    char name[NAME_LEN];
    printf("Enter the drug name to update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < drugCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating drug: %s\n", inventory[i].name);
            printf("Current Quantity: %d, Current Price: %.2f\n", inventory[i].quantity, inventory[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Drug updated successfully!\n");
            return;
        }
    }
    printf("Drug not found in the inventory.\n");
}

void deleteDrug() {
    char name[NAME_LEN];
    printf("Enter the drug name to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < drugCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < drugCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            drugCount--;
            printf("Drug deleted successfully!\n");
            return;
        }
    }
    printf("Drug not found in the inventory.\n");
}

void searchDrug() {
    char name[NAME_LEN];
    printf("Enter the drug name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < drugCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Drug found: %s, Manufacturer: %s, Quantity: %d, Price: %.2f\n",
                    inventory[i].name, inventory[i].manufacturer, 
                    inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Drug not found in the inventory.\n");
}

void saveInventoryToFile() {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < drugCount; i++) {
        fprintf(file, "%s,%s,%d,%.2f\n", inventory[i].name, inventory[i].manufacturer, 
                inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
    printf("Inventory saved to inventory.txt\n");
}

void loadInventoryFromFile() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("No saved inventory found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, " %[^,],%[^,],%d,%f\n", inventory[drugCount].name, inventory[drugCount].manufacturer, 
                &inventory[drugCount].quantity, &inventory[drugCount].price) != EOF) {
        drugCount++;
    }
    fclose(file);
    printf("Inventory loaded from inventory.txt\n");
}

int main() {
    int choice;

    printf("Welcome to Medical Store Management System!\n");
    loadInventoryFromFile();

    do {
        printf("\nMenu:\n");
        printf("1. Add Drug\n");
        printf("2. Display Inventory\n");
        printf("3. Update Drug\n");
        printf("4. Delete Drug\n");
        printf("5. Search Drug\n");
        printf("6. Save Inventory to File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDrug(); break;
            case 2: displayInventory(); break;
            case 3: updateDrug(); break;
            case 4: deleteDrug(); break;
            case 5: searchDrug(); break;
            case 6: saveInventoryToFile(); break;
            case 7: printf("Exiting program...\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 7);

    return 0;
}