//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LEN 30
#define CODE_LEN 10

typedef struct {
    char code[CODE_LEN];
    char name[NAME_LEN];
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory is full! Cannot add more medicines.\n");
        return;
    }

    Medicine med;
    printf("Enter medicine code: ");
    scanf("%s", med.code);
    printf("Enter medicine name: ");
    scanf(" %[^\n]", med.name);
    printf("Enter medicine price: ");
    scanf("%f", &med.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &med.quantity);

    inventory[medicineCount++] = med;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in inventory!\n");
        return;
    }

    printf("\nMedicines in Inventory:\n");
    printf("%-10s %-30s %-10s %-10s\n", "Code", "Name", "Price", "Quantity");
    for (int i = 0; i < medicineCount; i++) {
        printf("%-10s %-30s %-10.2f %-10d\n", 
               inventory[i].code, 
               inventory[i].name, 
               inventory[i].price, 
               inventory[i].quantity);
    }
}

void searchMedicine() {
    char code[CODE_LEN];
    printf("Enter medicine code to search: ");
    scanf("%s", code);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            printf("Medicine Found:\n");
            printf("Code: %s\n", inventory[i].code);
            printf("Name: %s\n", inventory[i].name);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

void sellMedicine() {
    char code[CODE_LEN];
    int quantity;
    printf("Enter medicine code to sell: ");
    scanf("%s", code);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Sold %d of %s. Remaining quantity: %d\n", 
                       quantity, inventory[i].name, inventory[i].quantity);
                return;
            } else {
                printf("Not enough stock available! Available: %d\n", inventory[i].quantity);
                return;
            }
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

void updateMedicine() {
    char code[CODE_LEN];
    printf("Enter medicine code to update: ");
    scanf("%s", code);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            printf("Updating medicine: %s\n", inventory[i].name);
            printf("Enter new name: ");
            scanf(" %[^\n]", inventory[i].name);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

void deleteMedicine() {
    char code[CODE_LEN];
    printf("Enter medicine code to delete: ");
    scanf("%s", code);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

int main() {
    int choice;
    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Sell Medicine\n");
        printf("5. Update Medicine\n");
        printf("6. Delete Medicine\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: sellMedicine(); break;
            case 5: updateMedicine(); break;
            case 6: deleteMedicine(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}