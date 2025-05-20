//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory is full, cannot add more medicines.\n");
        return;
    }

    Medicine newMed;
    printf("Enter Medicine Name: ");
    getchar();  // Clear buffer
    fgets(newMed.name, MAX_NAME_LENGTH, stdin);
    newMed.name[strcspn(newMed.name, "\n")] = 0; // Remove newline

    printf("Enter Medicine Price: ");
    scanf("%f", &newMed.price);

    printf("Enter Medicine Quantity: ");
    scanf("%d", &newMed.quantity);

    inventory[medicineCount++] = newMed;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\n--- Medicines in Inventory ---\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("Medicine Name: %s | Price: %.2f | Quantity: %d\n", 
                inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void updateQuantity() {
    char medName[MAX_NAME_LENGTH];
    printf("Enter Medicine Name to Update Quantity: ");
    getchar(); // Clear buffer
    fgets(medName, MAX_NAME_LENGTH, stdin);
    medName[strcspn(medName, "\n")] = 0; // Remove newline

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, medName) == 0) {
            int newQty;
            printf("Current Quantity: %d. Enter New Quantity: ", inventory[i].quantity);
            scanf("%d", &newQty);
            inventory[i].quantity = newQty;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found in inventory.\n");
}

void deleteMedicine() {
    char medName[MAX_NAME_LENGTH];
    printf("Enter Medicine Name to Delete: ");
    getchar(); // Clear buffer
    fgets(medName, MAX_NAME_LENGTH, stdin);
    medName[strcspn(medName, "\n")] = 0; // Remove newline

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].name, medName) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found in inventory.\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Medicine Quantity\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0); // Exit program
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}