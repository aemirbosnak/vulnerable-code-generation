//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
    int quantity;
} Medicine;

Medicine *inventory;
int inventorySize = 0;

void addMedicine() {
    Medicine medicine;
    printf("Enter medicine name: ");
    scanf("%s", medicine.name);
    printf("Enter medicine price: ");
    scanf("%f", &medicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicine.quantity);

    inventory = realloc(inventory, (inventorySize + 1) * sizeof(Medicine));
    inventory[inventorySize++] = medicine;
}

void displayInventory() {
    printf("\nInventory:\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("| %-30s | %-10s | %-10s |\n", "Medicine Name", "Price", "Quantity");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < inventorySize; i++) {
        printf("| %-30s | %-10.2f | %-10d |\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("--------------------------------------------------------------------------------\n");
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < inventorySize; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nMedicine found:\n");
            printf("--------------------------------------------------------------------------------\n");
            printf("| %-30s | %-10s | %-10s |\n", "Medicine Name", "Price", "Quantity");
            printf("--------------------------------------------------------------------------------\n");
            printf("| %-30s | %-10.2f | %-10d |\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
            printf("--------------------------------------------------------------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

void updateMedicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < inventorySize; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new medicine price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new medicine quantity: ");
            scanf("%d", &inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

void deleteMedicine() {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < inventorySize; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < inventorySize - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            inventorySize--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

void mainMenu() {
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("--------------------------------\n");
        printf("1. Add Medicine\n");
        printf("2. Display Inventory\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("--------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                deleteMedicine();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);
}

int main() {
    inventory = malloc(0);
    mainMenu();
    return 0;
}