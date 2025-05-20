//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 50

typedef struct {
    char name[20];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
    float totalRevenue;
} Inventory;

void printMenu() {
    printf("\n");
    printf(" 1. Add Medicine\n");
    printf(" 2. Remove Medicine\n");
    printf(" 3. Update Medicine Price\n");
    printf(" 4. Sell Medicine\n");
    printf(" 5. View Inventory\n");
    printf(" 6. View Total Revenue\n");
    printf(" 7. Exit\n");
}

void addMedicine(Inventory *inventory) {
    if (inventory->count >= MAX_MEDICINES) {
        printf("Medicines capacity reached. No more medicines can be added.\n");
        return;
    }
    Medicine medicine;
    printf("Enter medicine name: ");
    scanf("%s", &medicine.name);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicine.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &medicine.price);
    inventory->medicines[inventory->count++] = medicine;
    printf("%s added to the inventory.\n", medicine.name);
}

void removeMedicine(Inventory *inventory) {
    printf("Enter medicine name: ");
    char medicineName[20];
    scanf("%s", &medicineName);
    int i;
    for (i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->medicines[i].name, medicineName) == 0) {
            printf("%s removed from the inventory.\n", inventory->medicines[i].name);
            inventory->count--;
            inventory->medicines[i] = inventory->medicines[inventory->count];
            return;
        }
    }
    printf("Medicine not found in the inventory.\n");
}

void updateMedicinePrice(Inventory *inventory) {
    printf("Enter medicine name: ");
    char medicineName[20];
    scanf("%s", &medicineName);
    int i;
    for (i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->medicines[i].name, medicineName) == 0) {
            printf("Enter new medicine price: ");
            float newPrice;
            scanf("%f", &newPrice);
            inventory->medicines[i].price = newPrice;
            printf("Price of %s updated in the inventory.\n", inventory->medicines[i].name);
            return;
        }
    }
    printf("Medicine not found in the inventory.\n");
}

void sellMedicine(Inventory *inventory) {
    printf("Enter medicine name: ");
    char medicineName[20];
    scanf("%s", &medicineName);
    int i;
    for (i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->medicines[i].name, medicineName) == 0) {
            printf("Enter quantity to sell: ");
            int quantityToSell;
            scanf("%d", &quantityToSell);
            if (quantityToSell <= inventory->medicines[i].quantity) {
                inventory->medicines[i].quantity -= quantityToSell;
                inventory->totalRevenue += quantityToSell * inventory->medicines[i].price;
                printf("%d units of %s sold. Total revenue: %.2f\n", quantityToSell, inventory->medicines[i].name, inventory->totalRevenue);
            }
            else {
                printf("Insufficient quantity available in the inventory.\n");
            }
            return;
        }
    }
    printf("Medicine not found in the inventory.\n");
}

void viewInventory(Inventory *inventory) {
    printf("+------------+-----+-------+\n");
    printf("| MEDICINE   | QTY | PRICE |\n");
    printf("+------------+-----+-------+\n");
    int i;
    for (i = 0; i < inventory->count; i++) {
        printf("| %-10s | %-3d | $%-5.2f |\n", inventory->medicines[i].name, inventory->medicines[i].quantity, inventory->medicines[i].price);
    }
    printf("+------------+-----+-------+\n");
}

int main() {
    Inventory inventory;
    inventory.count = 0;
    inventory.totalRevenue = 0;
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(&inventory);
                break;
            case 2:
                removeMedicine(&inventory);
                break;
            case 3:
                updateMedicinePrice(&inventory);
                break;
            case 4:
                sellMedicine(&inventory);
                break;
            case 5:
                viewInventory(&inventory);
                break;
            case 6:
                printf("Total revenue: $%.2f\n", inventory.totalRevenue);
                break;
            case 7:
                printf("Thank you for using the Medical Store Management System!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    }
    return 0;
}