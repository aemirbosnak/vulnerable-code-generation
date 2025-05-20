//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    char category[50];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX];
int count = 0;

void loadInventory() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        return; // No file exists, start fresh
    }
    while (fscanf(file, "%49s %49s %d %f", inventory[count].name, inventory[count].category,
                 &inventory[count].quantity, &inventory[count].price) != EOF) {
        count++;
    }
    fclose(file);
}

void saveInventory() {
    FILE *file = fopen("inventory.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %d %.2f\n", inventory[i].name, inventory[i].category,
                inventory[i].quantity, inventory[i].price);
    }
    fclose(file);
}

void addMedicine() {
    if (count >= MAX) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }

    Medicine med;
    printf("Enter medicine name: ");
    scanf("%49s", med.name);
    printf("Enter medicine category: ");
    scanf("%49s", med.category);
    printf("Enter medicine quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &med.price);

    inventory[count] = med;
    count++;
    printf("Medicine added successfully!\n");
    saveInventory();
}

void updateMedicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%49s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating details for %s:\n", name);
            printf("New quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("New price: ");
            scanf("%f", &inventory[i].price);
            printf("Medicine updated successfully!\n");
            saveInventory();
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%49s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];  // Shift elements to left
            }
            count--;
            printf("Medicine deleted successfully!\n");
            saveInventory();
            return;
        }
    }
    printf("Medicine not found!\n");
}

void viewInventory() {
    printf("\n----- Inventory List -----\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Category: %s, Quantity: %d, Price: %.2f\n", 
                inventory[i].name, inventory[i].category,
                inventory[i].quantity, inventory[i].price);
    }
    printf("-------------------------\n");
}

int main() {
    loadInventory();
    int choice;

    while (1) {
        printf("\n------- Medical Store Management -------\n");
        printf("1. Add Medicine\n");
        printf("2. Update Medicine\n");
        printf("3. Delete Medicine\n");
        printf("4. View Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                updateMedicine();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                viewInventory();
                break;
            case 5:
                printf("Exiting... Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}