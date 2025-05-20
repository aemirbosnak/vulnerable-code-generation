//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine *inventory;
int inventorySize = 0;
int inventoryCapacity = 10;

void displayInventory() {
    printf("Inventory:\n");
    for (int i = 0; i < inventorySize; i++) {
        printf("%s\t%d\t%f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void addMedicine() {
    if (inventorySize == inventoryCapacity) {
        inventoryCapacity *= 2;
        inventory = realloc(inventory, inventoryCapacity * sizeof(Medicine));
    }

    printf("Enter medicine name: ");
    scanf(" %s", inventory[inventorySize].name);

    printf("Enter medicine quantity: ");
    scanf(" %d", &inventory[inventorySize].quantity);

    printf("Enter medicine price: ");
    scanf(" %f", &inventory[inventorySize].price);

    inventorySize++;
}

void removeMedicine() {
    char name[50];

    printf("Enter medicine name to remove: ");
    scanf(" %s", name);

    int index = -1;
    for (int i = 0; i < inventorySize; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n");
    } else {
        for (int i = index; i < inventorySize - 1; i++) {
            inventory[i] = inventory[i + 1];
        }

        inventorySize--;
    }
}

void updateMedicine() {
    char name[50];

    printf("Enter medicine name to update: ");
    scanf(" %s", name);

    int index = -1;
    for (int i = 0; i < inventorySize; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n");
    } else {
        printf("Enter new medicine quantity: ");
        scanf(" %d", &inventory[index].quantity);

        printf("Enter new medicine price: ");
        scanf(" %f", &inventory[index].price);
    }
}

int main() {
    inventory = malloc(inventoryCapacity * sizeof(Medicine));

    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Display Inventory\n");
        printf("2. Add Medicine\n");
        printf("3. Remove Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                displayInventory();
                break;
            case 2:
                addMedicine();
                break;
            case 3:
                removeMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    free(inventory);

    return 0;
}