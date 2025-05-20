//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine pharmacy[MAX_MEDICINES];
int medicineCount = 0;

// Function prototypes
void addMedicine();
void displayMedicines();
void sellMedicine();
void viewInventory();
void searchMedicine();

int main() {
    int choice;

    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. View Inventory\n");
        printf("5. Search Medicine\n");
        printf("6. Exit\n");
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
                sellMedicine();
                break;
            case 4:
                viewInventory();
                break;
            case 5:
                searchMedicine();
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void addMedicine() {
    if (medicineCount == MAX_MEDICINES) {
        printf("Medicine limit reached, cannot add more.\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter Medicine Name: ");
    scanf("%s", newMedicine.name);
    printf("Enter Quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter Price: ");
    scanf("%f", &newMedicine.price);

    pharmacy[medicineCount++] = newMedicine;
    printf("Medicine added successfully.\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\n--- List of Medicines ---\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", pharmacy[i].name, pharmacy[i].quantity, pharmacy[i].price);
    }
}

void sellMedicine() {
    char name[NAME_LENGTH];
    int quantityToSell;
    printf("Enter Medicine Name to Sell: ");
    scanf("%s", name);
    printf("Enter Quantity to Sell: ");
    scanf("%d", &quantityToSell);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(pharmacy[i].name, name) == 0) {
            if (pharmacy[i].quantity >= quantityToSell) {
                pharmacy[i].quantity -= quantityToSell;
                printf("Sold %d of %s. Remaining quantity: %d\n", quantityToSell, pharmacy[i].name, pharmacy[i].quantity);
                return;
            } else {
                printf("Not enough quantity available. Available quantity: %d\n", pharmacy[i].quantity);
                return;
            }
        }
    }

    printf("Medicine not found.\n");
}

void viewInventory() {
    int totalQuantity = 0;
    float totalValue = 0.0;

    for (int i = 0; i < medicineCount; i++) {
        totalQuantity += pharmacy[i].quantity;
        totalValue += pharmacy[i].quantity * pharmacy[i].price;
    }

    printf("Total Medicines in Inventory: %d\n", totalQuantity);
    printf("Total Inventory Value: %.2f\n", totalValue);
}

void searchMedicine() {
    char name[NAME_LENGTH];
    printf("Enter Medicine Name to Search: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(pharmacy[i].name, name) == 0) {
            printf("Medicine Found: %s, Quantity: %d, Price: %.2f\n", pharmacy[i].name, pharmacy[i].quantity, pharmacy[i].price);
            return;
        }
    }

    printf("Medicine not found.\n");
}